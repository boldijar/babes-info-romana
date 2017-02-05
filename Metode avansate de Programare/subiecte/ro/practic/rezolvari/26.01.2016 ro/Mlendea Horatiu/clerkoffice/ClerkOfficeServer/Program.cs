using ClerkOffice.Net;
using ClerkOffice.Service;
using ClerkOffice.Controllers;
using ClerkOffice.Repositories;

namespace ClerkOffice
{
    class Program
    {
        static void Main()
        {
            ClerkOfficeManager man = new ClerkOfficeManager();
            man.ClerkRepository = new ClerkRepository("clerks.xml");
            man.TicketRepository = new TicketRepository("tickets.xml");

            TcpServer tcpServer = new TcpServer();
            tcpServer.CommandService = new CommandService(man);
            tcpServer.Start();
        }
    }
}
