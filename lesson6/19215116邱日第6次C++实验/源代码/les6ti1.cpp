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
	friend void show(Student &S);
	string name;
	string num;
};
 void show(Student &S){
		cout<<"Name:"<<S.name<<"\tNum:\t"<<S.num<<endl;
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
void Test1(){
Student qiuri("qiuri","19215116");
Score rigeScore(99,97,100);
showAll(qiuri,rigeScore);
}
int main()
{
Test1();
system("pause");
return 0;
}