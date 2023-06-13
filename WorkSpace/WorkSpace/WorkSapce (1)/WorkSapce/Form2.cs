using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Linq;
using WorkspaceManagementSystem;

namespace WorkSapce
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string name = textBox1.Text.Trim();
                string email = textBox2.Text.Trim();
                string password = textBox3.Text.Trim();

                if (string.IsNullOrEmpty(name) || string.IsNullOrEmpty(email) || string.IsNullOrEmpty(password))
                {
                    MessageBox.Show("Please enter your name, email, and password.");
                    return;
                }
                try
                {

                    MailAddress mailAddress = new MailAddress(email);
                }
                catch (FormatException ex)
                {
                    MessageBox.Show("Invalid email format: ");
                    return;
                }

                var userManager = new UserManager();

                // Check if the email already exists in the database
                if (userManager.GetUserByEmail(email) != null)
                {
                    MessageBox.Show("This email is already registered. Please use a different email.");
                    return;
                }

                var newUser = userManager.RegisterUser(name, email, password);

                if (newUser != null)
                {
                    MessageBox.Show("Registration successful!");
                }
                else
                {
                    MessageBox.Show("Registration failed. Please try again.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"An error occurred: {ex.Message}");
            }

            Form1 form1 = new Form1();
            form1.Show();
            this.Hide();
        }


    }
}
