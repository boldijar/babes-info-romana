using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
using System.Threading;

using FamilyDoctor.Domain;

namespace FamilyDoctor.Repository
{
    public class AppointmentRepository : AbstractRepository<Appointment>
    {
        public int AppointmentsCount { get { return entities.Count; } }

        public virtual void Add(Appointment appointment)
        {
            entities.Add(appointment);

            Log.WriteLine("Appointment '" + appointment.ID + "' added");
        }

        public virtual void Delete(Appointment appointment)
        {
            entities.Remove(appointment);

            Log.WriteLine("Appointment '" + appointment.ID + "' removed");
        }

        public Appointment GetByID(string id)
        {
            Appointment appointment;
            appointment = entities.Find(A => A.ID == id);

            if (appointment != null)
                return appointment;
            return null;
        }

        public bool Contains(string id)
        {
            return entities.Find(A => A.ID == id) != null;
        }
    }

    public class AppointmentRepositoryFile : AppointmentRepository
    {
        string path;
        RepositoryFileFormat format;

        public AppointmentRepositoryFile(string path, RepositoryFileFormat format)
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

            Log.WriteLine("Loaded appointments from '" + path + "'");
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

            Log.WriteLine("Saved appointments to '" + path + "'");
        }

        private void LoadXML_Serialization()
        {
            XmlSerializer xs = new XmlSerializer(typeof(List<Patient>));
            StreamReader sr = new StreamReader(path);

            entities = (List<Appointment>)xs.Deserialize(sr);
            sr.Close();
        }

        private void SaveXML_Serialization()
        {
            XmlSerializer xs = new XmlSerializer(typeof(List<Appointment>));
            StreamWriter sw = new StreamWriter(path);

            xs.Serialize(sw, entities);
            sw.Close();
        }

        private void LoadXML_Manual()
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(path);
            XmlNodeList nodes = doc.SelectNodes("/ListOfAppointment/Appointment");

            foreach (XmlNode node in nodes)
            {
                Appointment appointment = new Appointment();
                appointment.ID = node["ID"].InnerText;
                appointment.PatientID = node["PatientID"].InnerText;
                appointment.Diagnostic = node["Diagnostic"].InnerText;
                appointment.IsEmergency = bool.Parse(node["IsEmergency"].InnerText);

                entities.Add(appointment);
            }
        }

        private void SaveXML_Manual()
        {
            XmlDocument doc = new XmlDocument();
            XmlDeclaration xmlDeclaration = doc.CreateXmlDeclaration("1.0", "UTF-8", null);
            XmlElement root = doc.CreateElement("ListOfAppointment");

            doc.AppendChild(xmlDeclaration);
            doc.AppendChild(root);

            foreach (Appointment appointment in entities)
            {
                XmlElement el = doc.CreateElement("Appointment");

                AddSubnode(doc, el, "ID", appointment.ID);
                AddSubnode(doc, el, "PatientID", appointment.PatientID);
                AddSubnode(doc, el, "Diagnostic", appointment.Diagnostic);
                AddSubnode(doc, el, "IsEmergency", appointment.IsEmergency.ToString());

                root.AppendChild(el);
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

                Appointment appointment = new Appointment(cells[0], cells[1], cells[2], bool.Parse(cells[3]));
                entities.Add(appointment);
            }
        }

        private void SaveCSV()
        {
            StreamWriter sw = new StreamWriter(path);

            new Thread(() =>
            {
                foreach (Appointment appointment in entities)
                    sw.WriteLine(
                        appointment.ID + "," + appointment.PatientID + "," +
                        appointment.Diagnostic + "," + appointment.IsEmergency);

                sw.Close();
                sw.Dispose();
            }).Start();
        }

        public override void Add(Appointment appointment)
        {
            base.Add(appointment);
            Save();
        }

        public override void Delete(Appointment appointment)
        {
            base.Delete(appointment);
            Save();
        }
    }
}
