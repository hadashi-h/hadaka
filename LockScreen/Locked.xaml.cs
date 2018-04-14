using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
 namespace LockScreen
{
    /// <summary>
    /// Logika interakcji dla klasy Locked.xaml
    /// </summary>
    public partial class Locked : Window
    {
        public Locked()
        {
            InitializeComponent();

            if (!serialPort.IsOpen)
            {
                serialPort.Open();
            }
            serialPort.DataReceived += SerialPort_DataReceived;
        }
        SerialPort serialPort = new SerialPort("COM6");

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string data = serialPort.ReadExisting();
            if (data.Contains("Hubert"))
            {
                serialPort.DataReceived -= SerialPort_DataReceived;
                Dispatcher.Invoke(() => {

                    var Login = new Login();
                    Login.Show();
                });
            }
        }
    }
}
