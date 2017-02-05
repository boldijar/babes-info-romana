using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;

using FamilyDoctor.Models;
using FamilyDoctor.Repositories;
using FamilyDoctor.Utils;

namespace FamilyDoctor.Controllers
{
    public class ManagerController : Controller
    {
        FamilyDoctorManager manager;

        public ActionResult Index()
        {
            manager = new FamilyDoctorManager();
            manager.PatientRepository = new PatientRepository("patients.xml");
            manager.AppointmentRepository = new AppointmentRepository("appointments.xml");

            HandleApiRequests();

            return View();
        }

        void HandleApiRequests()
        {
            string response;

            switch (Request.Form["command"])
            {
                case "addpatient":
                    response = AddPatient();
                    break;

                case "addappointment":
                    response = AddAppointment();
                    break;

                case "removepatient":
                    response = RemovePatient();
                    break;

                case "listpatients":
                    response = ListPatients();
                    break;

                case "listappointments":
                    response = ListAppointments();
                    break;

                default:
                    response = "Invalid request";
                    break;
            }
            Console.WriteLine(response);
            Response.Write(response);
        }

        string AddPatient()
        {
            string message;
            string id, name;
            int age;

            try
            {
                id = Request.Form["id"];
                name = Request.Form["name"];
                age = int.Parse(Request.Form["age"]);

                manager.AddPatient(id, name, age);
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

        string AddAppointment()
        {
            string message;
            string appointmentID, patientID, diagnostic;
            bool isEmergency;
            DateTime date;

            try
            {
                appointmentID = Request.Form["appointmentID"];
                patientID = Request.Form["patientID"];
                diagnostic = Request.Form["diagnostic"];
                date = DateTime.Parse(Request.Form["date"]);
                isEmergency = bool.Parse(Request.Form["isEmergency"]);

                manager.AddAppointment(appointmentID, patientID, diagnostic, date, isEmergency);
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

        string RemovePatient()
        {
            string message;
            string id;

            try
            {
                id = Request.Form["id"];

                manager.RemovePatient(id);
                message = "Patient removed sucessfully";
            }
            catch (RepositoryException re)
            {
                message = "Repository error: " + re.Message;
                Log.WriteWarning(message);
            }

            return message;
        }

        string RemoveAppointment()
        {
            string message;
            string id;

            try
            {
                id = Request.Form["id"];

                manager.RemoveAppointment(id);
                message = "Appointment removed sucessfully";
            }
            catch (RepositoryException re)
            {
                message = "Repository error: " + re.Message;
                Log.WriteWarning(message);
            }

            return message;
        }

        string ListPatients()
        {
            string message = "";
            string criteria, value;

            List<Patient> patients = manager.GetAllPatients();

            criteria = Request.Form["criteria"];

            if (criteria != "all")
            {
                value = Request.Form["value"];

                switch (criteria)
                {
                    case "id":
                        patients = patients.FindAll(P => P.ID == value);
                        break;

                    case "age-eq":
                        patients = patients.FindAll(P => P.Age == int.Parse(value));
                        break;

                    case "age-lt":
                        patients = patients.FindAll(P => P.Age < int.Parse(value));
                        break;

                    case "age-gt":
                        patients = patients.FindAll(P => P.Age > int.Parse(value));
                        break;
                }
            }

            foreach (Patient patient in patients)
                message += patient + Environment.NewLine;

            return message;
        }

        string ListAppointments()
        {
            string message = "";
            string criteria, value;

            List<Appointment> appointments = manager.GetAllAppointments();

            criteria = Request.Form["criteria"];

            if (criteria != "all")
            {
                value = Request.Form["value"];

                switch (criteria)
                {
                    case "id":
                        appointments = appointments.FindAll(A => A.ID == value);
                        break;

                    case "patientid":
                        appointments = appointments.FindAll(A => A.PatientID == value);
                        break;

                    case "diagnostic":
                        appointments = appointments.FindAll(A => A.Diagnostic == value);
                        break;

                    case "emergency":
                        appointments = appointments.FindAll(A => A.IsEmergency == bool.Parse(value));
                        break;

                    case "date-eq":
                        appointments = appointments.FindAll(A => A.Date == DateTime.Parse(value));
                        break;

                    case "date-lt":
                        appointments = appointments.FindAll(A => A.Date < DateTime.Parse(value));
                        break;

                    case "date-gt":
                        appointments = appointments.FindAll(A => A.Date > DateTime.Parse(value));
                        break;
                }
            }

            foreach (Appointment appointment in appointments)
                message += appointment + Environment.NewLine;

            return message;
        }
    }
}
