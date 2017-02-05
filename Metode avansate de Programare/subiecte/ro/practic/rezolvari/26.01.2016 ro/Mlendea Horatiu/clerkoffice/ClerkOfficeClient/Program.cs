using System;
using Gtk;

using ClerkOffice.Service;
using ClerkOffice.Net;

namespace ClerkOffice
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            CommandServiceProxy commandService = new CommandServiceProxy();
            commandService.TcpClient = new TcpClient();

            Application.Init();
            MainWindow win = new MainWindow();
            win.CommandService = commandService;
            win.Show();
            Application.Run();
        }
    }
}
