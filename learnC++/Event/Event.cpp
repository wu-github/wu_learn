#include "Event.h"
#include <Windows.h>
#include <iostream>

using namespace std;

Event::Event(void)
{
}


Event::~Event(void)
{
}

DWORD WINAPI Fun1(LPVOID lp);

DWORD WINAPI Fun2(LPVOID lp);

int tickets = 100;

HANDLE g_event;

void main1(){

	HANDLE t1;
	t1 = CreateThread(NULL, 0, Fun1, NULL, 0, NULL);
	CloseHandle(t1);

	HANDLE t2;
	t2 = CreateThread(NULL, 0, Fun2, NULL, 0, NULL);
	CloseHandle(t2);

	//g_event = CreateEvent(NULL, TRUE, FALSE, NULL);
	//g_event = CreateEvent(NULL, FALSE, FALSE, NULL);
	g_event = CreateEventA(NULL, FALSE, FALSE, "tickit");
	if(g_event){
		if(ERROR_ALREADY_EXISTS == GetLastError()){
			cout<<"is running"<<endl;
			return;
		}
	}
	SetEvent(g_event);

	system("pause");
	CloseHandle(g_event);
}

DWORD WINAPI Fun1(LPVOID lp){
	while(TRUE){
		WaitForSingleObject(g_event, INFINITE);
		//ResetEvent(g_event);
		if(tickets > 0){
			Sleep(1);
			cout<<"t1 tickets: "<<tickets--<<endl;
		}else{
			break;
		}
		SetEvent(g_event);
	}

	return 0;
}

DWORD WINAPI Fun2(LPVOID lp){
	while(TRUE){
		WaitForSingleObject(g_event, INFINITE);
		//ResetEvent(g_event);
		if(tickets > 0){
			Sleep(1);
			cout<<"t2 tickets: "<<tickets--<<endl;
		}else{
			break;
		}
		SetEvent(g_event);
	}

	return 0;
}
