using System;
using System.Collections.Generic;

using FamilyDoctor.Models;
using FamilyDoctor.Repositories;

namespace FamilyDoctor.Controllers
{
    class FamilyDoctorManager
    {
        PatientRepository patientRepository;
        AppointmentRepository appointmentRepository;

        public PatientRepository PatientRepository
        {
            set { patientRepository = value; }
        }

        public AppointmentRepository AppointmentRepository
        {
            set { appointmentRepository = value; }
        }

        public Patient AddPatient(string id, string name, int age)
        {
            Patient patient = new Patient();

            patient.ID = id;
            patient.Name = name;
            patient.Age = age;

            patientRepository.Add(patient);
            return patient;
        }

        public Appointment AddAppointment(string id, string patientId, string diagnostic, DateTime date, bool isEmergency)
        {
            if (!patientRepository.Contains(patientId))
                throw new RepositoryException("Specified patient does not exist");
            
            Appointment appointment = new Appointment();

            appointment.ID = id;
            appointment.PatientID = patientId;
            appointment.Diagnostic = diagnostic;
            appointment.Date = date;
            appointment.IsEmergency = isEmergency;
            
            appointmentRepository.Add(appointment);
            patientRepository.AddAppointment(id, patientId);

            return appointment;
        }

        public void RemovePatient(string id)
        {
            Patient patient = patientRepository.GetByID(id);
            patientRepository.Remove(patient);

            foreach (string appointmentID in patient.AppointmentIDs)
                RemoveAppointment(appointmentID);
        }

        public void RemoveAppointment(string id)
        {
            Appointment appointment = appointmentRepository.GetByID(id);
            appointmentRepository.Remove(appointment);
        }

        public Patient GetPatientByID(string id)
        {
            return patientRepository.GetByID(id);
        }

        public Appointment GetAppointmentByID(string id)
        {
            return appointmentRepository.GetByID(id);
        }

        public List<Patient> GetAllPatients()
        {
            return patientRepository.GetAll();
        }

        public List<Appointment> GetAllAppointments()
        {
            return appointmentRepository.GetAll();
        }
    }
}
