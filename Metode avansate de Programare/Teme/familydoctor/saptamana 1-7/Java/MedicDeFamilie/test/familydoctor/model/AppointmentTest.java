package familydoctor.model;

import familydoctor.mock.MockFactory;
import junit.framework.TestCase;

public class AppointmentTest extends TestCase {
    public void testCreate() {
        Appointment appointment = MockFactory.createJonSnowAppointment();

        assertEquals(MockFactory.JONSNOW_ID, appointment.getId());
        assertEquals(MockFactory.JONSNOW_ID, appointment.getPatientId());
        assertEquals(MockFactory.JONSNOW_DIAGNOSTIC, appointment.getDiagnostic());
        assertEquals(MockFactory.JONSNOW_EMERGENCY, appointment.getIsEmergency());
    }
}