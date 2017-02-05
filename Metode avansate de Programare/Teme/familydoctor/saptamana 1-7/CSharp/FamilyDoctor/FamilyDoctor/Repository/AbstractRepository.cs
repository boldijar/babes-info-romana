using System;
using System.Collections.Generic;

namespace FamilyDoctor.Repository
{
    public enum RepositoryFileFormat
    {
        XML,
        CSV
    }

    public class AbstractRepository<T>
    {
        protected List<T> entities = new List<T>();

        public List<T> GetAll()
        {
            return entities;
        }
    }
}