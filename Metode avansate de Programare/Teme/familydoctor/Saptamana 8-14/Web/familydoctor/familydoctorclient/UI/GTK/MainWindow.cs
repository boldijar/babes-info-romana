using System;
using System.Net;
using System.Text;
using System.IO;

using Gtk;

using FamilyDoctor.Utils;

namespace FamilyDoctor.UI.GTK
{
    public partial class MainWindow: Window
    {
        public MainWindow()
            : base(WindowType.Toplevel)
        {
            Build();
        }

        protected void OnDeleteEvent(object sender, DeleteEventArgs a)
        {
            Application.Quit();
            a.RetVal = true;
        }

        void ShowMessageDialog(string title, string message, MessageType msgType, ButtonsType btnType)
        {
            MessageDialog md = new MessageDialog(null, DialogFlags.Modal, msgType, btnType, message);
            md.Title = title;
            md.Run();
            md.Destroy();
        }

        public string SendHttpPostRequest(params string[] paramList)
        {
            string postData = string.Join("&", paramList);
            string responseMessage;

            Console.WriteLine(postData);

            try
            {
                WebRequest request = WebRequest.Create("http://127.0.0.1:8080/manager");
                byte[] byteArray = Encoding.UTF8.GetBytes(postData);

                request.Method = "POST";
                request.ContentType = "application/x-www-form-urlencoded";
                request.ContentLength = byteArray.Length;

                Stream dataStream = request.GetRequestStream();
                dataStream.Write(byteArray, 0, byteArray.Length);
                dataStream.Close();

                WebResponse response = request.GetResponse();
                dataStream = response.GetResponseStream();
                StreamReader reader = new StreamReader(dataStream);
                string responseFromServer = reader.ReadToEnd();
                responseMessage = responseFromServer;

                reader.Close();
                dataStream.Close();
                response.Close();
            }
            catch (Exception e)
            {
                responseMessage = e.Message;
                Log.WriteError(responseMessage);
            }

            return responseMessage;
        }

        protected void OnBtnAppointmentAddClicked(object sender, EventArgs e)
        {
            string id = entAppointmentAppointmentID.Text;
            string patientId = entAppointmentPatientID.Text;
            string diagnostic = entAppointmentDiagnostic.Text;
            DateTime date = calAppointmentDate.Date;
            bool isEmergency = chkAppointmentEmergency.Active;

            string response = SendHttpPostRequest(
                                  "command=addappointment",
                                  "appointmentID=" + id,
                                  "patientID=" + patientId,
                                  "diagnostic=" + diagnostic,
                                  "date=" + date,
                                  "isEmergency=" + isEmergency);

            ShowMessageDialog("Response", response, MessageType.Info, ButtonsType.Ok);
        }

        protected void OnBtnAppointmentsListClicked(object sender, EventArgs e)
        {
            string response = string.Empty;

            switch (cmbAppointmentListCriteria.Active)
            {
                case 0: // All
                    response = SendHttpPostRequest(
                        "command=listappointments",
                        "criteria=all");
                    break;

                case 1: // Patient
                    response = SendHttpPostRequest(
                        "command=listappointments",
                        "criteria=patientid",
                        "value=" + entAppointmentListValue.Text);
                    break;

                case 2: // Diagnostic
                    response = SendHttpPostRequest(
                        "command=listappointments",
                        "criteria=diagnostic",
                        "value=" + entAppointmentListValue.Text);
                    break;

                case 3: // Emergency
                    response = SendHttpPostRequest(
                        "command=listappointments",
                        "criteria=emergency",
                        "value=" + entAppointmentListValue.Text);
                    break;
            }

            txtAppointmentListResult.Buffer.Text = response;
        }

        protected void OnBtnPatientAddClicked(object sender, EventArgs e)
        {
            string id = entPatientID.Text;
            string name = entPatientName.Text;
            int age = (int)spnPatientAge.Value;

            string response = SendHttpPostRequest("addpatient", id, name, age.ToString());
            ShowMessageDialog("Response", response, MessageType.Info, ButtonsType.Ok);
        }

        protected void OnBtnPatientListClicked(object sender, EventArgs e)
        {
            string response = string.Empty;

            switch (cmbPatientListCriteria.Active)
            {
                case 0: // All
                    response = SendHttpPostRequest(
                        "command=listpatients",
                        "criteria=all");
                    break;

                case 1: // ID
                    response = SendHttpPostRequest(
                        "command=listpatients",
                        "criteria=id",
                        "value=" + entPatientListValue.Text);
                    break;

                case 2: // Over Age X
                    response = SendHttpPostRequest(
                        "command=listpatients",
                        "criteria=age-gt",
                        "value=" + entPatientListValue.Text);
                    break;

                case 3: // Under Age X
                    response = SendHttpPostRequest(
                        "command=listpatients",
                        "criteria=age-lt",
                        "value=" + entPatientListValue.Text);
                    break;
            }

            txtPatientListResult.Buffer.Text = response;
        }
    }
}