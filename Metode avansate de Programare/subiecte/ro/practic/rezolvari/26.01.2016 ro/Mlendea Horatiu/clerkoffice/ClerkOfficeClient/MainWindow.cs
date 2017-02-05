using System;
using Gtk;

using ClerkOffice.Service;
using ClerkOffice.Utils;

public partial class MainWindow: Gtk.Window
{
    ICommandService commandService;

    public ICommandService CommandService
    { 
        get { return commandService; }
        internal set { commandService = value; }
    }

    public MainWindow()
        : base(Gtk.WindowType.Toplevel)
    {
        Build();

        try
        {
            // ExecuteCommand("ping");
        }
        catch
        {
            ShowMessageDialog("Connection error", "Cannot connect to server", MessageType.Error, ButtonsType.Ok);
        }
    }

    string ExecuteCommand(params string[] paramList)
    {
        string command = string.Join(" ", paramList);
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

    void ShowMessageDialog(string title, string message, MessageType msgType, ButtonsType btnType)
    {
        MessageDialog md = new MessageDialog(null, DialogFlags.Modal, msgType, btnType, message);
        md.Title = title;
        md.Run();
        md.Destroy();
    }

    protected void OnDeleteEvent(object sender, DeleteEventArgs a)
    {
        Application.Quit();
        a.RetVal = true;
    }

    protected void OnBtnClerkOfficeClicked(object sender, EventArgs e)
    {
        ClerkLoginWindow clerkLoginWindow = new ClerkLoginWindow();
        clerkLoginWindow.CommandService = commandService;
        clerkLoginWindow.Show();
    }

    protected void OnBtnWaitingRoomClicked(object sender, EventArgs e)
    {
        WaitingRoomWindow waitingRoomWindow = new WaitingRoomWindow();
        waitingRoomWindow.CommandService = commandService;
        waitingRoomWindow.Show();
    }
}
