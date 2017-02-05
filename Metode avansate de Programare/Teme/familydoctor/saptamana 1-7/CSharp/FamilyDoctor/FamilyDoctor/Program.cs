using System;

using FamilyDoctor.UI;
using FamilyDoctor.Controller;
using FamilyDoctor.Repository;

namespace FamilyDoctor
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                FamilyDoctorUI ui = new FamilyDoctorUI();
                FamilyDoctorManager man = new FamilyDoctorManager();

                ui.FamilyDoctorManager = man;

                man.PatientRepository = new PatientRepositoryFile("patients.xml", RepositoryFileFormat.XML);
                man.AppointmentRepository = new AppointmentRepositoryFile("appointments.csv", RepositoryFileFormat.CSV);

                ui.ShowUI();
            }
            catch (Exception ex)
            {
                Console.WriteLine("The app crashed. How sad... :( " + ex.Message);
            }
        }
    }
}
