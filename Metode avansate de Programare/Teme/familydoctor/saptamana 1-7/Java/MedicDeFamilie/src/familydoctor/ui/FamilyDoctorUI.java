package familydoctor.ui;

import familydoctor.model.Appointment;
import familydoctor.model.Patient;
import familydoctor.model.ValidationException;
import familydoctor.repository.RepositoryException;
import familydoctor.service.FamilyDoctorManager;

import java.util.List;
import java.util.Scanner;

public final class FamilyDoctorUI {
    private FamilyDoctorManager familyDoctorManager;

    public void setFamilyDoctorManager(FamilyDoctorManager familyDoctorManager) {
        this.familyDoctorManager = familyDoctorManager;
    }

    private String input(String prompt) {
        Scanner input = new Scanner(System.in);
        System.out.print(prompt);
        return input.nextLine();
    }

    public void printCommands() {
        System.out.println("1. Add patient");
        System.out.println("2. Add appointment");
        System.out.println("3. List patients");
        System.out.println("4. List appointments");
        System.out.println("5. List appointments of patient");
        System.out.println("0. Exit");
    }

    public void showUI() {
        String cmd = "";
        boolean isRunning = true;

        while (isRunning) {
            printCommands();

            cmd = input("Enter command: ");
            System.out.println();

            switch (cmd) {
                case "1":
                    createPatient();
                    break;

                case "2":
                    createAppointment();
                    break;

                case "3":
                    listPatients();
                    break;

                case "4":
                    listAppointments();
                    break;

                case "5":
                    listAppointmentsOfPatient();
                    break;

                case "0":
                    System.out.println("Bye");
                    isRunning = false;
                    break;

                default:
                    System.out.println("Invalid command!");
                    break;
            }
            System.out.println("\n--------------");

            if (cmd == "0" || isRunning == false)
                break;
        }
    }

    private void createPatient() {
        try {
            String id = input("Patient ID = ");
            String name = input("Patient name = ");
            int age = Integer.parseInt(input("Patient age = "));

            Patient patient = familyDoctorManager.addPatient(id, name, age);

            System.out.println("Patient created: " + patient.getId());
        }
        catch (ValidationException ex) {
            System.out.println("Invalid patient info: " + ex.getMessage());
        }
        catch (RepositoryException ex) {
            System.out.println("Repository error: " + ex.getMessage());
        }
    }

    private void createAppointment() {
        try {
            String id = input("Appointment ID = ");
            String patientId = input("Patient ID = ");
            String diagnostic = input("Diagnostic = ");
            boolean isEmergency = Boolean.parseBoolean(input("Is emergency? (true/false) = "));

            Appointment appointment = familyDoctorManager.addAppointment(id, patientId, diagnostic, isEmergency);

            System.out.println("Appointment created: " + appointment.getId());
        }
        catch (ValidationException ex) {
            System.out.println("Invalid appointment info: " + ex.getMessage());
        }
        catch (RepositoryException ex) {
            System.out.println("Repository exception: " + ex.getMessage());
        }
    }

    private void listPatients() {
        List<Patient> patients = familyDoctorManager.GetAllPatients();
        for(int i = 0; i < patients.size(); i++)
        {
            Patient patient = patients.get(i);
            System.out.println(patient.getId());
        }
    }

    private void listAppointments() {
        List<Appointment> appointments = familyDoctorManager.GetAllAppointments();
        for(int i = 0; i < appointments.size(); i++)
        {
            Appointment appointment = appointments.get(i);
            System.out.println(appointment.getId());
        }
    }

    private void listAppointmentsOfPatient() {
        String patientId = input("Patient ID = ");

        List<Appointment> appointments = familyDoctorManager.GetAllAppointments();
        for(int i = 0; i < appointments.size(); i++)
        {
            Appointment appointment = appointments.get(i);
            if(appointment.getPatientId() == patientId)
                System.out.println(appointment.getId());
        }
    }
}