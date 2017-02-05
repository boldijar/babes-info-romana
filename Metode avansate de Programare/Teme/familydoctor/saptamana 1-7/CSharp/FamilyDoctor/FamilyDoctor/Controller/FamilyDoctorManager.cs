using System;
using System.Collections.Generic;

using FamilyDoctor.Domain;
using FamilyDoctor.Repository;

namespace FamilyDoctor.Controller
{
    class FamilyDoctorManager
    {
        private PatientRepository patientRepository;
        private AppointmentRepository appointmentRepository;

        public PatientRepository PatientRepository { set { patientRepository = value; } }
        public AppointmentRepository AppointmentRepository { set { appointmentRepository = value; } }

        public Patient AddPatient(string id, string name, int age)
        {
            Patient patient = new Patient();
            patient.ID = id;
            patient.Name = name;
            patient.Age = age;

            patient.Validate();

            patientRepository.Add(patient);
            return patient;
        }

        public Appointment AddAppointment(string id, string patientId, string diagnostic, bool isEmergency)
        {
            if (patientRepository.Contains(patientId) == false)
                throw new RepositoryException("Specified patient does not exist");
            
            Appointment appointment = new Appointment();
            appointment.ID = id;
            appointment.PatientID = patientId;
            appointment.Diagnostic = diagnostic;
            appointment.IsEmergency = isEmergency;

            appointment.Validate();
            
            appointmentRepository.Add(appointment);
            patientRepository.AddAppointment(id, patientId);
            return appointment;
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
