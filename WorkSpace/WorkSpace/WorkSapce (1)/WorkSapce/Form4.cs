using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.ListView;

namespace WorkSapce
{
    public partial class Form4 : Form
    {
        internal string passedroom;
        internal string nroom;
        internal double passedvalue;

        public Form4()
        {
            InitializeComponent();
        }
        
        

        private void button1_Click(object sender, EventArgs e)
        {

            DateTime startTime = dateTimePicker1.Value;
            DateTime endTime = dateTimePicker2.Value;

            if (endTime <= startTime)
            {
                MessageBox.Show("End time must be after start time.");
                return;
            }

            double hours = (endTime - startTime).TotalHours;
            double totalCost = hours * passedvalue;

            Form5 form5 = new Form5();
            form5.total = totalCost;
            form5.start = startTime;
            form5.end = endTime;
            form5.name = nroom;
            form5.Show();
            this.Hide();

           
        }

        
        private void dateTimePicker2_ValueChanged(object sender, EventArgs e)
        {

        }
    }
}
