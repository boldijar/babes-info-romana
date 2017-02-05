package familydoctor.mock;

import familydoctor.model.Appointment;
import familydoctor.model.Patient;

public class MockFactory {

    public static final String JONSNOW_ID = "js";
    public static final String JONSNOW_NAME = "Jon Snow";
    public static final String JONSNOW_DIAGNOSTIC = "Knows nothing";
    public static final int JONSNOW_AGE = 20;
    public static final boolean JONSNOW_EMERGENCY = true;

    public static Patient createJonSnowPatient() {
        Patient patient = new Patient();

        patient.setId(JONSNOW_ID);
        patient.setName(JONSNOW_NAME);
        patient.setAge(JONSNOW_AGE);

        return patient;
    }

    public static Appointment createJonSnowAppointment() {
        Appointment appointment = new Appointment();

        appointment.setId(JONSNOW_ID);
        appointment.setPatientId(JONSNOW_ID);
        appointment.setDiagnostic(JONSNOW_DIAGNOSTIC);
        appointment.setIsEmergency(JONSNOW_EMERGENCY);

        return appointment;
    }
}