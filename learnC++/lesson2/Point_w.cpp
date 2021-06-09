#include "StdAfx.h"
#include "Point_w.h"
#include "iostream"

using namespace std;
Point_w::Point_w(void)
{
}


Point_w::~Point_w(void)
{
}

//struct Point{
class Point{
	
public:
	int x;
	int y;
	Point(){
		x=0;
		y=0;
	}
	Point(int a, int b){
		this->x=a;
		y=b;
	}
	~Point(){
		cout<<"over"<<endl;
	}
	void output(){
		cout <<"x: "<<x<<endl<<"y: "<<y<<endl<<"z: "<<z<<endl;
	}
	void setZ(int num){
		z = num;
	}
private:
	int z;
};

void main1(){
	Point p(5,5);
	//Point* p;
	//p = new Point(5,5);
	//Point p = Point(5,5);
	//p.init();
	//p.x = 1;
	//p.y = 5;
	p.setZ(10);
	//cout <<"p.x: "<<p.x<<endl<<"p.y: "<<p.y<<endl;
	cout <<"p: "<<&p<<endl;
	p.output();
	//delete &p;
	system("pause");
}
