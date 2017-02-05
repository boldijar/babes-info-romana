using FamilyDoctor.Models;
using FamilyDoctor.Utils;

namespace FamilyDoctor.Repositories
{
    public class PatientRepository : Repository<Patient>
    {
        public PatientRepository(string filename)
            : base(filename)
        {
            
        }

        public virtual void AddAppointment(string appointmentID, string patientID)
        {
            Patient patient = Entities.Find(P => P.ID == patientID);
            patient.AppointmentIDs.Add(appointmentID);

            Log.WriteLine("Associated appointment '" + appointmentID + "' with patient '" + patientID + "'");
        }

        public Patient GetByID(string id)
        {
            Patient patient = Entities.Find(P => P.ID == id);

            if (patient == null)
                throw new RepositoryException("The specified ID does not exist");

            return patient;
        }

        public bool Contains(string id)
        {
            return Entities.Find(P => P.ID == id) != null;
        }
    }
}
