using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

using FamilyDoctor.Service;
using FamilyDoctor.Utils;

namespace FamilyDoctor.Net
{
    public class TcpServer
    {
        readonly IPEndPoint endPoint;

        public TcpServer()
        {
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            endPoint = new IPEndPoint(ipAddress, 1929);
        }

        public void Start()
        {
            try
            {
                Socket socketListner = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                socketListner.Bind(endPoint);
                socketListner.Listen(10);
                Log.WriteLine("Server is listening...");
                while (true)
                {
                    Log.WriteLine("Waiting for connections...", 2);
                    Socket clientSocket = socketListner.Accept();

                    Log.WriteLine("Connection accepted. Handling it...", 2);
                    Task.Factory.StartNew(new ClientHandler(clientSocket, CommandService).Handle);
                }
            }
            catch (SocketException se)
            {
                string error = "Socket Exception: " + se.Message;
                Log.WriteError(error);
            }
        }

        public ICommandService CommandService { get; internal set; }

        class ClientHandler
        {
            readonly Socket clientSocket;
            readonly ICommandService commandService;

            public ClientHandler(Socket clientSocket, ICommandService commandService)
            {
                this.clientSocket = clientSocket;
                this.commandService = commandService;
            }

            internal void Handle()
            {
                try
                {
                    Log.WriteLine("Receiving request...", 2);

                    byte[] bytes = new byte[1024];
                    int bytesRec = clientSocket.Receive(bytes);

                    Log.WriteLine("Creating response...", 2);
                    Message request = new Message(Encoding.ASCII.GetString(bytes, 0, bytesRec));
                    string result = commandService.ExecuteCommand(request.ToString());

                    Log.WriteLine("Sending response...", 2);
                    byte[] bytesRequest = Encoding.ASCII.GetBytes(result);
                    clientSocket.Send(bytesRequest);

                    Log.WriteLine("Shutting down...", 2);
                    clientSocket.Shutdown(SocketShutdown.Both);
                    clientSocket.Close();
                }
                catch (SocketException se)
                {
                    string error = "Socket Exception: " + se.Message;
                    Log.WriteError(error);
                }
            }
        }
    }
}
