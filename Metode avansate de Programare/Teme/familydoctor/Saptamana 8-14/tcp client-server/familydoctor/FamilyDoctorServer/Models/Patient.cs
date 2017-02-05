using System.Collections.Generic;

namespace FamilyDoctor.Models
{
    public class Patient
    {
        string id, name;
        int age;
        List<string> appointmentIDs;

        public string ID
        {
            get { return id; }
            set
            {
                id = value;
                PatientValidator.ValidateID(value);
            }
        }

        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                PatientValidator.ValidateName(value);
            }
        }

        public int Age
        {
            get { return age; }
            set
            {
                age = value;
                PatientValidator.ValidateAge(value);
            }
        }

        public List<string> AppointmentIDs
        {
            get { return appointmentIDs; }
        }

        public int AppointmentsCount
        {
            get { return appointmentIDs.Count; }
        }

        public Patient()
        {
            appointmentIDs = new List<string>();
        }

        public Patient(string id, string name, int age)
            : this()
        {
            this.id = id;
            this.name = name;
            this.age = age;

            PatientValidator.Validate(this);
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            if (obj.GetType() == typeof(Patient))
            if (id == ((Patient)obj).ID)
                return true;
            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return name + " (ID:" + id + "; Age:" + age + ")";
        }

        static class PatientValidator
        {
            public static void Validate(Patient patient)
            {
                ValidateID(patient.ID);
                ValidateName(patient.Name);
                ValidateAge(patient.Age);
            }

            public static void ValidateID(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid ID");
            }

            public static void ValidateName(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid name");
            }

            public static void ValidateAge(int value)
            {
                if (value < 0)
                    throw new ValidationException("Invalid age");
            }
        }
    }
}
