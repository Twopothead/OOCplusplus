#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Studemt;
class Course;
class Score;
int globalno=19215116;
int globalnumber=0;
int globalgrade=0;
class Course{
public :
	void highest();
	void lowest();
	void average();
private:
	int cno;
	int cname;
};
void Course::highest()
{
}
void Course::lowest()
{

}
void Course::average()
{
}
class Score{
public :
private:
	int sscore;
};
class Student
{
public :
	Student();
	void putname();
	void putno();
	void putgrade();
	void disp_stud();
private:
	int sno;
	string sname;
	int sgrade;
	Course scourse;
	Score sscore;
};
string int2string(int n)
{
ostringstream stream;
stream<<n;  //n为int类型
return stream.str();
}
string globalname="Qiu";
Student::Student()
{
	
	sno=globalno++;
	sname=globalname+int2string(globalnumber++);
	cout<<sno<<"  "<<this->sname<<endl;
}

void Student::putname()
{
	cout<<"Please modify sname:";
		cin>>this->sname;
		
};
void Student::putno()
{
	cout<<"Please modify sno:";
		cin>>this->sno;
		
};
void Student::putgrade()
{	
	cout<<"Please modify sgrade:";
	cin>>this->sgrade;
};
int main()
{
//TestBox();
	Student Q;
	Student Qiu[20];

return 0;
}