using System;
using FamilyDoctor.Net;
using FamilyDoctor.Service;

namespace FamilyDoctor.Service
{
    class CommandServiceProxy : ICommandService
    {
        public TcpClient TcpClient { get; internal set; }

        public string ExecuteCommand(string command)
        {
            try
            {
                Message request = new Message(command);
                Message response = TcpClient.Execute(request);
                return response.ToString();
            }
            catch (Exception e)
            {
                throw new ServiceException("Service unavailable", e);
            }
        }
    }
}