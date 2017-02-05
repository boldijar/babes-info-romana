using System;

namespace ClerkOffice.Models
{
    public class Ticket
    {
        int orderNumber;
        bool active;
        readonly DateTime requestDate;

        public int OrderNumber
        {
            get { return orderNumber; }
            set
            {
                orderNumber = value;
                TicketValidator.ValidateOrderNumber(value);
            }
        }

        public bool Active
        {
            get { return active; }
            set { active = value; }
        }

        public DateTime RequestDate
        {
            get { return requestDate; }
        }

        public Ticket()
        {
            active = true;
            requestDate = DateTime.Now;
        }

        public Ticket(int orderNumber)
            : this()
        {
            this.orderNumber = orderNumber;

            TicketValidator.Validate(this);
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            if (obj.GetType() == typeof(Ticket))
            if (orderNumber == ((Ticket)obj).OrderNumber)
                return true;
            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return orderNumber + "(ReleaseDate: " + requestDate + "; Expired: " + active + ")";
        }

        public static class TicketValidator
        {
            public static void Validate(Ticket ticket)
            {
                ValidateOrderNumber(ticket.OrderNumber);
            }

            public static void ValidateOrderNumber(int orderNumber)
            {
                if (orderNumber < 0)
                    throw new ValidationException("Invalid order number");
            }
        }
    }
}
