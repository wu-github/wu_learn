#include "UdpC.h"
#include <WinSock2.h>
#include <stdio.h>

UdpC::UdpC(void)
{
}


UdpC::~UdpC(void)
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

	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	sendto(sockClient, "wurd udp client", strlen("wurd udp client")+1, 0, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	closesocket(sockClient);
	WSACleanup();

}