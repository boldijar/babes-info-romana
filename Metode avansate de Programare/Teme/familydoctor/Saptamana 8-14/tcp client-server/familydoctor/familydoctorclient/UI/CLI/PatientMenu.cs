using System;

namespace FamilyDoctor.UI.CLI
{
    public class PatientMenu : Menu
    {
        public PatientMenu()
        {
            Name = "Patient Menu";

            MenuHelpList.Add("1. Add patient");
            MenuHelpList.Add("2. Remove patient");
            MenuHelpList.Add("3. Get patient by ID");
            MenuHelpList.Add("4. List patients");
            MenuHelpList.Add("5. List patients over age X");
            MenuHelpList.Add("6. List patients under age X");
        }

        public override void HandleCommand()
        {
            switch (CurrentCommand)
            {
                case "1":
                    AddPatient();
                    break;

                case "2":
                    RemovePatient();
                    break;

                case "3":
                    GetPatientByID();
                    break;

                case "4":
                    ListPatients();
                    break;

                case "5":
                    ListPatientsOverAge();
                    break;

                case "6":
                    ListPatientsUnderAge();
                    break;

                default:
                    Console.WriteLine("Invalid command!");
                    break;
            }
        }

        void AddPatient()
        {
            string id = Input("Patient ID = ");
            string name = Input("Patient name = ");
            int age = int.Parse(Input("Patient age = "));

            ExecuteCommand("addpatient", id, name, age.ToString());
        }

        void RemovePatient()
        {
            string id = Input("Patient ID = ");

            if (InputPermission("This will permanently remove the specified patient and all it's associated appointments. Continue?"))
                ExecuteCommand("removepatient", id);
        }

        void GetPatientByID()
        {
            string id = Input("Patient ID = ");
            ExecuteCommand("listpatients", "id", id);
        }

        void ListPatients()
        {
            ExecuteCommand("listpatients");
        }

        void ListPatientsOverAge()
        {
            string age = Input("Age = ");
            ExecuteCommand("listpatients", "age-gt", age);
        }

        void ListPatientsUnderAge()
        {
            string age = Input("Age = ");
            ExecuteCommand("listpatients", "age-lt", age);
        }
    }
}

