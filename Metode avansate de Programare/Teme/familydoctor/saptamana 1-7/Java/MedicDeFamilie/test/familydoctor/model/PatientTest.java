package familydoctor.model;

import familydoctor.mock.MockFactory;
import junit.framework.TestCase;

public class PatientTest extends TestCase{
    public void testCreate(){
        Patient patient = MockFactory.createJonSnowPatient();

        assertEquals(MockFactory.JONSNOW_ID, patient.getId());
        assertEquals(MockFactory.JONSNOW_NAME, patient.getName());
        assertEquals(MockFactory.JONSNOW_AGE, patient.getAge());
    }
}