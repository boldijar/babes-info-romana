package familydoctor.repository;

import familydoctor.model.Appointment;

import java.beans.XMLEncoder;
import java.beans.XMLDecoder;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class AppointmentRepositoryFile extends AppointmentRepository {
    private String filePath;

    public AppointmentRepositoryFile(String filePath) {
        this.filePath = filePath;

        if (Files.exists(Paths.get(filePath)))
            Load();
    }

    public void Load() {
        XMLDecoder decoder=null;
        try {
            decoder = new XMLDecoder(new BufferedInputStream(new FileInputStream(filePath)));
        } catch (FileNotFoundException e) {
            System.out.println("ERROR: File '" + filePath + "' not found");
        }
        entities = (List<Appointment>)decoder.readObject();
    }

    public void Save() {
        XMLEncoder encoder=null;
        try {
            encoder=new XMLEncoder(new BufferedOutputStream(new FileOutputStream(filePath)));
        } catch(FileNotFoundException fileNotFound) {
            System.out.println("ERROR: While Creating or Opening the File '" + filePath + "'");
        }
        encoder.writeObject(entities);
        encoder.close();
    }

    public void LoadOLD() {
        File file = new File(filePath);
        if(file.exists() && !file.isDirectory())
        {
            try {
                List<String> lines = Files.readAllLines(Paths.get(filePath));
                for (int i = 0; i < lines.size(); i++) {
                    String line = lines.get(i);
                    String[] cells = line.split(",");
                    Appointment appointment = new Appointment(cells[0], cells[1], cells[2], Boolean.parseBoolean(cells[3]));
                    entities.add(appointment);
                }
            } catch (IOException ex) {

            }
        }
    }

    public void SaveOLD() {
        Thread t1 = new Thread(new Runnable() {
            public void run() {
                try {
                    FileWriter writer = new FileWriter(filePath);

                    for (int i = 0; i < entities.size(); i++) {
                        Appointment appointment = entities.get(i);
                        writer.write(
                                appointment.getId() + "," + appointment.getPatientId() + "," +
                                appointment.getDiagnostic() + "," + appointment.getIsEmergency());
                    }
                    writer.close();
                } catch (IOException ex) {

                }
            }
        });
        t1.start();
    }

    public void add(Appointment appointment) {
        super.add(appointment);
        Save();
    }

    public void remove(Appointment appointment) {
        super.remove(appointment);
        Save();
    }
}