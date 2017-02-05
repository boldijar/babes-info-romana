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
	uint16_t nr, sum;
	//uint16_t a, b, s;

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
	server.sin_port = htons(4674);
//	server.sin_addr.s_addr = inet_addr ("192.168.1.184");
	server.sin_addr.s_addr = inet_addr ("127.0.0.1");

	if (connect (c, (struct sockaddr*) &server, sizeof (server)) < 0)
	{
		perror ("Error at connect");
		exit (2);
	}
	else
		printf ("Connected\n");

	while (1)
	{
		printf ("Send number: ");
		scanf ("%uh", &nr);

		nr = htons (nr);

		send (c, &nr, sizeof (nr), 0);

		nr = ntohs (nr);
		if (nr == 0)
			break;
	}

	recv (c, &sum, sizeof (sum), 0);
	sum = ntohs (sum);

	printf ("Sum is '%hu'\n", sum);

	close (c);
}
