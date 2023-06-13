using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WorkspaceManagementSystem;
using System.Data.OleDb;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;
using System.Data.SqlClient;

namespace WorkSapce
{
    public partial class Form1 : Form
    {
        private const string connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=E:\\WorkSpace\\WorkSapce (1)\\WorkSapce\\Database_Work_space.accdb";
        public Form1()
        {
            InitializeComponent();
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {
         
        }

        private UserManager userManager = new UserManager();
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {

                string email = textBox1.Text.Trim();
                string password = textBox2.Text.Trim();

                if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
                {
                    MessageBox.Show( "Please enter both email and password.");
                    return;
                }
                try
                {
                    using (OleDbConnection connection = new OleDbConnection(connectionString))
                    {
                        connection.Open();
                        string query = "SELECT COUNT(*) FROM Customer WHERE Email = @Email AND Password = @Password";
                        OleDbCommand command = new OleDbCommand(query, connection);
                        command.Parameters.AddWithValue("@Username", email);
                        command.Parameters.AddWithValue("@Password", password);

                        int result = (int)command.ExecuteScalar();

                        if (result > 0)
                        {
                            Form3 form3 = new Form3();
                            form3.Show();
                            this.Hide();
                            MessageBox.Show("Login successful!");
                        }
                        else
                        {
                            MessageBox.Show("Invalid username or password.");
                        }
                    }
                }
                catch (OleDbException ex)
                {
                    MessageBox.Show("An error occurred while connecting to the database: " + ex.Message);
                }
                catch (Exception ex)
                {
                    MessageBox.Show("An error occurred: " + ex.Message);
                }


                // You can add more input validation here, e.g., checking for a valid email format.

                var loggedInUser = userManager.AuthenticateUser(email, password);

            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }

           
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
            this.Hide();
            
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
namespace WorkspaceManagementSystem
{
    class Program
    {
        static void main(string[] args)
        {
            try
            {
                // Step 1: User authentication and registration
                var userManager = new UserManager();
                var user = userManager.RegisterUser("John Doe", "ahmed", "123");
                var loggedInUser = userManager.AuthenticateUser("ahmed", "123");

                if (loggedInUser != null)
                {
                    Console.WriteLine($"Welcome, {loggedInUser.Name}!");
                }
                else
                {
                    Console.WriteLine("Invalid email or password.");
                    return;
                }

                // Step 2: Workspace reservation
                var workspaceManager = new WorkspaceManager();
                var workspace = new Workspace { Id = 1, Name = "Workspace A", Capacity = 4 };
                var reservation = workspaceManager.ReserveWorkspace(loggedInUser, workspace, DateTime.Now, DateTime.Now.AddHours(2));

                if (reservation != null)
                {
                    Console.WriteLine($"Workspace {workspace.Name} reserved successfully.");
                }
                else
                {
                    Console.WriteLine("Failed to reserve workspace.");
                }

                // Step 3: Resource management
                var resourceManager = new ResourceManager();
                var meetingRoom = new Resource { Id = 1, Name = "Meeting Room 1", ResourceType = ResourceType.MeetingRoom };
                var resourceReservation = resourceManager.ReserveResource(loggedInUser, meetingRoom, DateTime.Now, DateTime.Now.AddHours(1));

                if (resourceReservation != null)
                {
                    Console.WriteLine($"Resource {meetingRoom.Name} reserved successfully.");
                }
                else
                {
                    Console.WriteLine("Failed to reserve resource.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An error occurred: {ex.Message}");
            }
        }
    }


    // User-related classes and methods
    public class User
    {
        //internal string name;

        public int Id { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }

        public User()
        {
        }

        public User(int id, string name, string email, string password)
        {
            Id = id;
            Name = name;
            Email = email;
            Password = password;
        }

        public User(string name, string email, string password)
        {
            Name = name;
            Email = email;
            Password = password;
        }

    }

    public class UserManager
    {
        private string connectionString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=E:\\WorkSpace\\WorkSapce (1)\\WorkSapce\\Database_Work_space.accdb;Persist Security Info=False;";

        public User RegisterUser(string name, string email, string password)
        {
            var user = new User { Id = GetNextUserId(), Name = name, Email = email, Password = password };
            InsertUserIntoDatabase(user);
            return user;
        }

        public User GetUserByEmail(string email)
        {
            using (OleDbConnection connection = new OleDbConnection(connectionString))
            {
                connection.Open();

                string query = "SELECT * FROM Customer WHERE Email = @Email";
                OleDbCommand command = new OleDbCommand(query, connection);
                command.Parameters.AddWithValue("@Email", email);

                OleDbDataReader reader = command.ExecuteReader();

                if (reader.Read())
                {
                    int id = (int)reader["Id"];
                    string name = (string)reader["Name"];
                    string password = (string)reader["Password"];

                    return new User( name, email, password);
                }
                else
                {
                    return null;
                }
            }
        }

        private int GetNextUserId()
        {
            int nextId = 1;
            using (var connection = new OleDbConnection(connectionString))
            {
                connection.Open();
                var command = new OleDbCommand("SELECT MAX(Customer_ID) FROM Customer", connection);
                var result = command.ExecuteScalar();
                if (result != null && result != DBNull.Value)
                {
                    nextId = Convert.ToInt32(result) + 1;
                }
            }
            return nextId;
        }

        private void InsertUserIntoDatabase(User user)
        {
            using (var connection = new OleDbConnection(connectionString))
            {
                connection.Open();
                var command = new OleDbCommand("INSERT INTO Customer ([Customer_ID],[UserName], [Email], [Password]) VALUES (?, ?, ?, ?)", connection);
                command.Parameters.AddWithValue("Customer_ID", user.Id);
                command.Parameters.AddWithValue("UserName", user.Name);
                command.Parameters.AddWithValue("Email", user.Email);
                command.Parameters.AddWithValue("Password", user.Password);
                command.ExecuteNonQuery();
            }
        }

        public User AuthenticateUser(string email, string password)
        {
            User user = null;
            using (var connection = new OleDbConnection(connectionString))
            {
                connection.Open();
                var command = new OleDbCommand("SELECT * FROM Customer WHERE Email = ? AND Password = ?", connection);
                command.Parameters.AddWithValue("Email", email);
                command.Parameters.AddWithValue("Password", password);
                var reader = command.ExecuteReader();
                if (reader.Read())
                {
                    user = new User
                    {
                        Id = Convert.ToInt32(reader["Customer_ID"]),
                        Name = Convert.ToString(reader["UserName"]),
                        Email = Convert.ToString(reader["Email"]),
                        Password = Convert.ToString(reader["Password"])
                    };
                }
            }
            return user;
        }
    }

    // Workspace-related classes and methods
    public class Workspace
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Capacity { get; set; }
    }

    public class WorkspaceReservation
    {
        public int Id { get; set; }
        public User User { get; set; }
        public Workspace Workspace { get; set; }
        public DateTime StartTime { get; set; }
        public DateTime EndTime { get; set; }
    }

    public class WorkspaceManager
    {
        private List<WorkspaceReservation> reservations = new List<WorkspaceReservation>();

        public WorkspaceReservation ReserveWorkspace(User user, Workspace workspace, DateTime startTime, DateTime endTime)
        {
            var reservation = new WorkspaceReservation { Id = reservations.Count + 1, User = user, Workspace = workspace, StartTime = startTime, EndTime = endTime };
            reservations.Add(reservation);
            return reservation;
        }
    }

    // Resource-related classes and methods
    public class Resource
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public ResourceType ResourceType { get; set; }
    }

    public enum ResourceType
    {
        MeetingRoom,
        Equipment,
        ParkingSpace
    }

    public class ResourceReservation
    {
        public int Id { get; set; }
        public User User { get; set; }
        public Resource Resource { get; set; }
        public DateTime StartTime { get; set; }
        public DateTime EndTime { get; set; }
    }

    public class ResourceManager
    {
        private List<ResourceReservation> reservations = new List<ResourceReservation>();

        public ResourceReservation ReserveResource(User user, Resource resource, DateTime startTime, DateTime endTime)
        {
            var reservation = new ResourceReservation { Id = reservations.Count + 1, User = user, Resource = resource, StartTime = startTime, EndTime = endTime };
            reservations.Add(reservation);
            return reservation;
        }
    }

}
