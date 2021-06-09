#include "NetClient.h"
#include <WinSock2.h>
#include <stdio.h>

NetClient::NetClient(void)
{
}


NetClient::~NetClient(void)
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
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");;
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	int len = sizeof(SOCKADDR);
	char recvBuf[111];
	char sendBuf[111];
	char tempBuf[222];

	while(1){
		printf("please input:\n");
		gets_s(sendBuf);
		sendto(sockSrv, sendBuf, strlen(sendBuf)+1, 0, (SOCKADDR*)&addrSrv, len);

		recvfrom(sockSrv, recvBuf, 111, 0, (SOCKADDR*)&addrSrv, &len);
		if('q' == recvBuf[0]){
			sendto(sockSrv, "q", strlen("q")+1, 0, (SOCKADDR*)&addrSrv, len);
			printf("chat end\n");
			break;
		}
		sprintf_s(tempBuf, "%s say : %s", inet_ntoa(addrSrv.sin_addr), recvBuf);
		printf("%s\n", tempBuf);
	}
	closesocket(sockSrv);
	WSACleanup();

}