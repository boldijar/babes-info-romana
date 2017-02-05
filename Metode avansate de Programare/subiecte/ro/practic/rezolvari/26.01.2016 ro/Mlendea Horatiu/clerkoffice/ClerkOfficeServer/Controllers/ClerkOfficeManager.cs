using System;
using System.Collections.Generic;
using System.Linq;

using ClerkOffice.Models;
using ClerkOffice.Repositories;
using System.Security.Authentication;

namespace ClerkOffice.Controllers
{
    class ClerkOfficeManager
    {
        ClerkRepository clerkRepository;
        TicketRepository ticketRepository;

        public ClerkRepository ClerkRepository
        {
            set { clerkRepository = value; }
        }

        public TicketRepository TicketRepository
        {
            set { ticketRepository = value; }
        }

        public Clerk AddClerk(string username, string password)
        {
            Clerk clerk = new Clerk();

            clerk.Username = username;
            clerk.Password = password;

            clerkRepository.Add(clerk);
            return clerk;
        }

        public Ticket AddTicket()
        {
            Ticket ticket = new Ticket();
            IOrderedEnumerable<Ticket> tickets = ticketRepository.GetAll().OrderByDescending(T => T.OrderNumber);
            int orderNumber;

            if (tickets.Count() == 0)
                orderNumber = 0;
            else
                orderNumber = tickets.First().OrderNumber + 1;

            ticket.OrderNumber = orderNumber;

            ticketRepository.Add(ticket);
            return ticket;
        }

        public void DeactivateTicket(int orderNumber)
        {
            foreach (Ticket ticket in ticketRepository.GetAll())
                if (ticket.OrderNumber == orderNumber)
                    ticket.Active = false;
            ticketRepository.Save();
        }

        public Ticket GetNextTicket()
        {
            Ticket ticket;
            IOrderedEnumerable<Ticket> tickets = ticketRepository.GetAll().FindAll(T => T.Active).OrderByDescending(T => T.OrderNumber);
            int orderNumber;

            orderNumber = tickets.First().OrderNumber;
            ticket = ticketRepository.GetByOrderNumber(orderNumber);

            return ticket;
        }

        public bool LoginClerk(string username, string password)
        {
            Clerk clerk = GetClerkByUsername(username);
            bool success = true;

            if (clerk == null)
                success = false;

            if (clerk.Password != password)
                success = false;

            if (!success)
                throw new AuthenticationException("Login failed");
            return success;
        }

        public Clerk GetClerkByUsername(string username)
        {
            return clerkRepository.GetByUsername(username);
        }

        public Ticket GetTicketByOrderNumber(int orderNumber)
        {
            return ticketRepository.GetByOrderNumber(orderNumber);
        }

        public List<Clerk> GetAllClerks()
        {
            return clerkRepository.GetAll();
        }

        public List<Ticket> GetAllTickets()
        {
            return ticketRepository.GetAll();
        }
    }
}
