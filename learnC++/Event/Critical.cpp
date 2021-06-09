#include <Windows.h>
#include <iostream>

//dead lock

using namespace std;
namespace critical
{
#include "Critical.h"

	Critical::Critical(void)
	{
	}

	Critical::~Critical(void)
	{
	}

	DWORD WINAPI Fun1(LPVOID lp);

	DWORD WINAPI Fun2(LPVOID lp);

	int tickets = 100;

	CRITICAL_SECTION g_csA;
	CRITICAL_SECTION g_csB;

	void main(){

		HANDLE t1;
		t1 = CreateThread(NULL, 0, Fun1, NULL, 0, NULL);
		CloseHandle(t1);

		HANDLE t2;
		t2 = CreateThread(NULL, 0, Fun2, NULL, 0, NULL);
		CloseHandle(t2);

		InitializeCriticalSection(&g_csA);
		InitializeCriticalSection(&g_csB);

		system("pause");
		DeleteCriticalSection(&g_csA);
		DeleteCriticalSection(&g_csB);
	}

	DWORD WINAPI Fun1(LPVOID lp){
		while(TRUE){
			EnterCriticalSection(&g_csA);
			Sleep(10);
			EnterCriticalSection(&g_csB);
			if(tickets > 0){
				Sleep(1);
				cout<<"t1 tickets: "<<tickets--<<endl;
			}else{
				break;
			}
			LeaveCriticalSection(&g_csA);
			LeaveCriticalSection(&g_csB);
		}

		return 0;
	}

	DWORD WINAPI Fun2(LPVOID lp){
		while(TRUE){
			EnterCriticalSection(&g_csB);
			Sleep(10);
			EnterCriticalSection(&g_csA);
			if(tickets > 0){
				Sleep(1);
				cout<<"t2 tickets: "<<tickets--<<endl;
			}else{
				break;
			}
			LeaveCriticalSection(&g_csA);
			LeaveCriticalSection(&g_csB);
		}

		return 0;
	}


}
void main(){
	critical::main();
}