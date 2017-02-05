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
	char buffer1[512], buffer2[512];

	c = socket (AF_INET, SOCK_STREAM, 0);

	if (c < 0)
	{
		perror ("Error at socket");
		exit (1);
	}
	else
		printf ("Socket created\n");

	memset (&server, 0, sizeof (server));
	server.sin_family = AF_INET;
//	server.sin_port = htons (1234);
//	server.sin_addr.s_addr = inet_addr ("10.42.0.54");
	server.sin_port = htons (1784);
	server.sin_addr.s_addr = inet_addr ("127.0.0.1");

	if (connect (c, (struct sockaddr*) &server, sizeof (server)) < 0)
	{
		perror ("Error at connect");
		exit (2);
	}
	else
		printf ("Connected\n");

	printf ("String 1: ");
	gets (buffer1);

	printf ("String 2: ");
	gets (buffer2);

	send (c, buffer1, sizeof (buffer1), 0);
	send (c, buffer2, sizeof (buffer2), 0);
	recv (c, buffer1, sizeof (buffer1), 0);

	printf ("Result: ");
	puts (buffer1);

	close (c);
}
