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

	printf ("Creating socket...\n");
	s = socket (AF_INET, SOCK_STREAM, 0);

	if (c < 0)
	{
		perror ("Error at socket");
		exit (1);
	}
	else
		printf ("Socket created sucessfully\n");

	memset (&server, 0, sizeof (server));
	server.sin_family = AF_INET;
	server.sin_port = htons (1146);
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
		uint16_t a, b, suma;

		c = accept (s, (struct sockaddr*) &client, &l);
		printf ("A client has connected...\n");

		printf ("Waiting to receive the data...\n");
		recv (c, &a, sizeof (a), MSG_WAITALL);
		recv (c, &b, sizeof (b), MSG_WAITALL);

		a = ntohs (a);
		b = ntohs (b);
		suma = a + b;
		printf ("Received '%hu' and '%hu'\n", a, b, suma);

		printf ("Sending '%hu' to client...\n", suma);
		suma = htons (suma);
		send (c, &suma, sizeof (suma), 0);
		printf ("Sum sent to client\n");

		printf ("Closing connection...\n");
		close (c);
	}
}
