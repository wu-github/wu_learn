#include "UdpSrv.h"
#include <WinSock2.h>
#include <stdio.h>

UdpSrv::UdpSrv(void)
{
}


UdpSrv::~UdpSrv(void)
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

	recvfrom(sockSrv, recvBuf, 111, 0, (SOCKADDR*)&addrClient, &len);
	printf("%s\n", recvBuf);
	closesocket(sockSrv);


}