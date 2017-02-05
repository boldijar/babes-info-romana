using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using FamilyDoctor.Domain;
using FamilyDoctor.Repository;

namespace FamilyDoctorTest
{
    [TestClass]
    public class AppointmentRepositoryTest
    {
        [TestMethod]
        public void TestCreatePatient()
        {
            AppointmentRepository appointmentRepository = new AppointmentRepository();
            Appointment appointment1 = new Appointment("id1", "patient_id2", "diag1", false);

            Assert.AreEqual(appointmentRepository.AppointmentsCount, 0);

            appointmentRepository.Add(appointment1);

            Assert.AreEqual(appointmentRepository.AppointmentsCount, 1);
            Assert.AreEqual(appointmentRepository.GetByID(appointment1.ID), appointment1);

            appointmentRepository.Add(new Appointment("id2", "patient_id2", "diag2", false));

            Assert.AreEqual(appointmentRepository.AppointmentsCount, 2);
        }
    }
}
