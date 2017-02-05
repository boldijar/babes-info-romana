using System;
using Gtk;

using ClerkOffice.Service;
using ClerkOffice.Utils;

public partial class WaitingRoomWindow : Gtk.Window
{
    ICommandService commandService;

    public ICommandService CommandService
    { 
        get { return commandService; }
        internal set { commandService = value; }
    }

    public WaitingRoomWindow()
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

    protected void OnBtnTicketClicked(object sender, EventArgs e)
    {
        string response;

        response = ExecuteCommand("ticket");

        if (!string.IsNullOrEmpty(response))
            ShowMessageDialog("Ticket info", response, MessageType.Info, ButtonsType.Ok);
    }
}
