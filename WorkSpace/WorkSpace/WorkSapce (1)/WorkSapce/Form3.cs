using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WorkSapce
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string roomname="";
            double pricePerHour = 0;

            if (radioButton1.Checked)
            {
                roomname = "Shared area";
                pricePerHour = 10; // Set the price per hour for radioButton1
            }
            else if (radioButton2.Checked)
            {
                roomname = "Room 1";
                pricePerHour = 30; // Set the price per hour for radioButton2
            }
            else if (radioButton3.Checked)
            {
                roomname = "Room 2";
                pricePerHour = 50; // Set the price per hour for radioButton3
            }
            else if (radioButton4.Checked)
            {
                roomname = "Room 3";
                pricePerHour = 80; // Set the price per hour for radioButton4
            }

            // Navigate to the SecondForm
            
            Form4 form4 = new Form4();
            form4.passedvalue = pricePerHour;
            form4.passedroom=roomname;
            form4.nroom = roomname;
            form4.Show();
            this.Hide();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
