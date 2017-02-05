using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
using System.Threading;

using FamilyDoctor.Domain;

namespace FamilyDoctor.Repository
{
    public class PatientRepository : AbstractRepository<Patient>
    {
        public int PatientsCount { get { return entities.Count; } }

        public virtual void Add(Patient patient)
        {
            entities.Add(patient);

            Log.WriteLine("Patient added: " + patient.ToString());
        }

        public virtual void Delete(Patient patient)
        {
            entities.Remove(patient);

            Log.WriteLine("Patient removed: " + patient.ToString());
        }
        
        public virtual void AddAppointment(string appointmentID, string patientID)
        {
            Patient patient = entities.Find(P => P.ID == patientID);
            patient.AppointmentIDs.Add(appointmentID);

            Log.WriteLine("Associated appointment '" + appointmentID + "' with patient '" + patientID + "'");
        }

        public Patient GetByID(string id)
        {
            Patient patient;
            patient = entities.Find(P => P.ID == id);

            if (patient != null)
                return patient;
            return null;
        }

        public bool Contains(string id)
        {
            return entities.Find(P => P.ID == id) != null;
        }
    }

    public class PatientRepositoryFile : PatientRepository
    {
        string path;
        RepositoryFileFormat format;

        public PatientRepositoryFile(string path, RepositoryFileFormat format)
        {
            this.path = path;
            this.format = format;

            Load();
        }

        private void Load()
        {
            if (File.Exists(path) == false)
            {
                Log.WriteLine("File '" + path + "' does not exist");
                return;
            }

                switch (format)
            {
                case RepositoryFileFormat.XML:
                    LoadXML_Serialization();
                    break;

                default:
                case RepositoryFileFormat.CSV:
                    LoadCSV();
                    break;
            }

            Log.WriteLine("Loaded patients from '" + path + "'");
        }

        private void Save()
        {
            switch (format)
            {
                case RepositoryFileFormat.XML:
                    SaveXML_Serialization();
                    break;

                default:
                case RepositoryFileFormat.CSV:
                    SaveCSV();
                    break;
            }

            Log.WriteLine("Saved patients to '" + path + "'");
        }

        private void LoadXML_Serialization()
        {
            XmlSerializer xs = new XmlSerializer(typeof(List<Patient>));
            StreamReader sr = new StreamReader(path);

            entities = (List<Patient>)xs.Deserialize(sr);
            sr.Close();
        }

        private void SaveXML_Serialization()
        {
            XmlSerializer xs = new XmlSerializer(typeof(List<Patient>));
            StreamWriter sw = new StreamWriter(path);

            xs.Serialize(sw, entities);
            sw.Close();
        }

        private void LoadXML_Manual()
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(path);
            XmlNodeList nodes = doc.SelectNodes("/ListOfPatient/Patient");

            try {
                foreach (XmlNode nodePatient in nodes)
                {
                    Patient patient = new Patient();
                    patient.ID = nodePatient["ID"].InnerText;
                    patient.Name = nodePatient["Name"].InnerText;
                    patient.Age = int.Parse(nodePatient["Age"].InnerText);
                    
                    XmlNodeList nodesAppointmentIDs = nodePatient["AppointmentIDs"].SelectNodes("string");
                    foreach (XmlNode nodeAppointmentID in nodesAppointmentIDs)
                    {
                        string appointmentID = nodeAppointmentID.InnerText;
                        patient.AppointmentIDs.Add(appointmentID);
                    }

                    entities.Add(patient);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private void SaveXML_Manual()
        {
            XmlDocument doc = new XmlDocument();
            XmlDeclaration xmlDeclaration = doc.CreateXmlDeclaration("1.0", "UTF-8", null);
            XmlElement root = doc.CreateElement("ListOfPatient");

            doc.AppendChild(xmlDeclaration);
            doc.AppendChild(root);

            foreach (Patient patient in entities)
            {
                XmlElement elPatient = doc.CreateElement("Patient");
                XmlElement elPatientAppointments = doc.CreateElement("AppointmentIDs");

                AddSubnode(doc, elPatient, "ID", patient.ID);
                AddSubnode(doc, elPatient, "Name", patient.Name);
                AddSubnode(doc, elPatient, "Age", patient.Age.ToString());

                foreach (string appointmentID in patient.AppointmentIDs)
                    AddSubnode(doc, elPatientAppointments, "string", appointmentID);

                elPatient.AppendChild(elPatientAppointments);
                root.AppendChild(elPatient);
            }

            doc.Save(path);
        }

        private void AddSubnode(XmlDocument document, XmlElement parent, string name, string text)
        {
            XmlElement node = document.CreateElement(name);
            node.InnerText = text;
            parent.AppendChild(node);
        }

        private void LoadCSV()
        {
            string[] lines = File.ReadAllLines(path);
            foreach (string line in lines)
            {
                string[] cells = line.Split(',');
                Thread.CurrentThread.IsBackground = true;
                Patient patient = new Patient(cells[0], cells[1], int.Parse(cells[2]));
                entities.Add(patient);
                Log.WriteLine("Added patient from file ('" + path + "'): " + patient.ToString());
            }
        }

        private void SaveCSV()
        {
            StreamWriter sw = new StreamWriter(path);

            new Thread(() =>
            {
                foreach (Patient patient in entities)
                    sw.WriteLine(patient.ID + "," + patient.Name + "," + patient.Age);

                sw.Close();
                sw.Dispose();
            }).Start();
        }

        public override void Add(Patient patient)
        {
            base.Add(patient);
            Save();
        }

        public override void Delete(Patient patient)
        {
            base.Delete(patient);
            Save();
        }

        public override void AddAppointment(string appointmentID, string patientID)
        {
            base.AddAppointment(appointmentID, patientID);
            Save();
        }
    }
}
