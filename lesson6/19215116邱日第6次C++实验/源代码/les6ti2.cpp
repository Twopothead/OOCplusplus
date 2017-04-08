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
public:	Score(unsigned int s1,unsigned int s2,unsigned s3):mat(s1),phy(s2),eng(s3){}
private:
	unsigned int mat,phy,eng;
	friend void showAll(Student &,Score &);
};
void showAll(Student &S,Score &score){
	show(S);
	cout<<"Mathematics:"<<score.mat<<"\t\tPhysics:"<<score.phy<<"\tEnglish:"<<score.eng<<endl;
}
class AnotherScore{
	public:	AnotherScore(unsigned int s1,unsigned int s2,unsigned s3):mat(s1),phy(s2),eng(s3){}
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
void Test2(){
Student qiuri("qiuri","19215116");
AnotherScore anotherSco(94,95,96);
anotherSco.displayStu(qiuri);
}
int main()
{
Test2();
system("pause");
return 0;
}