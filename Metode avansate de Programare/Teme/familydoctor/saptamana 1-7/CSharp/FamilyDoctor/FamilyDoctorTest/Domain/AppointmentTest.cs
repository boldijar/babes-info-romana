using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using FamilyDoctor.Domain;

namespace FamilyDoctorTest
{
    class AppointmentTest
    {
        const string JONSNOWAPMT_ID = "jonapmt";
        const string JONSNOWAPMT_PATIENTID = "jon";
        const string JONSNOWAPMT_DIAGNOSTIC = "Knows nothing!";
        const bool JONSNOWAPMT_ISEMERGENCY = false;

        [TestMethod]
        public void TestCreateAppointment()
        {
            Appointment appointment = new Appointment();
            appointment.ID = JONSNOWAPMT_ID;
            appointment.PatientID = JONSNOWAPMT_PATIENTID;
            appointment.Diagnostic = JONSNOWAPMT_DIAGNOSTIC;
            appointment.IsEmergency = JONSNOWAPMT_ISEMERGENCY;

            Assert.AreEqual(appointment.ID, JONSNOWAPMT_ID);
            Assert.AreEqual(appointment.PatientID, JONSNOWAPMT_PATIENTID);
            Assert.AreEqual(appointment.Diagnostic, JONSNOWAPMT_DIAGNOSTIC);
            Assert.AreEqual(appointment.IsEmergency, JONSNOWAPMT_ISEMERGENCY);
        }
    }
}
