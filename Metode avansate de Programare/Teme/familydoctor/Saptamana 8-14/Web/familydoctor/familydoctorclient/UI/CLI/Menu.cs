using System;
using System.Collections.Generic;
using System.Net;
using System.Text;
using System.IO;

using FamilyDoctor.Utils;

namespace FamilyDoctor.UI.CLI
{
    public class Menu
    {
        string name, cmd, exitCommand;
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

        public void SendHttpPostRequest(params string[] paramList)
        {
            string postData = string.Join("&", paramList);
            string responseMessage;

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
                
                Console.WriteLine(responseMessage);
            }
            catch (Exception e)
            {
                responseMessage = e.Message;
                Log.WriteError(responseMessage);
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
                Console.WriteLine();
            }
        }
    }
}

