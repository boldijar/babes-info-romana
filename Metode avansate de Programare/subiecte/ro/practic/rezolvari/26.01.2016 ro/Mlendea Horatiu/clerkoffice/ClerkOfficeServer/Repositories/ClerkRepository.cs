using ClerkOffice.Models;

namespace ClerkOffice.Repositories
{
    public class ClerkRepository : Repository<Clerk>
    {
        public ClerkRepository(string filename)
            : base(filename)
        {

        }

        public Clerk GetByUsername(string username)
        {
            Clerk clerk = Entities.Find(C => C.Username == username);

            if (clerk == null)
                throw new RepositoryException("The specified username does not exist");

            return clerk;
        }

        public bool Contains(string username)
        {
            return Entities.Find(C => C.Username == username) != null;
        }
    }
}
