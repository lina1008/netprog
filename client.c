#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main () {

	char servermessage [256] = "Hi";
	int net_socket;
	net_socket = socket(AF_INET, SOCK_STREAM,0);
	
	struct sockaddr_in server_add;
	server_add.sin_family= AF_INET;
	server_add.sin_port = htons (17800);
	server_add.sin_addr.s_addr=inet_addr("192.168.30.132");
	
	int status = connect (net_socket,(struct sockaddr *)&server_add,sizeof(server_add));
	
	if (status == -1) {
	
		printf("ERROR! %s\n");
		
	}
	
	send (net_socket,servermessage,sizeof(servermessage),0);
	
	char server_resp [256];
	recv(net_socket,server_resp,sizeof(server_resp),0);
	
	printf("Server message: %s\n", server_resp);
	
	close(net_socket);
	
	return 0;
	
}
