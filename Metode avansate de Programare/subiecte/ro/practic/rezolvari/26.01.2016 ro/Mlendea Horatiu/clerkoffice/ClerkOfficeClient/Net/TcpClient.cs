using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

using ClerkOffice.Utils;

namespace ClerkOffice.Net
{
    class TcpClient
    {
        readonly EndPoint endPoint;

        internal TcpClient()
        {
            IPHostEntry ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            IPAddress ipAddress = ipHostInfo.AddressList[0];
            endPoint = new IPEndPoint(ipAddress, 1929);
        }

        internal Message Execute(object request)
        {
            try
            {
                Log.WriteLine("Connecting socket...", 2);
                Socket socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                socket.Connect(endPoint);

                Log.WriteLine("Sending request...", 2);
                byte[] bytesRequest = Encoding.ASCII.GetBytes(request.ToString());
                socket.Send(bytesRequest);

                Log.WriteLine("Receiving response...", 2);
                byte[] bytes = new byte[1024];
                int bytesRec = socket.Receive(bytes);

                Log.WriteLine("Closing socket...", 2);
                socket.Shutdown(SocketShutdown.Both);
                socket.Close();

                return new Message(Encoding.ASCII.GetString(bytes, 0, bytesRec));
            }
            catch (SocketException se)
            {
                string error = "Socket Exception: " + se.Message;
                Log.WriteError(error);
            }

            return null;
        }
    }
}
