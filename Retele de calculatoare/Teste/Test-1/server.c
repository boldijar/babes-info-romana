#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	int s;
	struct sockaddr_in server, client;
	int c, l;
	char f_name[512];
	char s_name[512];
	int client_count = 0;

	printf ("Creating socket...\n");
	s = socket (AF_INET, SOCK_STREAM, 0);

	switch (fork ())
	{
		case -1:
			perror ("Error at fork");
			exit (errno);

		case 0:
			break;

		default:
			printf ("Server launched in background. Stop it with \"killall <NAME>\"\n");
			exit (0);
	}

	if (c < 0)
	{
		perror ("Error at socket");
		exit (errno);
	}
	else
		printf ("Socket created sucessfully\n");

	memset (&server, 0, sizeof (server));
	server.sin_family = AF_INET;
	server.sin_port = htons (1147);
	server.sin_addr.s_addr = INADDR_ANY;

	printf ("Binding...\n");
	if (bind (s, (struct sockaddr*) &server, sizeof (server)) < 0)
	{
		perror ("Error at bind");
		exit (2);
	}
	else
		printf ("Binded sucessfully\n");

	listen (s, 5);

	l = sizeof (client);
	memset (&client, 0, sizeof (client));

	while (1)
	{
		printf ("Waiting for a client to connect...\n");

		c = accept (s, (struct sockaddr*) &client, &l);
		printf ("A client has connected...\n");
		client_count += 1;

		printf ("Waiting to receive the data...\n");
		recv (c, &f_name, sizeof (f_name), MSG_WAITALL);
		recv (c, &s_name, sizeof (s_name), MSG_WAITALL);

		printf ("Sending data to client...\n");
		if (client_count == 0)
		{
			send (c, &s_name, sizeof (s_name), 0);
			send (c, &f_name, sizeof (f_name), 0);
		}

		printf ("Closing connection...\n");
		close (c);
	}
}
