using System;
using System.Collections.Generic;
using System.Linq;

using FamilyDoctor.Service;
using FamilyDoctor.Models;
using FamilyDoctor.Controllers;
using FamilyDoctor.Repositories;
using FamilyDoctor.Utils;

namespace FamilyDoctor.Service
{
    class CommandService : ICommandService
    {
        readonly FamilyDoctorManager manager;

        public CommandService(FamilyDoctorManager manager)
        {
            this.manager = manager;
        }

        public string ExecuteCommand(string command)
        {
            string[] cmd = command.Split('|');
            string response;

            Log.WriteLine("Received command: " + command.Replace(' ', '_').Replace('|', ' '));

            try
            {
                switch (cmd[0])
                {
                    case "addpatient":
                        response = AddPatient(cmd.Skip(1).ToArray());
                        break;

                    case "addappointment":
                        response = AddAppointment(cmd.Skip(1).ToArray());
                        break;

                    case "removepatient":
                        response = RemovePatient(cmd.Skip(1).ToArray());
                        break;

                    case "listpatients":
                        response = ListPatients(cmd.Skip(1).ToArray());
                        break;

                    case "listappointments":
                        response = ListAppointments(cmd.Skip(1).ToArray());
                        break;

                    default:
                        Console.WriteLine("Invalid command");
                        response = "INVALID COMMAND";
                        break;
                }
            }
            catch (Exception ex)
            {
                response = "Exception: " + ex.Message;
                Log.WriteWarning(response);
            }

            return response;
        }

        string AddPatient(params string[] list)
        {
            string message;

            try
            {
                manager.AddPatient(list[0], list[1], int.Parse(list[2]));
                message = "Patient added sucessfully";
            }
            catch (ValidationException ve)
            {
                message = "Invalid content: " + ve.Message;
                Log.WriteWarning(message); 
            }
            catch (RepositoryException re)
            {
                message = "Repository error: " + re.Message;
                Log.WriteWarning(message);
            }

            return message;
        }

        string AddAppointment(params string[] list)
        {
            string message;

            try
            {
                manager.AddAppointment(list[0], list[1], list[2], DateTime.Parse(list[3]), bool.Parse(list[4]));
                message = "Appointment added sucessfully";
            }
            catch (ValidationException ve)
            {
                message = "Invalid content: " + ve.Message;
                Log.WriteWarning(message);
            }
            catch (RepositoryException re)
            {
                message = "Repository error: " + re.Message;
                Log.WriteWarning(message);
            }

            return message;
        }

        string RemovePatient(params string[] list)
        {
            string message;

            try
            {
                manager.RemovePatient(list[0]);
                message = "Patient removed sucessfully";
            }
            catch (RepositoryException re)
            {
                message = "Repository error: " + re.Message;
                Log.WriteWarning(message);
            }

            return message;
        }

        string RemoveAppointment(params string[] list)
        {
            string message;

            try
            {
                manager.RemoveAppointment(list[0]);
                message = "Appointment removed sucessfully";
            }
            catch (RepositoryException re)
            {
                message = "Repository error: " + re.Message;
                Log.WriteWarning(message);
            }

            return message;
        }

        string ListPatients(params string[] list)
        {
            string message = "";

            List<Patient> patients = manager.GetAllPatients();

            if (list.Length >= 2)
            {
                switch (list[0])
                {
                    case "id":
                        patients = patients.FindAll(P => P.ID == list[1]);
                        break;

                    case "age-eq":
                        patients = patients.FindAll(P => P.Age == int.Parse(list[1]));
                        break;

                    case "age-lt":
                        patients = patients.FindAll(P => P.Age < int.Parse(list[1]));
                        break;

                    case "age-gt":
                        patients = patients.FindAll(P => P.Age > int.Parse(list[1]));
                        break;
                }
            }

            foreach (Patient patient in patients)
                message += patient + Environment.NewLine;

            return message;
        }

        string ListAppointments(params string[] list)
        {
            string message = "";

            List<Appointment> appointments = manager.GetAllAppointments();

            if (list.Length >= 2)
            {
                switch (list[0])
                {
                    case "id":
                        appointments = appointments.FindAll(A => A.ID == list[1]);
                        break;

                    case "patientid":
                        appointments = appointments.FindAll(A => A.PatientID == list[1]);
                        break;

                    case "diagnostic":
                        appointments = appointments.FindAll(A => A.Diagnostic == list[1]);
                        break;

                    case "emergency":
                        appointments = appointments.FindAll(A => A.IsEmergency == bool.Parse(list[1]));
                        break;

                    case "date-eq":
                        appointments = appointments.FindAll(A => A.Date == DateTime.Parse(list[1]));
                        break;

                    case "date-lt":
                        appointments = appointments.FindAll(A => A.Date < DateTime.Parse(list[1]));
                        break;

                    case "date-gt":
                        appointments = appointments.FindAll(A => A.Date > DateTime.Parse(list[1]));
                        break;
                }
            }

            foreach (Appointment appointment in appointments)
                message += appointment + Environment.NewLine;

            return message;
        }
    }
}