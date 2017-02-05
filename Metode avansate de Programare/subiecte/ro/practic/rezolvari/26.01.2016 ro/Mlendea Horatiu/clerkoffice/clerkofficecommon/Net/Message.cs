namespace ClerkOffice.Net
{
    public class Message
    {
        readonly string body;

        public Message(string body)
        {
            this.body = body;
        }

        public override string ToString()
        {
            return body;
        }
    }
}
