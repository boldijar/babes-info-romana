using System;

namespace FamilyDoctor.UI.CLI
{
    public class AppointmentMenu : Menu
    {
        public AppointmentMenu()
        {
            Name = "Appointment Menu";

            MenuHelpList.Add("1. Add appointment");
            MenuHelpList.Add("2. Remove appointment");
            MenuHelpList.Add("3. List appointments");
            MenuHelpList.Add("4. List appointments of patient");
            MenuHelpList.Add("5. List appointments by diagnostic");
            MenuHelpList.Add("6. List appointments by emergency");
            MenuHelpList.Add("7. List appointments after date X");
            MenuHelpList.Add("8. List appointments before date X");
        }

        public override void HandleCommand()
        {
            switch (CurrentCommand)
            {
                case "1":
                    AddAppointment();
                    break;

                case "2":
                    RemoveAppointment();
                    break;

                case "3":
                    ListAppointments();
                    break;

                case "4":
                    ListAppointmentsOfPatient();
                    break;

                case "5":
                    ListAppointmentsByDiagnostic();
                    break;

                case "6":
                    ListAppointmentsByEmergency();
                    break;

                case "7":
                    ListAppointmentsAfterDate();
                    break;

                case "8":
                    ListAppointmentsBeforeDate();
                    break;

                default:
                    Console.WriteLine("Invalid command!");
                    break;
            }
        }

        void AddAppointment()
        {
            string id = Input("Appointment ID = ");
            string patientId = Input("Patient ID = ");
            string diagnostic = Input("Diagnostic = ");
            DateTime date = DateTime.Parse(Input("Date = "));
            bool isEmergency = bool.Parse(Input("Is emergency? (true/false) = "));

            ExecuteCommand("addappointment", id, patientId, diagnostic, date.ToString(), isEmergency.ToString());
        }

        void RemoveAppointment()
        {
            string id = Input("Appointment ID = ");

            if (InputPermission("This will permanently remove the specified appointment. Continue?"))
                ExecuteCommand("removeappointment", id);
        }

        void ListAppointments()
        {
            ExecuteCommand("listappointments");
        }

        void ListAppointmentsOfPatient()
        {
            string patientID = Input("Patient ID = ");
            ExecuteCommand("listappointments", "patientid", patientID);
        }

        void ListAppointmentsByDiagnostic()
        {
            string diagnostic = Input("Diagnostic = ");
            ExecuteCommand("listappointments", "diagnostic", diagnostic);
        }

        void ListAppointmentsByEmergency()
        {
            string isEmergency = Input("Is emergency? (true/false) = ");
            ExecuteCommand("listappointments", "emergency", isEmergency);
        }

        void ListAppointmentsAfterDate()
        {
            string date = Input("Date = ");
            ExecuteCommand("listappointments", "date-gt", date);
        }

        void ListAppointmentsBeforeDate()
        {
            string date = Input("Date = ");
            ExecuteCommand("listappointments", "date-lt", date);
        }
    }
}

