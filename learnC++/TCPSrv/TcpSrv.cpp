#include "TcpSrv.h"
#include <WinSock2.h>
#include <stdio.h>

TcpSrv::TcpSrv(void)
{
}


TcpSrv::~TcpSrv(void)
{
}


void main(){
	WORD versionRequeted;
	WSADATA data;
	int err;
	versionRequeted = MAKEWORD(1, 1);
	err = WSAStartup(versionRequeted, &data);
	if(err != 0){
		return;
	}
	if(LOBYTE(data.wVersion) != 1 || HIBYTE(data.wVersion) != 1){
		WSACleanup();
		return;
	}
	SOCKET socketSrv = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	
	bind(socketSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	listen(socketSrv, 5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while(1){
		SOCKET sockConn = accept(socketSrv, (SOCKADDR*)&addrClient, &len);
		char sendBuf[111];
		sprintf(sendBuf, "wurd %s dodo", inet_ntoa(addrClient.sin_addr));
		send(sockConn, sendBuf, strlen(sendBuf)+1, 0);
		char recvBuf[111];
		recv(sockConn, recvBuf, 100, 0);
		printf("%s\n", recvBuf);
		closesocket(sockConn);

	}
	
}