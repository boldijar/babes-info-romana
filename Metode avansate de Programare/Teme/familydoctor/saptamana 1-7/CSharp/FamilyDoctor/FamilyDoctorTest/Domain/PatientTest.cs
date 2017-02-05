using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using FamilyDoctor.Domain;

namespace FamilyDoctorTest
{
    [TestClass]
    public class PatientTest
    {
        const string JONSNOW_ID = "jon";
        const string JONSNOW_NAME = "Jon Snow";
        const int JONSNOW_AGE = 20;

        [TestMethod]
        public void TestCreatePatient()
        {
            Patient patient = new Patient();
            patient.ID = JONSNOW_ID;
            patient.Name = JONSNOW_NAME;
            patient.Age = JONSNOW_AGE;

            Assert.AreEqual(patient.ID, JONSNOW_ID);
            Assert.AreEqual(patient.Name, JONSNOW_NAME);
            Assert.AreEqual(patient.Age, JONSNOW_AGE);
        }
    }
}
