#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <windows.h>
#include "les6distance.h"
using namespace std;
Point::Point(){
		cout<<"Please input x_data:";
		cin>>this->x;
		cout<<"Please input y_data:";
		cin>>this->y;
}
Point::Point(Point &other){
		this->x=other.x;
		this->y=other.y;
}
Point::Point(double xx,double yy):x(xx),y(yy){
}
double Point::PointDistance(Point &B){
		return(sqrt((this->x-B.x)*(this->x-B.x)+(this->y-B.y)*(this->y-B.y)));
}
void Point::displayXY(){
		cout<<"x_data:"<<setw(10)<<this->x<<",\ty_data"<<setw(10)<<this->y<<endl;
}
double FucDistance(Point &Pa,Point &Pb){
		return(sqrt((Pa.x-Pb.x)*(Pa.x-Pb.x)+(Pa.y-Pb.y)*(Pa.y-Pb.y)));
}
ComputeDistance::ComputeDistance(Point &Pa,Point &Pb):xa(Pa.x),ya(Pa.y),xb(Pb.x),yb(Pb.y){
		xsquare=abs(this->xa-this->xb);
		xsquare*=xsquare;
		ysquare=abs(this->ya-this->yb);
		ysquare*=ysquare;
}
double ComputeDistance::Distance(){
		return(sqrt(xsquare+ysquare));
}
void TestPoint(){
Point Pa(3.0,4.0);
Point Pb(6.0,8.0);
cout<<endl<<"Point A:  ";
Pa.displayXY();
cout<<"Point B:  ";
Pb.displayXY();
cout<<"The distance between A and B:"<<endl;
cout<<"Member function of class Point               :"<<setw(10)<<Pa.PointDistance(Pb)<<endl;
cout<<"friend function of class Point               :"<<setw(10)<<FucDistance(Pa,Pb)<<endl;
ComputeDistance Compute(Pa,Pb);
cout<<"friend class's member function of class Point:"<<setw(10)<<Compute.Distance()<<endl;
}
int main()
{
TestPoint();
system("pause");
return 0;
}