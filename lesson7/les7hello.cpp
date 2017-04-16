#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <windows.h>
using namespace std;
class CPerson;
class CCourse;
class CStudent;
class CClass;
enum Gender{male,female};
class CPerson{
public:
	CPerson();
	CPerson(CPerson &);
	CPerson(string Aname,int Aage,string AID,Gender sex);
	void setname();
	void setage();
	void setID();
	void setGender();
	void setPerson();
    void showinfo();
protected:
	string name;
	int age;
	string ID;
	Gender sex;
};
CPerson::CPerson(string Aname,int Aage,string AID,Gender Asex):name(Aname),age(Aage),ID(AID),sex(Asex){
}
CPerson::CPerson(CPerson &other):name(other.name),age(other.age),ID(other.ID),sex(other.sex){
}
void CPerson::setname(){
	cout<<"Please input name:";
	cin>>name;
}
void CPerson::setage(){
	cout<<"Please input age:";
	cin>>age;
}
void CPerson::setID(){
	cout<<"Please input ID number:";
	cin>>ID;
}
void CPerson::setGender(){
	char yesorno;
	cout<<"Are you a female?(y/n) ";
	cin>>yesorno;
	sex?(yesorno=='y'):female,male;
}
void CPerson::showinfo(){
cout<<"Name:\t"<<setw(10)<<name<<"\t\tGender:\t";
if(sex==female)
	cout<<setw(7)<<"female";
else
cout<<setw(7)<<"male";
cout<<"\t\tAge:"<<setw(4)<<age<<"\t\t"<<"ID number:"<<setw(10)<<ID<<endl;
}
void CPerson::setPerson(){
	setname();
	setGender();
	setage();
	setID();
}
CPerson::CPerson(){
	name="NONE";
	age=0;
	sex=female;
	ID="NULL";
	//setPerson();
	setPerson();
}

class CCourse{
public:
	friend CStudent;
	friend CClass;
	void setcredit();
	void setcourseName();
	void setteacher();
	CCourse();
	CCourse(CCourse &other);
	void setCourse();
	double grade;
private:
	string courseName;
	int credit;

	string teacher;
};
void CCourse::setteacher(){
cout<<"Please input teacher's name:";
cin>>teacher;
}
CCourse::CCourse(){
	courseName = "NoneCourse";
	credit = 0;
	teacher = "None";
	grade = 0;
	//setCourse();
	setCourse();
}
CCourse::CCourse(CCourse &other):courseName(other.courseName),credit(other.credit){}
void CCourse::setcredit(){
	cout<<"Please input credit:";
	cin>>credit;
}
void CCourse::setcourseName(){
	cout<<"Please input Course Name:";
	cin>>courseName;
}
void CCourse::setCourse(){
	setcourseName();
	setcredit();
	setteacher();
	cout<<"please input grade of this course";
	cin>>grade;
}
class CStudent:CPerson{
	public:
		friend CClass;
		CStudent();
		void setStudent();
		int totalcredit();
		void gettotalcredit();
	private:
	string studentNumber;
	CCourse courses[3];
};

void CStudent::setStudent(){
	cout<<"Please input Student number :";
	cin>>studentNumber;

}
CStudent::CStudent(){
	setStudent();
}
int CStudent::totalcredit(){
	return courses[0].credit+courses[1].credit+courses[2].credit;
}
void CStudent::gettotalcredit(){
	cout<<"total credit of "<<name<<" is"<<gettotalcredit<<endl;
}
class CClass{
public:
	CClass();
	void Seek();
	double Max(int);
	double Min(int );
	double Average(int);
	void classInfo();
	void setclassname();
	void setclassnum();
	~CClass();
private:
string classname;
int classnum;
CStudent *Stu;
};

double CClass::Max(int courseNo){
	double max=0;
	for(int i=0;i<classnum;i++)
		if (Stu[i].courses[courseNo].grade>max)
		max = Stu[i].courses[courseNo].grade;
	return max;
}
double CClass::Min(int courseNo){
	double min=0;
	for(int i=0;i<classnum;i++)
		if (Stu[i].courses[courseNo].grade<min)
		min = Stu[i].courses[courseNo].grade;
	return min;
}
double CClass::Average(int courseNo){
	double Average=0;
	if(classnum!=0){
	for(int i=0;i<classnum;i++)
		Average += Stu[i].courses[courseNo].grade;
	Average/=classnum;
	}
	return Average;
}
void CClass::classInfo(){
	cout<<"Highest score of "<<Stu[0].courses[0].courseName<<Max(0);
}
CClass::CClass(){
	setclassname();
	setclassnum();
	Stu =new CStudent[classnum];
}
CClass::~CClass(){
	if(Stu)
		delete[] Stu;
}
void CClass::setclassname(){
	cout<<"Please input class name:";
	cin>>classname;
}
void CClass::setclassnum(){
	cout<<"Please input total number of students in this class:";
	cin>>classnum;
}

int main()
{
	//CPerson qiuri("qiuri",21,"321284199604230216",male);
	//CPerson jinzhu("Jinzhu",18,"32128419990101000x",female);
	//CPerson meinv("meinv",16,"32128420010202000x",female);
	//qiuri.showinfo();
	//jinzhu.showinfo();
	//meinv.showinfo();
	CClass C;
	




return 0;
}