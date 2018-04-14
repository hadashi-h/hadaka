using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO.Ports;
using System.Threading;

namespace LockScreen
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        SerialPort serialPort = new SerialPort("COM3");
        List<int> buffor;
        List<string> bufforSound;

        public MainWindow()
        {
            InitializeComponent();

            //serialPort.Open();
            //serialPort.DataReceived += SerialPort_DataReceived;

            buffor = new List<int>(new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 0 });
            bufforSound = new List<string>(new string[] { "", "", "", "", "", "", "", "", "" });

        }

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            //throw new NotImplementedException();
            int item;
            Int32.TryParse(serialPort.ReadLine(), out item);
            // Console.WriteLine(item);

            int numberOfItems = buffor.Count;

            if (item > buffor.ElementAt(0) + 5 || item < buffor.ElementAt(0) - 5)
            {
                for (int i = 9; i >= 1; i--)
                {
                    buffor.Insert(i, buffor.ElementAt(i - 1));
                }
                buffor.Insert(0, item);


                for (int i = 0; i < 9; i++)
                {
                    Console.Write(buffor.ElementAt(i));
                    Console.Write(" ");
                }
                Console.WriteLine();

            }

            BufforToSoundBuffor(buffor, bufforSound);

            for (int i = 0; i < 9; i++)
            {
                Console.Write(bufforSound.ElementAt(i));
                Console.Write(" ");
            }
            Console.WriteLine();


        }

        public void BufforToSoundBuffor(List<int> buffor, List<string> bufforOfSound)
        {
            for(int i = 0; i<9; i++)
            {
                if(buffor.ElementAt(i)<20)
                {
                    bufforOfSound.Insert(i,"cH");
                }
                else if(buffor.ElementAt(i)>=20 && buffor.ElementAt(i)<40)
                {
                    bufforOfSound.Insert(i, "f");
                }
                else
                {
                    bufforOfSound.Insert(i, "a");
                }
            }
        }

    }

   
}
