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
    public partial class Form5 : Form
    {
       
        internal DateTime start;
        internal DateTime end;
        internal string name;
        internal double total;
        public Form5()
        {
            InitializeComponent();
        }

        

        private void button1_Click(object sender, EventArgs e)
        {

            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox2.Text = start.ToString();
            textBox3.Text = end.ToString();
            textBox4.Text = name;
            textBox5.Text = total.ToString("c");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form3 form3 = new Form3();
            form3.Show();
            this.Hide();
        }
    }
}
