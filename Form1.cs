using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Drawing.Drawing2D;

namespace aproksimator
{
    public partial class Form1 : Form
    {
        private int N;
        private double pi = 3.1415926535;
        public double w;
        public int shag;
        public int mirror;
        [DllImport("c:\\users\\user\\documents\\visual studio 2013\\Projects\\aproksimatorcc\\Debug\\aproksimatorcc.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern double count(int j, int k, int N, double w, double K, double m1, double m2, double m3, int mirror, int shag);
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double buff = count(0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
            N = Convert.ToInt32(buff);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string str = textBox2.Text;
            w = Convert.ToDouble(str);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            string str = textBox1.Text;
            mirror = Convert.ToInt32(str);
            str = textBox3.Text;
            shag = Convert.ToInt32(str);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double fi, t, W = 0.8 * w, wmin = 0, s;
            double[] a = new double[N];
            for (int j = 0; j < N; j++)
                a[j] = count(j, 2, N, 0, 0, 0, 0, 0, 0, 0);
            double[] x = new double[3];
            double[] z = new double[mirror];
            while (W <= 1.2 * w)
            {
                for (int j = 0; j < 3; j++)
                    x[j] = count(j, 3, N, W, 0, 0, 0, 0, mirror, shag);
                double K = count(0, 4, N, W, 0, 0, 0, 0, mirror, shag);//находим разность между исходной и апроксимированной точкой
                wmin = count(0, 5, N, W, K, x[0], x[1], x[2], mirror, shag);//здесь найдем значение частоты, при котором разность координат апроксимированной и исходной функцией будет наименьшей
                W += (1.2 * w - 0.8 * w) / 4;
            }
            for (int j = 0; j < 3; j++)
                x[j] = count(j, 3, N, wmin, 0, 0, 0, 0, mirror, shag);//находим значение коэффициентов А, В и С при наилучшей частоте
            fi = Math.Atan(x[1] / x[0]); //находим угол fi
            if (fi > -pi / 2 || fi < pi / 2) //вычисляем время до экстремума исходя из значения угла 
            {
                t = (pi / 2 - fi) / wmin;
                s = x[0] * Math.Sin(wmin * t) + x[1] * Math.Cos(wmin * t) + x[2]; //нахоим значение экстремума
                label2.Text = t.ToString();
                label4.Text = s.ToString();
                label6.Text = "максимум";
            }
            else if (fi > -3 * pi / 2 || pi < -pi / 2)
            {
                t = -(pi / 2 - fi) / wmin;
                s = x[0] * Math.Sin(wmin * t) + x[1] * Math.Cos(wmin * t) + x[2]; //нахоим значение экстремума
                label2.Text = t.ToString();
                label4.Text = s.ToString();
                label6.Text = "минимум";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

    }
}
