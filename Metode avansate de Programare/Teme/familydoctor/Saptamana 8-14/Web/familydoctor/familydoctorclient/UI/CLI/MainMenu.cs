using System;

namespace FamilyDoctor.UI.CLI
{
    public class MainMenu : Menu
    {
        public MainMenu()
        {
            Name = "Main Menu";

            MenuHelpList.Add("1. Open Patients Menu");
            MenuHelpList.Add("2. Open Appointments Menu");
        }

        public override void HandleCommand()
        {
            switch (CurrentCommand)
            {
                case "1":
                    ShowPatientMenu();
                    break;

                case "2":
                    ShowAppointmentMenu();
                    break;

                default:
                    Console.WriteLine("Invalid command!");
                    break;
            }
        }

        void ShowPatientMenu()
        {
            new PatientMenu().Show();
        }

        void ShowAppointmentMenu()
        {
            new AppointmentMenu().Show();
        }
    }
}