using Gtk;

using FamilyDoctor.UI.CLI;
using FamilyDoctor.UI.GTK;

namespace FamilyDoctor
{
    class MainClass
    {
        enum InterfaceType
        {
            CLI,
            GTK
        }

        public static void Main(string[] args)
        {
            InterfaceType interfaceType = InterfaceType.GTK; // Default is GTK2

            foreach (string arg in args)
            {
                switch (arg)
                {
                    case "--cli":
                        interfaceType = InterfaceType.CLI;
                        break;

                    case "--gtk":
                        interfaceType = InterfaceType.GTK;
                        break;
                }
            }
            switch (interfaceType)
            {
                case InterfaceType.GTK:
                    Application.Init();
                    MainWindow win = new MainWindow();
                    win.Show();
                    Application.Run();
                    break;

                case InterfaceType.CLI:
                    MainMenu ui = new MainMenu();
                    ui.Show();
                    break;
            }
        }
    }
}
