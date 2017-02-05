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
	uint16_t sum, nr;

	s = socket(AF_INET, SOCK_STREAM, 0);
	if (s < 0)
	{
		perror ("Error at socket");
		exit (1);
	}
	else
		printf ("Socked created\n");

	memset(&server, 0, sizeof (server));
	server.sin_port = htons(4674);
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
		c = accept (s, (struct sockaddr *) &client, &l);
		printf("A client has connected\n");

		sum = 0;
		nr = 0;

		while (1)
		{
			recv (c, &nr, sizeof (nr), MSG_WAITALL);
			nr = ntohs (nr);
			printf ("Received '%hu'\n", nr);
			sum += nr;

			if (nr == 0)
				break;
		}

		printf ("Sending '%hu'\n", sum);
		sum = htons (sum);
		send(c, &sum, sizeof(sum), 0);

		close (c);
		printf ("Client connection closed\n");
	}
}
