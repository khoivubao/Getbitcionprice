#include <stdio.h>
#include "Socket.h"

char buffer[4096] = { 0 };

void main()
{
	Socket_Client_Init("54.192.22.61", 80);
	Send("GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n");
	Recv(buffer, sizeof(buffer));
	//printf("Data from server: %s", buffer);

	char *key = "\"rate_float\":";
	char *Position = strstr(key, &buffer);

	char Price[32] = { 0 };
	int indx = 0;
	while((Price[indx]+Position) != '}')
	{ 
		printf("Bitcoin = %s USD\r\n", Price[indx]);
		indx++;
	}
}