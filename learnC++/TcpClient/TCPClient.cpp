#include "TCPClient.h"
#include <WinSock2.h>
#include <stdio.h>

TCPClient::TCPClient(void)
{
}


TCPClient::~TCPClient(void)
{
}

void main(){
	WORD versionRequeted;
	WSADATA data;
	int err;
	versionRequeted = MAKEWORD(1, 1);
	err = WSAStartup(versionRequeted, & data);
	if(err != 0){
		return;
	}
	if(LOBYTE(data.wVersion) != 1 || HIBYTE(data.wVersion) != 1){
		WSACleanup();
		return;
	}
	SOCKET socketClient = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrClient;
	addrClient.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(6000);
	connect(socketClient, (SOCKADDR*)&addrClient, sizeof(SOCKADDR));
	
	char recvBuf[111];
	recv(socketClient, recvBuf, 100, 0);
	printf("%s\n", recvBuf);
	send(socketClient, "wurd client", strlen("wurd client")+1, 0);

	closesocket(socketClient);
	WSACleanup();
	
	
}