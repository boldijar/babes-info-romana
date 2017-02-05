using System;
using Gtk;
using FamilyDoctor.Service;
using FamilyDoctor.Utils;

namespace FamilyDoctor.UI.GTK
{
    public partial class MainWindow: Window
    {
        ICommandService commandService;

        public ICommandService CommandService
        { 
            get { return commandService; }
            internal set { commandService = value; }
        }

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

        string ExecuteCommand(params string[] paramList)
        {
            string command = string.Join("|", paramList);
            string response;

            try
            {
                response = commandService.ExecuteCommand(command);
            }
            catch (ServiceException e)
            {
                response = e.Message;
                ShowMessageDialog("Error", response, MessageType.Error, ButtonsType.Ok);
                Log.WriteError(response);
            }

            return response;
        }

        protected void OnBtnAppointmentAddClicked(object sender, EventArgs e)
        {
            string id = entAppointmentAppointmentID.Text;
            string patientId = entAppointmentPatientID.Text;
            string diagnostic = entAppointmentDiagnostic.Text;
            DateTime date = calAppointmentDate.Date;
            bool isEmergency = chkAppointmentEmergency.Active;

            string response = ExecuteCommand("addappointment", id, patientId, diagnostic, date.ToString(), isEmergency.ToString());
            ShowMessageDialog("Response", response, MessageType.Info, ButtonsType.Ok);
        }

        protected void OnBtnAppointmentsListClicked(object sender, EventArgs e)
        {
            string response = string.Empty;

            switch (cmbAppointmentListCriteria.Active)
            {
                case 0: // All
                    response = ExecuteCommand("listappointments");
                    break;

                case 1: // Patient
                    response = ExecuteCommand("listappointments", "patientid", entAppointmentListValue.Text);
                    break;

                case 2: // Diagnostic
                    response = ExecuteCommand("listappointments", "diagnostic", entAppointmentListValue.Text);
                    break;

                case 3: // Emergency
                    response = ExecuteCommand("listappointments", "emergency", entAppointmentListValue.Text);
                    break;
            }

            txtAppointmentListResult.Buffer.Text = response;
        }

        protected void OnBtnPatientAddClicked(object sender, EventArgs e)
        {
            string id = entPatientID.Text;
            string name = entPatientName.Text;
            int age = (int)spnPatientAge.Value;

            string response = ExecuteCommand("addpatient", id, name, age.ToString());
            ShowMessageDialog("Response", response, MessageType.Info, ButtonsType.Ok);
        }

        protected void OnBtnPatientListClicked(object sender, EventArgs e)
        {
            string response = string.Empty;

            switch (cmbPatientListCriteria.Active)
            {
                case 0: // All
                    response = ExecuteCommand("listpatients");
                    break;

                case 1: // ID
                    response = ExecuteCommand("listpatients", "id", entPatientListValue.Text);
                    break;

                case 2: // Over Age X
                    response = ExecuteCommand("listpatients", "age-gt", entPatientListValue.Text);
                    break;

                case 3: // Under Age X
                    response = ExecuteCommand("listpatients", "age-lt", entPatientListValue.Text);
                    break;
            }

            txtPatientListResult.Buffer.Text = response;
        }
    }
}