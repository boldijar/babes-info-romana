package familydoctor.repository;

import familydoctor.model.Patient;

import java.beans.XMLEncoder;
import java.beans.XMLDecoder;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class PatientRepositoryFile extends PatientRepository {
    private String filePath;

    public PatientRepositoryFile(String filePath) {
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
        entities = (List<Patient>)decoder.readObject();
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
                    Patient patient = new Patient(cells[0], cells[1], Integer.parseInt(cells[2]));
                    entities.add(patient);
                }
            } catch (IOException ex) {

            }
        }
    }

    public void SaveOLD() {
        try {
            FileWriter writer = new FileWriter(filePath);

            for (int i = 0; i < entities.size(); i++) {
                Patient patient = entities.get(i);
                writer.write(patient.getId() + "," + patient.getName() + "," + patient.getAge());
            }
            writer.close();
        } catch (IOException ex) {

        }
    }

    public void add(Patient patient) {
        super.add(patient);
        Save();
    }

    public void remove(Patient patient) {
        super.remove(patient);
        Save();
    }
}