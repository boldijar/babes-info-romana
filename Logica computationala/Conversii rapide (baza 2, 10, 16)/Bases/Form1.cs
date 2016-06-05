using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Bases
{
    public partial class Form1 : Form
    {

        public int baseA;
        public int baseB;
        public void dimensions()
        {
            groupBox1.Dock = DockStyle.Fill;
            groupBox2.Dock = DockStyle.Fill;

        }
        public void hide()
        {
            groupBox1.Visible = false;
            groupBox2.Visible = false;
        }
        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            hide();
            groupBox1.Visible = true;
            dimensions();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            dimensions();
            hide();
            groupBox2.Visible = true;
            label2.Text = "Enter the number in base 10: ";
            label3.Text = "The number in base 2 is:";
            baseA = 10;
            baseB = 2;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            dimensions();
            hide();
            groupBox2.Visible = true;
            label2.Text = "Enter the number in base 10: ";
            label3.Text = "The number in base 16 is:";
            baseA = 10;
            baseB = 16;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            dimensions();
            hide();
            groupBox2.Visible = true;
            label2.Text = "Enter the number in base 2: ";
            label3.Text = "The number in base 16 is:";
            baseA = 2;
            baseB = 16;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            dimensions();
            hide();
            groupBox2.Visible = true;
            label2.Text = "Enter the number in base 2: ";
            label3.Text = "The number in base 10 is:";
            baseA = 2;
            baseB = 10;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            dimensions();
            hide();
            groupBox2.Visible = true;
            label2.Text = "Enter the number in base 16: ";
            label3.Text = "The number in base 2 is:";
            baseA = 16;
            baseB = 2;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            dimensions();
            hide();
            groupBox2.Visible = true;
            label2.Text = "Enter the number in base 16: ";
            label3.Text = "The number in base 10 is:";
            baseA = 16;
            baseB = 10;
        }

        public string inverse_string(string n)
        {
            string a = "";
            for (int k = n.Length - 1; k >= 0; k--)
                a = a + n[k];
            return a;
        }
        public string inverse_string2(string n)
        {
            string a = "";
            for (int k = n.Length - 1; k >= 0; k--)
                a = a + n[k];
            return a;
        }
        public string h(long nr)
        {
            if (nr <= 9)
                return nr.ToString();
            else if (nr == 10)
                return "A";
            else if (nr == 11)
                return "B";
            else if (nr == 12)
                return "C";
            else if (nr == 13)
                return "D";
            else if (nr == 14)
                return "E";
            else 
                return "F";
        }
        public string b_to_h(long a)
        {
            if (a == 0) return "0";
            else if (a == 1) return "1";
            else if (a == 10) return "2";
            else if (a == 11) return "3";
            else if (a == 100) return "4";
            else if (a == 101) return "5";
            else if (a == 110) return "6";
            else if (a == 111) return "7";
            else if (a == 1000) return "8";
            else if (a == 1001) return "9";
            else if (a == 1010) return "A";
            else if (a == 1011) return "B";
            else if (a == 1100) return "C";
            else if (a == 1101) return "D";
            else if (a == 1110) return "E";
            else return "F";
  
        }
        public string h_to_b(string a)
        {
            if (a == "0") return "0000";
            else if (a == "1") return "0001";
            else if (a == "2") return "0010";
            else if (a == "3") return "0011";
            else if (a == "4") return "0100";
            else if (a == "5") return "0101";
            else if (a == "6") return "0110";
            else if (a == "7") return "0111";
            else if (a == "8") return "1000";
            else if (a == "9") return "1001";
            else if (a == "A") return "1010";
            else if (a == "B") return "1011";
            else if (a == "C") return "1100";
            else if (a == "D") return "1101";
            else if (a == "E") return "1110";
            else return "1111";
        }
        public int h_to_d(char a)
        {
            if (a == '0') return 0;
            else if (a == '1') return 1;
            else if (a == '2') return 2;
            else if (a == '3') return 3;
            else if (a == '4') return 4;
            else if (a == '5') return 5;
            else if (a == '6') return 6;
            else if (a == '7') return 7;
            else if (a == '8') return 8;
            else if (a == '9') return 9;
            else if (a == 'A') return 10;
            else if (a == 'B') return 11;
            else if (a == 'C') return 12;
            else if (a == 'D') return 13;
            else if (a == 'E') return 14;
            else return 15;
        }
        private void button7_Click(object sender, EventArgs e)
        {
            long n = 0;
            try
            {
                 n = long.Parse(textBox1.Text);
            }
            catch
            {
            }
            string nr = "";
            string nr2 = "";

           

            if (baseA == 10 && baseB == 2)
            {
                
                while ( n  > 0  )
                {
                    nr = nr + (n % 2).ToString();               
                    n = n / 2;                              
                }
                nr2 = inverse_string(nr);
                textBox2.Text = nr2.ToString();
            }
            if (baseA == 10 && baseB == 16)
            {
                while (n > 0)
                {
                    
                    nr = nr + h((n % 16));
                    n = n / 16;
                }
                nr2 = inverse_string(nr);
                textBox2.Text = nr2.ToString();
            }
            if (baseA == 2 && baseB == 10)
            {
                long sum = 0;
                int p = 0;
                while (n > 0)
                {
                    sum += (n%10)*(long)Math.Pow(2, p);
                    p++;
                    n = n / 10;
                }
                textBox2.Text = sum.ToString();
            }
            if (baseA == 2 && baseB == 16)
            {
                while (n > 0)
                {
                    nr = nr + b_to_h(n % 10000);
                    n = n / 10000;
                }
                nr2 = inverse_string(nr);
                textBox2.Text = nr2;
            }
            if (baseA == 16 && baseB == 2)
            {
                string nn = textBox1.Text;
                string mm = inverse_string(nn);
                int i = mm.Length - 1;
                while (i >= 0)
                {

                    nr = nr + h_to_b(mm[i].ToString());
                    i--;
                }
                textBox2.Text = nr;
            }
            if (baseA == 16 && baseB == 10)
            {
                string nn = textBox1.Text;
                int i = nn.Length-1;
                
                int p = 0;
                double sum = 0;
                while (i >= 0)
                {
                    int a = h_to_d(nn[i]);
                    
                    sum += a * (Math.Pow(16,p));
                    p++;
                    i--;
                }
                textBox2.Text = sum.ToString();
            }
            
        }

        private void button8_Click(object sender, EventArgs e)
        {
            hide();
            groupBox1.Visible = true;
            baseA = 0;
            baseB = 0;
            textBox1.Text = "";
            textBox2.Text = "";
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {

            if ((e.KeyChar < '0' || e.KeyChar > '9') && e.KeyChar != 8 && e.KeyChar != 'A' && e.KeyChar != 'B' && e.KeyChar != 'C' && e.KeyChar != 'D' && e.KeyChar != 'E' && e.KeyChar != 'F')
                e.Handled = true;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
