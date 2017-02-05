package familydoctor.repository;

import junit.framework.TestCase;
import familydoctor.mock.MockFactory;
import familydoctor.model.Appointment;

public class AppointmentRepositoryTest extends TestCase {
    public void testGetById(){
        AppointmentRepository appointmentRepository = new AppointmentRepository();

        Appointment appointmentJS = MockFactory.createJonSnowAppointment();
        appointmentRepository.add(appointmentJS);
        Appointment appointment = appointmentRepository.getById(MockFactory.JONSNOW_ID);

        assertEquals(MockFactory.createJonSnowAppointment(), appointmentJS);
    }
}