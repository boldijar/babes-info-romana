using System;
using System.Collections.Generic;

using FamilyDoctor.Service;
using FamilyDoctor.Utils;

namespace FamilyDoctor.UI.CLI
{
    public class Menu
    {
        string name, cmd, exitCommand;
        ICommandService commandService;
        List<string> menuHelpList;

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        protected string CurrentCommand
        {
            get { return cmd; }
        }

        public string ExitCommand
        {
            get { return exitCommand; }
            set { exitCommand = value; }
        }

        public ICommandService CommandService
        { 
            get { return commandService; }
            internal set { commandService = value; }
        }

        public List<string> MenuHelpList
        {
            get { return menuHelpList; }
            set { menuHelpList = value; }
        }

        public Menu()
        {
            exitCommand = "0";
            menuHelpList = new List<string>();
        }

        public Menu(string name)
            : this()
        {
            this.name = name;
        }

        public virtual string Input(string prompt)
        {
            Console.Write(prompt);
            return Console.ReadLine();
        }

        public bool InputPermission(string prompt)
        {
            Console.Write(prompt);
            Console.Write(" (y/N) ");

            while (true)
            {
                ConsoleKeyInfo c = Console.ReadKey();

                switch (c.Key)
                {
                    case ConsoleKey.Y:
                        Console.WriteLine();
                        return true;

                    case ConsoleKey.N:
                    case ConsoleKey.Enter:
                        Console.WriteLine();
                        return false;

                    default:
                        Console.SetCursorPosition(Console.CursorLeft - 1, Console.CursorTop);
                        break;
                }
            }
        }

        public void ExecuteCommand(params string[] paramList)
        {
            string command = string.Join("|", paramList);
            string response;

            try
            {
                response = commandService.ExecuteCommand(command);
                Console.WriteLine(response);
            }
            catch (ServiceException e)
            {
                response = "Service Exception: " + e.Message;
                Log.WriteError(response);
            }
        }

        public virtual string GetCommand()
        {
            Console.Write("> ");
            return Console.ReadLine();
        }

        public virtual void HandleCommand()
        {
            
        }

        public void Show()
        {
            while (cmd != exitCommand)
            {
                Console.WriteLine("-===< " + name + " >===-");
                foreach (string line in menuHelpList)
                    Console.WriteLine(line);
                Console.WriteLine("Enter '" + exitCommand + "' to exit this menu");
                
                cmd = GetCommand();
                Console.WriteLine();

                HandleCommand();
            }
        }
    }
}

