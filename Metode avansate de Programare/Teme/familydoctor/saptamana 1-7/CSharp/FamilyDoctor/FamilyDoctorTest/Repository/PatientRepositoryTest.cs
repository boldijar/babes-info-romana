using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using FamilyDoctor.Domain;
using FamilyDoctor.Repository;

namespace FamilyDoctorTest
{
    [TestClass]
    public class PatientRepositoryTest
    {
        [TestMethod]
        public void TestCreatePatient()
        {
            PatientRepository patientRepository = new PatientRepository();
            Patient patient1 = new Patient("id1", "name1", 1);

            Assert.AreEqual(patientRepository.PatientsCount, 0);
            
            patientRepository.Add(patient1);

            Assert.AreEqual(patientRepository.PatientsCount, 1);
            Assert.AreEqual(patientRepository.GetByID(patient1.ID), patient1);

            patientRepository.Add(new Patient("id2", "name2", 2));

            Assert.AreEqual(patientRepository.PatientsCount, 2);
        }
    }
}
