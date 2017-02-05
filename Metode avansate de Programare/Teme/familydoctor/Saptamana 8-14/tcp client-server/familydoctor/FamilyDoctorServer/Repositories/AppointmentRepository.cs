using FamilyDoctor.Models;

namespace FamilyDoctor.Repositories
{
    public class AppointmentRepository : Repository<Appointment>
    {
        public AppointmentRepository(string filename)
            : base(filename)
        {
            
        }

        public Appointment GetByID(string id)
        {
            Appointment appointment = Entities.Find(P => P.ID == id);

            if (appointment == null)
                throw new RepositoryException("The specified ID does not exist");

            return appointment;
        }

        public bool Contains(string id)
        {
            return Entities.Find(A => A.ID == id) != null;
        }
    }
}
