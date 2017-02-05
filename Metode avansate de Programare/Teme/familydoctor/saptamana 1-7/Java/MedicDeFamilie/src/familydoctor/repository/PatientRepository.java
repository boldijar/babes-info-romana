package familydoctor.repository;

import familydoctor.model.Patient;

import java.util.stream.Collectors;

public class PatientRepository extends AbstractRepository<Patient> {
    public void add(Patient patient) {
        entities.add(patient);
    }

    public void remove(Patient patient) {
        entities.remove(patient);
    }

    public Patient getById(String id) {
        return entities.stream().filter(A -> A.getId() == id).collect(Collectors.toList()).get(0);
    }

    public boolean contains(String id) {
        return entities.stream().filter(A -> A.getId() == id).collect(Collectors.toList()).size() != 0;
    }
}
