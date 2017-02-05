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

            SendHttpPostRequest(
                "command=addappointment",
                "appointmentID=" + id,
                "patientID=" + patientId,
                "diagnostic=" + diagnostic,
                "date=" + date,
                "isEmergency=" + isEmergency);
        }

        void RemoveAppointment()
        {
            string id = Input("Appointment ID = ");

            if (InputPermission("This will permanently remove the specified appointment. Continue?"))
                SendHttpPostRequest(
                    "command=removeappointment",
                    "id=" + id);
        }

        void ListAppointments()
        {
            SendHttpPostRequest(
                "command=listappointments",
                "criteria=all");
        }

        void ListAppointmentsOfPatient()
        {
            string patientID = Input("Patient ID = ");
            SendHttpPostRequest(
                "command=listappointments",
                "criteria=patientid",
                "value=" + patientID);
        }

        void ListAppointmentsByDiagnostic()
        {
            string diagnostic = Input("Diagnostic = ");

            SendHttpPostRequest(
                "command=listappointments",
                "criteria=diagnostic",
                "value=" + diagnostic);
        }

        void ListAppointmentsByEmergency()
        {
            string isEmergency = Input("Is emergency? (true/false) = ");

            SendHttpPostRequest(
                "command=listappointments",
                "criteria=emergency",
                "value=" + isEmergency);
        }

        void ListAppointmentsAfterDate()
        {
            string date = Input("Date = ");

            SendHttpPostRequest(
                "command=listappointments",
                "criteria=date-gt",
                "value=" + date);
        }

        void ListAppointmentsBeforeDate()
        {
            string date = Input("Date = ");

            SendHttpPostRequest(
                "command=listappointments",
                "criteria=date-lt",
                "value=" + date);
        }
    }
}

