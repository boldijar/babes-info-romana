using System.Linq;
using System.Collections.Generic;
using System.Xml.Serialization;
using System.IO;
using System.Threading;

using ClerkOffice.Utils;

namespace ClerkOffice.Repositories
{
    public class Repository<T>
    {
        List<T> entities = new List<T>();
        string filename;

        protected List<T> Entities
        {
            get { return entities; }
            set { entities = value; }
        }

        public string FileName
        {
            get { return filename; }
            set { filename = value; }
        }

        public Repository(string filename)
        {
            this.filename = filename;
            Load();
        }

        public virtual void Add(T entity)
        {
            string entityType = entity.GetType().ToString().Split('.').Last();
            entities.Add(entity);
            Log.WriteLine("Added a " + entityType + ": " + entity);

            Save();
        }

        public virtual void Remove(T entity)
        {
            string entityType = entity.GetType().ToString().Split('.').Last();
            entities.Remove(entity);
            Log.WriteLine("Removed a " + entityType + ": " + entity);

            Save();
        }

        public List<T> GetAll()
        {
            return entities;
        }

        public void Clear()
        {
            entities.Clear();
        }

        public void Save()
        {
            new Thread(() =>
                {
                    XmlSerializer xs = new XmlSerializer(typeof(List<T>));
                    StreamWriter sw = new StreamWriter(filename);

                    xs.Serialize(sw, Entities);
                    sw.Close();
                }).Start();
        }

        public void Load()
        {
            new Thread(() =>
                {
                    if (!File.Exists(filename))
                        return;

                    XmlSerializer xs = new XmlSerializer(typeof(List<T>));
                    StreamReader sr = new StreamReader(filename);

                    Entities = (List<T>)xs.Deserialize(sr);
                    sr.Close();
                }).Start();
        }
    }
}
