using FamilyDoctor.Net;
using FamilyDoctor.Service;
using FamilyDoctor.Controllers;
using FamilyDoctor.Repositories;

namespace FamilyDoctor
{
    class Program
    {
        static void Main()
        {
            FamilyDoctorManager man = new FamilyDoctorManager();
            man.PatientRepository = new PatientRepository("patients.xml");
            man.AppointmentRepository = new AppointmentRepository("appointments.xml");

            TcpServer tcpServer = new TcpServer();
            tcpServer.CommandService = new CommandService(man);
            tcpServer.Start();
        }
    }
}
