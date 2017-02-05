package familydoctor.repository;

import familydoctor.model.Appointment;

import java.util.stream.Collectors;

public class AppointmentRepository extends AbstractRepository<Appointment> {
    public void add(Appointment appointment) {
        entities.add(appointment);
    }

    public void remove(Appointment appointment) {
        entities.remove(appointment);
    }

    public Appointment getById(String id) {
        return entities.stream().filter(A -> A.getId() == id).collect(Collectors.toList()).get(0);
    }

    public boolean contains(String id) {
        return getById(id) != null;

    }
}
