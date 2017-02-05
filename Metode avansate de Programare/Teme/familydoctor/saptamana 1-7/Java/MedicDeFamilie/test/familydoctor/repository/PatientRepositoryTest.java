package familydoctor.repository;

import familydoctor.model.Patient;
import junit.framework.TestCase;
import familydoctor.mock.MockFactory;

public class PatientRepositoryTest extends TestCase {
    public void testGetById(){
        PatientRepository patientRepository = new PatientRepository();

        Patient jonSnow = MockFactory.createJonSnowPatient();
        patientRepository.add(jonSnow);
        Patient patient = patientRepository.getById(MockFactory.JONSNOW_ID);

        assertEquals(MockFactory.createJonSnowPatient(), patient);
    }
}