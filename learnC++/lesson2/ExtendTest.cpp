#include "StdAfx.h"
//""从当前目录开始查找文件
#include "ExtendTest.h"
//<>从库里边开始查找
#include <iostream>

using namespace std;

ExtendTest::ExtendTest(void)
{
}


ExtendTest::~ExtendTest(void)
{
}

//防止多次include，导致redefine错误
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
	//纯虚函数，必须被继承
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