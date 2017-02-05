using System;
using System.IO;

namespace FamilyDoctor.Utils
{
    public static class Log
    {
        static int verbLevel = 1;
        static bool enabled = true;
        static bool firstUse = true;
        static bool newline = true;
        static string fileLocation = Environment.CurrentDirectory;
        static string fileName = "logfile.log";
        static string timestampFormat = "<HH:mm:ss>";

        #region Properties

        public static int VerbosityLevel
        {
            get { return verbLevel; }
            set
            {
                verbLevel = value;
                enabled = value != 0;
            }
        }

        public static bool Enabled
        {
            get { return enabled; }
            set { enabled = value; }
        }

        public static string FileLocation
        {
            get { return fileLocation; }
            set { fileLocation = value; }
        }

        public static string FileName
        {
            get { return fileName; }
            set { fileName = value; }
        }

        public static string TimestampFormat
        {
            get { return timestampFormat; }
            set { timestampFormat = value; }
        }

        #endregion

        public static void Write(string text)
        {
            if (firstUse)
            {
                File.WriteAllText(FileLocation + "/" + FileName, "");
                firstUse = false;
            }

            if (newline)
            {
                text = DateTime.Now.ToString(TimestampFormat) + " " + text;
                newline = false;
            }

            using (StreamWriter sw = File.AppendText(FileLocation + "/" + FileName))
                sw.Write(text);

            Console.Write(text);
        }

        public static void Write(string text, int verbosityLevel)
        {
            if (verbosityLevel <= verbLevel)
                Write(text);
        }

        public static void WriteLine(string text)
        {
            Write(text + Environment.NewLine);
            newline = true;
        }

        public static void WriteLine(string text, int verbosityLevel)
        {
            if (verbosityLevel <= verbLevel)
                WriteLine(text);
        }

        public static void WriteError(string text)
        {
            WriteLine("ERROR: " + text + "!");
            Console.Beep();
        }

        public static void WriteError(string text, int verbosityLevel)
        {
            if (verbosityLevel <= verbLevel)
                WriteError(text);
        }

        public static void WriteWarning(string text)
        {
            WriteLine("WARNING: " + text + "!");
        }

        public static void WriteWarning(string text, int verbosityLevel)
        {
            if (verbosityLevel <= verbLevel)
                WriteWarning(text);
        }
    }
}
