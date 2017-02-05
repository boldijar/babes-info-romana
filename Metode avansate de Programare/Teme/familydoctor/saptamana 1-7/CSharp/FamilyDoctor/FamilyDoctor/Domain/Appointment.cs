using System;

namespace FamilyDoctor.Domain
{
    public class Appointment
    {
        private string id, patientId, diagnostic;
        private bool isEmergency;

        public string ID { get { return id; } set { id = value; } }
        public string PatientID { get { return patientId; } set { patientId = value; } }
        public string Diagnostic { get { return diagnostic; } set { diagnostic = value; } }
        public bool IsEmergency { get { return isEmergency; } set { isEmergency = value; } }

        public Appointment()
        {

        }

        public Appointment(string id, string patientId, string diagnostic, bool isEmergency = false)
        {
            this.id = id;
            this.patientId = patientId;
            this.diagnostic = diagnostic;
            this.isEmergency = isEmergency;
        }
        
        public void Validate()
        {
            if (id == null || id == string.Empty)
                throw new ValidationException("Invalid ID");

            if (patientId == null || patientId == string.Empty)
                throw new ValidationException("Invalid name");

            if (diagnostic == null || diagnostic == string.Empty)
                throw new ValidationException("Invalid age");
        }

        public override bool Equals(object other)
        {
            if (other == null)
                return false;

            if (other.GetType() == typeof(Appointment))
                if (id == ((Appointment)other).ID)
                    return true;
            return false;
        }

        public override string ToString()
        {
            return id + " (PatientID:" + patientId + ", Diag:" + diagnostic + ", IsEmergency:" + isEmergency + ")";
        }
    }
}
