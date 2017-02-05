using ClerkOffice.Models;

namespace ClerkOffice.Repositories
{
    public class TicketRepository : Repository<Ticket>
    {
        public TicketRepository(string filename)
            : base(filename)
        {

        }

        public Ticket GetByOrderNumber(int orderNumber)
        {
            Ticket ticket = Entities.Find(T => T.OrderNumber == orderNumber);

            if (ticket == null)
                throw new RepositoryException("The specified ticket does not exist");

            return ticket;
        }

        public bool Contains(int orderNumber)
        {
            return Entities.Find(T => T.OrderNumber == orderNumber) != null;
        }
    }
}
