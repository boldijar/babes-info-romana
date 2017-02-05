#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int s;
	struct sockaddr_in server, client;
	int c, l;
	char buffer1[512], buffer2[512], buffer3[512];

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		perror ("Error at socket");
		exit (1);
	}
	else
		printf ("Socked created\n");

	memset(&server, 0, sizeof (server));
	server.sin_port = htons(1784);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (struct sockaddr *) &server, sizeof (server)) < 0)
	{
		perror ("Eroare la bind");
		exit (2);
	}
	else
		printf ("Bind successfull\n");

	listen(s, 5);

	l = sizeof (client);
	memset (&client, 0, sizeof (client));

	while (1)
	{
		int i, j, c1, c2;
		char aux;

		c = accept (s, (struct sockaddr *) &client, &l);
		printf("A client has connected\n");

		recv (c, buffer1, sizeof (buffer1), MSG_WAITALL);
		recv (c, buffer2, sizeof (buffer2), MSG_WAITALL);

		c1 = 0; c2 = 0;
		for (i = 0; i < strlen (buffer1) + strlen (buffer2); i++)
			if (buffer1[c1] < buffer2[c2])
			{
				buffer3[i] = buffer1[c1];
				c1 += 1;
			}
			else
			{
				buffer3[i] = buffer2[c2];
				c2 += 1;
			}

		if (c1 < strlen (buffer1) - 1)
			for (; c1 < strlen (buffer1); c1++)
			{
				buffer3[i] = buffer1[c1];
				i += 1;
			}

		if (c2 < strlen (buffer2) - 1)
			for (; c2 < strlen (buffer2); c2++)
			{
				buffer3[i] = buffer2[c2];
				i += 1;
			}

		buffer3[c1 + c2 - 1] = '\0';

		send (c, buffer3, strlen (buffer3), 0);

		close (c);
		printf ("Client connection closed\n");
	}
}
