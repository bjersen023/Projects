using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WorkspaceManagementSystem;


namespace WorkSapce
{
    public partial class Form1 : Form
    {
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
            string email = textBox1.Text.Trim();
            string password = textBox2.Text.Trim();

            if (string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
            {
                label1.Text = "Please enter both email and password.";
                return;
            }

            // You can add more input validation here, e.g., checking for a valid email format.

            var loggedInUser = userManager.AuthenticateUser(email, password);

            if (loggedInUser != null)
            {
                label1.Text = $"Welcome, {loggedInUser.Name}!";
            }
            else
            {
                label1.Text = "Invalid email or password.";
            }
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }
    }
}
namespace WorkspaceManagementSystem
{
    class Program
    {
        static void main(string[] args)
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
    }

    // User-related classes and methods
    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }
    }

    public class UserManager
    {
        private List<User> users = new List<User>();

        public User RegisterUser(string name, string email, string password)
        {
            var user = new User { Id = users.Count + 1, Name = name, Email = email, Password = password };
            users.Add(user);
            return user;
        }

        public User AuthenticateUser(string email, string password)
        {
            return users.Find(user => user.Email == email && user.Password == password);
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