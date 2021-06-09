#include "NetSrv.h"
#include <WinSock2.h>
#include <stdio.h>

NetSrv::NetSrv(void)
{
}


NetSrv::~NetSrv(void)
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

	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	SOCKADDR_IN addrClient;

	int len = sizeof(SOCKADDR);
	char recvBuf[111];
	char sendBuf[111];
	char tempBuf[222];

	while(1){
		recvfrom(sockSrv, recvBuf, 111, 0, (SOCKADDR*)&addrClient, &len);
		if('q' == recvBuf[0]){
			sendto(sockSrv, "q", strlen("q")+1, 0, (SOCKADDR*)&addrClient, len);
			printf("chat end\n");
			//break;
		}
		sprintf_s(tempBuf, "%s say : %s", inet_ntoa(addrClient.sin_addr), recvBuf);
		printf("%s\n", tempBuf);
		printf("please input:\n");
		gets_s(sendBuf);
		sendto(sockSrv, sendBuf, strlen(sendBuf)+1, 0, (SOCKADDR*)&addrClient, len);
	}
	closesocket(sockSrv);
	WSACleanup();

}