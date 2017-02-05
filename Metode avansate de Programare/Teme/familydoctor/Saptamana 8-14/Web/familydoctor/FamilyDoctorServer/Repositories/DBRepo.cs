using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Threading;

using FamilyDoctor.Models;

namespace FamilyDoctor.Repositories
{
    public class DBRepo
    {
        public static void AddPatient(Patient patient)
        {
            var connection = DatabaseIns.Instance.GetDatabaseConnection();
            //Here is the 2nd method to insert into table
            string sqlQuery = "Insert Into Patients (ID,Name,Age) values (@ID,@Name,@Age)";
            using (var command = new SqlCommand(sqlQuery, connection))
            {
                command.Parameters.Add(new SqlParameter("@ID", SqlDbType.Int) { Value = patient.ID });
                command.Parameters.Add(new SqlParameter("@Age", SqlDbType.Int) { Value = patient.Age });
                command.Parameters.Add(new SqlParameter("@Name", SqlDbType.NVarChar) { Value = patient.Name });
                command.ExecuteNonQuery();
            }

        }

        public static void DeletePatient(int id)
        {
            var connection = DatabaseIns.Instance.GetDatabaseConnection();
            const string sqlQuery = "DELETE FROM Patients where ID=@ID";
            using (var command = new SqlCommand(sqlQuery, connection))
            {
                command.Parameters.Add(new SqlParameter("@ID", SqlDbType.Int) { Value = id });
                command.ExecuteNonQuery();
            }
        }

        public static List<Patient> GetAllPatients()
        {
            List<Patient> patients = new List<Patient>();
            var connection = DatabaseIns.Instance.GetDatabaseConnection();
            const string sqlQuery = "SELECT * FROM Patients";
            using (var command = new SqlCommand(sqlQuery, connection))
            {
                using (var reader = command.ExecuteReader())
                {
                    while (reader.Read())
                    {
                        Patient patient = new Patient
                        {
                            ID = Convert.ToInt32(reader["ID"]),
                            Age = Convert.ToInt32(reader["Sum"]),
                            Name = reader["Status"],
                        };
                        patients.Add(patient);
                    }
                }
            }

            return patients;
        }

        public static void UpdatePatient(int id, string name, int age)
        {
            var connection = DatabaseIns.Instance.GetDatabaseConnection();
            const string sqlQuery = "Update Patients set Name=@Name, Age=@Age where ID = @ID";

            using (var command = new SqlCommand(sqlQuery, connection))
            {
                command.Parameters.Add(new SqlParameter("@ID", SqlDbType.Int) { Value = id });
                command.Parameters.Add(new SqlParameter("@Name", SqlDbType.NVarChar) { Value = name });
                command.Parameters.Add(new SqlParameter("@Age", SqlDbType.Int) { Value = age });
                command.ExecuteNonQuery();
            }
        }
    }
}

