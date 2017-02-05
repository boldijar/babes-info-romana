using System;
using System.Diagnostics;
using System.IO;

public class Log
{
    #region Variables
    static bool enabled = true;
    static bool firstUse = true;
    static string fileLocation = Environment.CurrentDirectory;
    static string fileName = "logfile.log";
    static string timestampFormat = "<HH:mm:ss>";
    #endregion

    #region Properties
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
            File.WriteAllText(FileLocation + "\\" + FileName, "");
            firstUse = false;
        }

        using (StreamWriter sw = File.AppendText(FileLocation + "\\" + FileName))
            sw.Write(DateTime.Now.ToString(TimestampFormat) + " " + text);

        Debug.Write(text);
    }

    public static void WriteLine(string text)
    {
        Write(text + Environment.NewLine);
    }
}
