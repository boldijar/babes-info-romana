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

            SendHttpPostRequest(
                "command=addpatient",
                "id=" + id,
                "name=" + name,
                "age=" + age);
        }

        void RemovePatient()
        {
            string id = Input("Patient ID = ");

            if (InputPermission("This will permanently remove the specified patient and all it's associated appointments. Continue?"))
                SendHttpPostRequest(
                    "command=removepatient",
                    "id=" + id);
        }

        void GetPatientByID()
        {
            string id = Input("Patient ID = ");

            SendHttpPostRequest(
                "command=listpatients",
                "criteria=id",
                "value=" + id);
        }

        void ListPatients()
        {
            SendHttpPostRequest(
                "command=listpatients",
                "criteria=all");
        }

        void ListPatientsOverAge()
        {
            string age = Input("Age = ");

            SendHttpPostRequest(
                "command=listpatients",
                "criteria=age-gt",
                "value=" + age);
        }

        void ListPatientsUnderAge()
        {
            string age = Input("Age = ");

            SendHttpPostRequest(
                "command=listpatients",
                "criteria=age-lt",
                "value=" + age);
        }
    }
}
