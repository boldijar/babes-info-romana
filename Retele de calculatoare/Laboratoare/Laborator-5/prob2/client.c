#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	int c;
	struct sockaddr_in server;
	int l;
	uint16_t nr, isPrime;

	c = socket(AF_INET, SOCK_DGRAM, 0);
	if (c < 0)
	{
		perror ("Error creating socket");
		exit (errno);
	}

	memset (&server, 0, sizeof (server));
	server.sin_port = htons (3451);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr ("127.0.0.1");

	l = sizeof (server);

	printf ("Enter a number: ");
	scanf ("%hu", &nr);
	nr = htons (nr);

	sendto (c, &nr, sizeof (nr), 0, (struct sockaddr *) &server, sizeof (server));
	recvfrom (c, &isPrime, sizeof (isPrime), MSG_WAITALL, (struct sockaddr *) &server, &l);

	isPrime = ntohs (isPrime);
	if (isPrime)
		printf ("Your number is prime!\n");
	else
		printf ("Your number is not prime!\n");

	close (c);
	return 0;
}
