namespace ClerkOffice.Models
{
    public class Clerk
    {
        string username, password;


        public string Username
        {
            get { return username; }
            set
            {
                username = value;
                ClerkValidator.ValidateUsername(value);
            }
        }

        public string Password
        {
            get { return password; }
            set
            {
                password = value;
                ClerkValidator.ValidatePassword(value);
            }
        }

        public Clerk()
        {

        }

        public Clerk(string username, string password)
            : this()
        {
            this.username = username;
            this.password = password;

            ClerkValidator.Validate(this);
        }

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;

            if (obj.GetType() == typeof(Clerk))
            if (username == ((Clerk)obj).Username)
                return true;
            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return username;
        }

        public static class ClerkValidator
        {
            public static void Validate(Clerk clerk)
            {
                ValidateUsername(clerk.Username);
                ValidatePassword(clerk.Password);
            }

            public static void ValidateUsername(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid username");
            }

            public static void ValidatePassword(string value)
            {
                if (string.IsNullOrEmpty(value))
                    throw new ValidationException("Invalid password");
            }
        }
    }
}
