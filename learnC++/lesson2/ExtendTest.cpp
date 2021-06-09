#include "StdAfx.h"
//""�ӵ�ǰĿ¼��ʼ�����ļ�
#include "ExtendTest.h"
//<>�ӿ���߿�ʼ����
#include <iostream>

using namespace std;

ExtendTest::ExtendTest(void)
{
}


ExtendTest::~ExtendTest(void)
{
}

//��ֹ���include������redefine����
#ifndef Animal_H_H
#define Animal_H_H

class Animal{
public:
	Animal(){
		cout <<"animal"<<endl;
	}
	Animal(int height){
		cout <<"animal"<<height<<endl;
	}
	virtual void eat(){
		cout <<"animal eat"<<endl;
	}
	//���麯�������뱻�̳�
	//virtual void eat()=0;
	void sleep(){
		cout <<"animal sleep"<<endl;
	}
	void play(){
		cout <<"animal play"<<endl;
	}
	void dosomething();
protected:
	void ppp(){
		cout <<"animal ppp"<<endl;
	}
};

void Animal::dosomething(){
	cout<<"animal do something"<<endl;
}

#endif


class Fish : public Animal{
public:
	Fish():Animal(100),num(11){
		cout <<"fish"<<endl;
	}
	Fish(int height):num(11){
		cout <<"fish"<<height<<endl;
	}
	void eat(){
		Animal::ppp();
		cout<<"fish eat"<<endl;
	}
	void test(){
		ppp();
	}
private:
	const int num;
	
};

void fn(Animal *pAn){
	pAn->eat();
}

void main(){
	Fish fish;
	Animal *pAn;
	pAn = &fish;
	fn(&fish);
	fish.dosomething();
	system("pause");
}

void main2(){
	Animal animal;
	animal.eat();
	Fish fish;
	fish.eat();
	fish.test();
	std::cout<<"test std::cout"<<endl;
	system("pause");
}