using System;
using System.Threading;
using Gtk;

using ClerkOffice.Service;
using ClerkOffice.Utils;

public partial class ClerkOfficeWindow : Gtk.Window
{
    ICommandService commandService;
    int officeNumber;

    public int OfficeNumber
    {
        get { return officeNumber; }
        set { officeNumber = value; }
    }

    public ICommandService CommandService
    { 
        get { return commandService; }
        internal set { commandService = value; }
    }

    public ClerkOfficeWindow()
        : base(Gtk.WindowType.Toplevel)
    {
        this.Build();
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

    protected void OnBtnNextClicked(object sender, EventArgs e)
    {
        ExecuteCommand("next " + 3);

        new Thread(() =>
            {
                Thread.Sleep(10000);
                ExecuteCommand("deactivateticket", "0");
            }).Start();
    }

    protected void OnBtnArrivedClicked(object sender, EventArgs e)
    {
        ExecuteCommand("arrived " + 3);
    }
}
    