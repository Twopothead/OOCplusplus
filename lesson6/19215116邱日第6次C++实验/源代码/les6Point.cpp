#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <windows.h>
using namespace std;
class Student{
public:
	Student(string Name,string Num):name(Name),num(Num){};
private:
	friend class AnotherScore;
	friend void show(Student &S){
		cout<<"Name:"<<S.name<<"\tNum:\t"<<S.num<<endl;
	};
	string name;
	string num;
};
class Score{
public :	Score(unsigned int s1,unsigned int s2,unsigned s3):mat(s1),phy(s2),eng(s3){}
private:
	unsigned int mat,phy,eng;
	friend void showAll(Student &,Score &);
};
void showAll(Student &S,Score &score){
	show(S);
	cout<<"Mathematics:"<<score.mat<<"\t\tPhysics:"<<score.phy<<"\tEnglish:"<<score.eng<<endl;
}
class AnotherScore{
	public :	AnotherScore(unsigned int s1,unsigned int s2,unsigned s3):mat(s1),phy(s2),eng(s3){}
				void displayStu(Student &S);
				void display(){
					cout<<"Mathematics:"<<mat<<"\t\tPhysics:"<<phy<<"\tEnglish:"<<eng<<endl;
				}
private:
	unsigned int mat,phy,eng;
};
void AnotherScore::displayStu(Student &S){
	cout<<"Student Name:"<<S.name<<endl;
	display();
}
class ComputeDistance;
class Point{
public:
	Point(){
		cout<<"Please input x_data:";
		cin>>this->x;
		cout<<"Please input y_data:";
		cin>>this->y;
	}
	Point(Point &other){
		this->x=other.x;
		this->y=other.y;
	}
	Point(double xx,double yy):x(xx),y(yy){}
	double PointDistance(Point &B){
		return(sqrt((this->x-B.x)*(this->x-B.x)+(this->y-B.y)*(this->y-B.y)));
	}
	void displayXY(){
		cout<<"x_data:"<<setw(10)<<this->x<<",\ty_data"<<setw(10)<<this->y<<endl;
	}
private:
	friend class ComputeDistance;
	friend double FucDistance(Point &Pa,Point &Pb){
		return(sqrt((Pa.x-Pb.x)*(Pa.x-Pb.x)+(Pa.y-Pb.y)*(Pa.y-Pb.y)));
	}
	double x;
	double y;	
};
class ComputeDistance{
public:
	ComputeDistance(Point &Pa,Point &Pb):xa(Pa.x),ya(Pa.y),xb(Pb.x),yb(Pb.y){
		xsquare=abs(this->xa-this->xb);
		xsquare*=xsquare;
		ysquare=abs(this->ya-this->yb);
		ysquare*=ysquare;
	}
	double Distance(){
		return(sqrt(xsquare+ysquare));
	}
private:
	double xa;
	double ya;
	double xb;
	double yb;
	double xsquare;
	double ysquare;
};
void Test1(){
Student qiuri("qiuri","19215116");
Score rigeScore(99,97,100);
showAll(qiuri,rigeScore);
}
void Test2(){
cout<<endl;
Student qiuri("qiuri","19215116");
AnotherScore anotherSco(94,95,96);
anotherSco.displayStu(qiuri);
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
Test1();
Test2();
TestPoint();
system("pause");
return 0;
}