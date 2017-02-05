using System;
using System.Collections.Generic;

namespace FamilyDoctor.Domain
{
    public class Patient
    {
        private string id, name;
        private int age;
        List<string> appointmentIDs;

        public string ID { get { return id; } set { id = value; } }
        public string Name { get { return name; } set { name = value; } }
        public int Age { get { return age; } set { age = value; } }
        public List<string> AppointmentIDs { get { return appointmentIDs; } }
        public int AppointmentsCount { get { return appointmentIDs.Count; } }

        public Patient()
        {
            appointmentIDs = new List<string>();
        }

        public Patient(string id, string name, int age)
        {
            this.id = id;
            this.name = name;
            this.age = age;

            appointmentIDs = new List<string>();

            Validate();
        }

        public void Validate()
        {
            if (id == null || id == string.Empty)
                throw new ValidationException("Invalid ID");

            if (name == null || name == string.Empty)
                throw new ValidationException("Invalid name");

            if (age < 0)
                throw new ValidationException("Invalid age");
        }

        public override bool Equals(object other)
        {
            if (other == null)
                return false;

            if (other.GetType() == typeof(Patient))
                if (id == ((Patient)other).ID)
                    return true;
            return false;
        }

        public override string ToString()
        {
            return name + " (ID:" + id + "; Age:" + age + ")";
        }
    }
}
