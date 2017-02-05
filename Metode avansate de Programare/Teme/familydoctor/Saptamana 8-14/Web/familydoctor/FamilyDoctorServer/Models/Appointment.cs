using System;

namespace FamilyDoctor.Models
{
    public class Appointment
    {
        string id, patientId, diagnostic;
        bool isEmergency;
        DateTime date;

        public string ID
        {
            get { return id; }
            set
            {
                id = value;
                AppointmentValidator.ValidateID(value);
            }
        }

        public string PatientID
        {
            get { return patientId; }
            set
            {
                patientId = value;
                AppointmentValidator.ValidatePatientID(value);
            }
        }

        public string Diagnostic
        {
            get { return diagnostic; }
            set
            {
                diagnostic = value;
                AppointmentValidator.ValidateDiagnostic(diagnostic);
            }
        }

        public DateTime Date
        {
            get { return date; }
            set
            {
                date = value;
                AppointmentValidator.ValidateDate(date);
            }
        }

        public bool IsEmergency
        {
            get { return isEmergency; }
            set { isEmergency = value; }
        }

        public bool Past
        {
            get { return DateTime.Now > date; }
        }

        public Appointment()
        {

        }

        public Appointment(string id, string patientId, string diagnostic, DateTime date)
            : this()
        {
            this.id = id;
            this.patientId = patientId;
            this.diagnostic = diagnostic;
            this.date = date;
            this.isEmergency = false;

            AppointmentValidator.Validate(this);
        }

        public Appointment(string id, string patientId, string diagnostic, DateTime date, bool isEmergency)
            : this(id, patientId, diagnostic, date)
        {
            this.isEmergency = isEmergency;
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            if (obj.GetType() == typeof(Appointment))
            if (id == ((Appointment)obj).ID)
                return true;
            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return id + " (PatientID:" + patientId + ", Diag:" + diagnostic + ", IsEmergency:" + isEmergency + ")";
        }

        public static class AppointmentValidator
        {
            public static void Validate(Appointment appointment)
            {
                ValidateID(appointment.ID);
                ValidatePatientID(appointment.PatientID);
                ValidateDiagnostic(appointment.Diagnostic);
                ValidateDate(appointment.Date);
            }

            public static void ValidateID(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid ID");
            }

            public static void ValidatePatientID(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid Patient ID");
            }

            public static void ValidateDiagnostic(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid diagnostic");
            }

            public static void ValidateDate(DateTime value)
            {
                // TODO: Real validation. This if always returns false, DateTime's value cannot be null
                if (value == null)
                    throw new ValidationException("Invalid diagnostic");
            }
        }
    }
}
