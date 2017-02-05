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
	char buffer[512];
	uint16_t res;

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
	server.sin_port = htons(1783);
//	server.sin_addr.s_addr = inet_addr ("10.14.239.98");
	server.sin_addr.s_addr = inet_addr ("127.0.0.1");

	if (connect (c, (struct sockaddr*) &server, sizeof (server)) < 0)
	{
		perror ("Error at connect");
		exit (2);
	}
	else
		printf ("Connected\n");

	printf ("Input string: ");
	gets (buffer);

	send (c, buffer, sizeof (buffer), 0);
	recv (c, &res, sizeof (res), 0);

	res = ntohs (res);
	printf ("There are %hu spaces in the string\n", res);

	close (c);
}
