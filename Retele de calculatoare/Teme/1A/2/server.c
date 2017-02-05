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
	char buffer[512];

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		perror ("Error at socket");
		exit (1);
	}
	else
		printf ("Socked created\n");

	memset(&server, 0, sizeof (server));
	server.sin_port = htons(1783);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (struct sockaddr *) &server, sizeof (server)) < 0)
	{
		printf("Eroare la bind\n");
		return 1;
	}
	else
		printf ("Bind successfull\n");

	listen(s, 5);

	l = sizeof (client);
	memset (&client, 0, sizeof (client));

	while (1)
	{
		int i = 0;
		uint16_t count = 0;

		c = accept (s, (struct sockaddr *) &client, &l);
		printf("A client has connected\n");

		recv (c, buffer, sizeof (buffer), MSG_WAITALL);

		for (i = 0; i < strlen (buffer); i++)
			if (buffer[i] == ' ')
				count += 1;

		count = htons (count);
		send (c, &count, sizeof (count), 0);

		close (c);
		printf ("Client connection closed\n");
	}
}
