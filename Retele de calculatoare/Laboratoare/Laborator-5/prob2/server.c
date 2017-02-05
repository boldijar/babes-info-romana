#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	int s;
	struct sockaddr_in server, client;
	int l, i;
	uint16_t nr, isPrime;

	s = socket (AF_INET, SOCK_DGRAM, 0);
	if (s < 0)
	{
		perror ("Error creating socket!");
		exit (errno);
	}

	memset (&server, 0, sizeof (server));
	server.sin_port = htons (3451);
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;

	if (bind (s, (struct sockaddr *) &server, sizeof (server)) < 0)
	{
		perror ("Error binding");
		exit (errno);
	}

	l = sizeof (client);
	memset (&client, 0, sizeof (client));

	while (1)
	{
		printf ("Waiting for a number...\n");

		recvfrom (s, &nr, sizeof (nr), MSG_WAITALL, (struct sockaddr *) &client, &l);
		nr = ntohs (nr);

		printf ("Received '%hu'\n", nr);

		isPrime = 1;
		for (i = 2; i < nr * 0.5; i++)
			if (nr % i == 0)
				isPrime = 0;

//		printf ("nr=%hu isPrime=%hu\n", nr, isPrime);
		isPrime = htons (isPrime);
		sendto (s, &isPrime, sizeof (isPrime), 0, (struct sockaddr *) &client, sizeof (client));

//		close (s);
	}

	return 0;
}
