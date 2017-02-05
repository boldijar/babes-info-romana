package familydoctor;

import familydoctor.repository.AppointmentRepositoryFile;
import familydoctor.repository.PatientRepositoryFile;
import familydoctor.service.FamilyDoctorManager;
import familydoctor.ui.FamilyDoctorUI;

public class FamilyDoctorApp {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Name parameter is invalid.");
            System.exit(1);
        }

        try {
            FamilyDoctorUI familyDoctorUI = new FamilyDoctorUI();
            FamilyDoctorManager familyDoctorManager = new FamilyDoctorManager();
            familyDoctorUI.setFamilyDoctorManager(familyDoctorManager);
            familyDoctorManager.setPacientRepository(new PatientRepositoryFile("patients.xml"));
            familyDoctorManager.setAppointmentRepository(new AppointmentRepositoryFile("appointments.xml"));
            familyDoctorUI.showUI();
        } catch (Exception e) {
            System.out.println("The App has encountered an error. Sorry.");
        }

    }

}
