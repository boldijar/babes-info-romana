package familydoctor.model;

import java.util.List;

public class Patient {
    private String id, name;
    private int age;
    private List<Appointment> appointments;

    public Patient() {

    }

    public Patient(String id, String name, int age) {
        this.id = id;
        this.name = name;
        this.age = age;

        validate();
    }

    public String getId() { return id; }
    public void setId(String value) {
        id = value;
    }

    public String getName() {
        return name;
    }
    public void setName(String value) {
        name = value;
    }

    public int getAge() {
        return age;
    }
    public void setAge(int value) {
        age = value;
    }

    public void validate()
    {
        if (id == null || id == "")
            throw new ValidationException("Invalid ID");

        if (name == null || name == "")
            throw new ValidationException("Invalid name");

        if (age < 0)
            throw new ValidationException("Invalid age");
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;

        if (obj == null)
            return false;

        if (getClass() != obj.getClass())
            return false;

        Patient other = (Patient) obj;
        if (id == null) {
            if (other.id != null)
                return false;
        } else if (!id.equals(other.id))
            return false;

        return true;
    }



}