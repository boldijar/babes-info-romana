using System;
using System.Collections.Generic;

using FamilyDoctor.Domain;
using FamilyDoctor.Controller;
using FamilyDoctor.Repository;

namespace FamilyDoctor.UI
{
    class FamilyDoctorUI
    {
        private FamilyDoctorManager familyDoctorManager;
        
        public FamilyDoctorManager FamilyDoctorManager { set { familyDoctorManager = value; } }

        private static string Input(string prompt)
        {
            Console.Write(prompt);
            return Console.ReadLine();
        }

        private void PrintCommands()
        {
            Console.WriteLine("1. Add patient");
            Console.WriteLine("2. Add appointment");
            Console.WriteLine("3. List patients");
            Console.WriteLine("4. List appointments");
            Console.WriteLine("5. List appointments of patient");
            Console.WriteLine("0. Exit");
        }

        public void ShowUI()
        {
            string cmd = string.Empty;

            while (cmd != "0")
            {
                PrintCommands();

                Console.Write("Enter command: ");
                cmd = Console.ReadLine();
                Console.WriteLine();

                switch (cmd)
                {
                    case "1":
                        AddPatient();
                        break;

                    case "2":
                        AddAppointment();
                        break;

                    case "3":
                        ListPatients();
                        break;

                    case "4":
                        ListAppointments();
                        break;

                    case "5":
                        ListAppointmentsOfPatient();
                        break;

                    case "0":
                        break;

                    default:
                        Console.WriteLine("Invalid command!");
                        break;
                }
                Console.WriteLine("\n--------------");
            }
        }

        public void AddPatient()
        {
            try
            {
                string id = Input("Patient ID = ");
                string name = Input("Patient name = ");
                int age = int.Parse(Input("Patient age = "));

                familyDoctorManager.AddPatient(id, name, age);
            }
            catch (ValidationException ex)
            {
                Console.WriteLine("Invalid patient info: " + ex.Message);
            }
            catch (RepositoryException ex)
            {
                Console.WriteLine("Repository error: " + ex.Message);
            }
        }

        public void AddAppointment()
        {
            try
            {
                string id = Input("Appointment ID = ");
                string patientId = Input("Patient ID = ");
                string diagnostic = Input("Diagnostic = ");
                bool isEmergency = bool.Parse(Input("Is emergency? (true/false) = "));

                familyDoctorManager.AddAppointment(id, patientId, diagnostic, isEmergency);
            }
            catch (ValidationException ex)
            {
                Console.WriteLine("Invalid appointment info: " + ex.Message);
            }
            catch (RepositoryException ex)
            {
                Console.WriteLine("Repository error: " + ex.Message);
            }
        }

        private void ListPatients()
        {
            List<Patient> patients = familyDoctorManager.GetAllPatients();
            foreach (Patient patient in patients)
                Console.WriteLine(patient);
        }

        private void ListAppointments()
        {
            List<Appointment> appointments = familyDoctorManager.GetAllAppointments();
            foreach (Appointment appointment in appointments)
                Console.WriteLine(appointment);
        }

        private void ListAppointmentsOfPatient()
        {
            string patientId = Input("Patient ID = ");
            Patient patient = familyDoctorManager.GetPatientByID(patientId);
            string appointments = "";
            /*
            List<Appointment> appointments = familyDoctorManager.GetAllAppointments();
            foreach (Appointment appointment in appointments)
                if (appointment.PatientID == patientId)
                    Console.WriteLine(appointment);
            */

            foreach (string appointmentID in patient.AppointmentIDs)
                appointments += appointmentID + ", ";

            Console.WriteLine(appointments);    
        }
    }
}
