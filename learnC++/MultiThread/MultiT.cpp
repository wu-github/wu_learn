#include "MultiT.h"
#include <Windows.h>
#include <iostream>

using namespace std; 

MultiT::MultiT(void)
{
}


MultiT::~MultiT(void)
{
}

DWORD WINAPI Fun1(LPVOID lp);

DWORD WINAPI Fun2(LPVOID lp);

int tickets = 100;
int index = 0;

HANDLE mutex;

void main(){

	//mutex = CreateMutex(NULL, FALSE, NULL);
	mutex = CreateMutexA(NULL, FALSE, "wurd");
	if(mutex){
		if(ERROR_ALREADY_EXISTS == GetLastError()){
			cout<<"is running"<<endl;
		}
	}


	HANDLE t1;
	t1 = CreateThread(NULL, 0, Fun1, NULL, 0, NULL);
	CloseHandle(t1);

	HANDLE t2;
	t2 = CreateThread(NULL, 0, Fun2, NULL, 0, NULL);
	CloseHandle(t2);

	/*while(index<1000)
	cout<<"mail thread"<<endl;*/
	
	Sleep(5000);
	system("pause");

}

DWORD WINAPI Fun1(LPVOID lp){
	/*while(index<1000)
	cout<<"t1 thread"<<endl;*/
	/*while(TRUE){
		WaitForSingleObject(mutex, INFINITE);
		if(tickets > 0){
			cout<<"t1 tickets: "<<tickets--<<endl;
		}else{
			break;
		}
		ReleaseMutex(mutex);
	}*/

	WaitForSingleObject(mutex, INFINITE);
	cout<<"t1 tickets: "<<""<<endl;
	return 0;
}

DWORD WINAPI Fun2(LPVOID lp){
	/*while(index<1000)
	cout<<"t2 thread"<<endl;*/
	/*while(TRUE){
		WaitForSingleObject(mutex, INFINITE);
		if(tickets > 0){
			cout<<"t2 tickets: "<<tickets--<<endl;
		}else{
			break;
		}
		ReleaseMutex(mutex);
	}*/

	WaitForSingleObject(mutex, INFINITE);
	cout<<"t2 tickets: "<<""<<endl;
	return 0;
}