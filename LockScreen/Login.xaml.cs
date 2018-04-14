using System.IO.Ports;
using System.Windows;

namespace LockScreen
{
    /// <summary>
    /// Logika interakcji dla klasy Login.xaml
    /// </summary>
    public partial class Login : Window
    {
        public Login()
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
            if (data.Contains("Login"))
            {
                Dispatcher.Invoke(() => {

                    var Login = new Login();
                    Login.Show();
                });
            }
        }
    }
}
