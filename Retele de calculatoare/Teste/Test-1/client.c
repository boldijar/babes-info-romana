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
	int c;
	struct sockaddr_in server;
	uint16_t a, b, suma;

	printf ("Creating socket...\n");
	c = socket (AF_INET, SOCK_STREAM, 0);

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

	printf ("Connecting to server...\n");
	if (connect (c, (struct sockaddr*) &server, sizeof (server)) < 0)
	{
		perror ("Error at connect");
		exit (2);
	}
	else
		printf ("Connected to server sucessfully\n");

	printf ("a = ");
	scanf ("%hu", &a);

	printf ("b = ");
	scanf ("%hu", &b);


	printf ("Sending '%hu' and '%hu'...\n", a, b);
	a = htons (a);
	b = htons (b);
	send (c, &a, sizeof (a), 0);
	send (c, &b, sizeof (b), 0);

	printf ("Receiving sum...\n");
	recv (c, &suma, sizeof (suma), 0);

	suma = ntohs (suma);
	printf ("Received '%hu'\n", suma);

	printf ("Closing connection...\n");
	close (c);
}
