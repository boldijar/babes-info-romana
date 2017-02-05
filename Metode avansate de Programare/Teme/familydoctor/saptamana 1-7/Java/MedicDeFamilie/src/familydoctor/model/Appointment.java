package familydoctor.model;

public class Appointment {
    private String id, patientId, diagnostic;
    private boolean isEmergency;

    public Appointment() {

    }

    public Appointment(String id, String patientId, String diagnostic, boolean isEmergency) {
        this.id = id;
        this.patientId = patientId;
        this.diagnostic = diagnostic;
        this.isEmergency = isEmergency;

        validate();
    }

    public String getId() {
        return id;
    }
    public void setId(String value) {
        id = value;
    }

    public String getPatientId() {
        return patientId;
    }
    public void setPatientId(String value) {
        patientId = value;
    }

    public String getDiagnostic() {
        return diagnostic;
    }
    public void setDiagnostic(String value) {
        diagnostic= value;
    }

    public boolean getIsEmergency() {
        return isEmergency;
    }
    public void setIsEmergency(boolean value) {
        isEmergency = value;
    }

    public void validate()
    {
        if (id == null || id == "")
            throw new ValidationException("Invalid ID");

        if (patientId == null || patientId == "")
            throw new ValidationException("Invalid name");

        if (diagnostic == null || diagnostic == "")
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

        Appointment other = (Appointment) obj;
        if (id == null) {
            if (other.getId() != null)
                return false;
        } else if (!id.equals(other.getId()))
            return false;

        return true;
    }



}