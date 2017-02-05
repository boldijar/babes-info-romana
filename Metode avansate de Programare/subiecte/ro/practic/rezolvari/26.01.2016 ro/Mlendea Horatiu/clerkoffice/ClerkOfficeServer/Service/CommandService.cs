using System;
using System.Collections.Generic;
using System.Linq;

using ClerkOffice.Service;
using ClerkOffice.Models;
using ClerkOffice.Controllers;
using ClerkOffice.Repositories;
using ClerkOffice.Utils;

namespace ClerkOffice.Service
{
    class CommandService : ICommandService
    {
        readonly ClerkOfficeManager manager;

        public CommandService(ClerkOfficeManager manager)
        {
            this.manager = manager;
        }

        public string ExecuteCommand(string command)
        {
            string[] cmd = command.Split(' ');
            string response;

            Log.WriteLine("Received command: " + command);

            try
            {
                switch (cmd[0])
                {
                    case "ping":
                        response = "pong";
                        break;

                    case "login":
                        response = Login(cmd.Skip(1).ToArray());
                        break;

                    case "ticket":
                        response = GetTicket();
                        break;

                    case "next":
                        response = NextTicket();
                        break;

                    case "arrived":
                        response = ConfirmTicketArrival(cmd.Skip(1).ToArray());
                        break;

                    case "deactivateticket":
                        response = DeactivateTicket(cmd.Skip(1).ToArray());
                        break;

                    default:
                        Console.WriteLine("Invalid command");
                        response = "INVALID COMMAND";
                        break;
                }
            }
            catch (Exception ex)
            {
                response = "Exception: " + ex.Message;
                Log.WriteWarning(response);
            }

            return response;
        }

        string Login(params string[] list)
        {
            string message = "";
            manager.LoginClerk(list[0], list[1]);
            return message;
        }

        string GetTicket()
        {
            string message;

            Ticket ticket = manager.AddTicket();
            message = ticket.ToString();

            return message;
        }

        string NextTicket()
        {
            string message;

            Ticket ticket = manager.GetNextTicket();
            manager.DeactivateTicket(ticket.OrderNumber);

            message = "Next ticket (" + ticket.OrderNumber + ") called and deactivated";
            return message;
        }

        string DeactivateTicket(params string[] list)
        {
            int orderNumber = int.Parse(list[0]);

            manager.DeactivateTicket(orderNumber);

            return "Ticket #" + orderNumber + " deactivated";
        }

        string ConfirmTicketArrival(params string[] list)
        {
            string message;

            Ticket ticket = manager.GetNextTicket();
            ticket.Active = false;

            message = "Ticket #" + ticket.OrderNumber + " has arrived!";

            return message;
        }
    }
}