package familydoctor.service;

import familydoctor.model.Appointment;
import familydoctor.model.Patient;
import familydoctor.repository.AppointmentRepositoryFile;
import familydoctor.repository.PatientRepositoryFile;
import familydoctor.repository.RepositoryException;

import java.util.List;

public class FamilyDoctorManager {
    private PatientRepositoryFile patientRepository;
    private AppointmentRepositoryFile appointmentRepository;

    public void setPacientRepository(PatientRepositoryFile patientRepository) {
        this.patientRepository = patientRepository;
    }

    public void setAppointmentRepository(AppointmentRepositoryFile appointmentRepository) {
        this.appointmentRepository = appointmentRepository;
    }

    public Patient addPatient(String id, String name, int age) {
        Patient patient = new Patient();
        patient.setId(id);
        patient.setName(name);
        patient.setAge(age);

        patient.validate();

        patientRepository.add(patient);
        return patient;
    }

    public Appointment addAppointment(String id, String patientId, String diagnostic, boolean isEmergency) {
        if(patientRepository.contains(patientId) == false)
            throw new RepositoryException("Specified patient does not exist");

        Appointment appointment = new Appointment();
        appointment.setId(id);
        appointment.setPatientId(patientId);
        appointment.setDiagnostic(diagnostic);
        appointment.setIsEmergency(isEmergency);

        appointment.validate();

        appointmentRepository.add(appointment);
        return appointment;
    }

    public Patient GetPatientByID(String id) {
        return patientRepository.getById(id);
    }

    public Appointment GetAppointmentByID(String id) {
        return appointmentRepository.getById(id);
    }

    public List<Patient> GetAllPatients() {
        return patientRepository.getAll();
    }

    public List<Appointment> GetAllAppointments() {
        return appointmentRepository.getAll();
    }

    public void AddAppointmentToPatient(String appointmentId, String patientId) {
        if (appointmentRepository.contains(appointmentId)) {
            Patient patient = patientRepository.getById(patientId);
            //patient.addAppointment(appointmentId);
        }
    }
}