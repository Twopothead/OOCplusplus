#include "les7grade.h"
using namespace std;
CClass::CClass(){
	setclassname();
	setclassnum();
	Stu =new CStudent[classnum];
}
CClass::~CClass(){
	if(Stu)
		delete[] Stu;
}
CPerson::CPerson(string Aname,int Aage,string AID,Gender Asex):name(Aname),age(Aage),ID(AID),sex(Asex){
}
CPerson::CPerson(CPerson &other):name(other.name),age(other.age),ID(other.ID),sex(other.sex){
}
CPerson::CPerson(){
	name="NONE";
	age=0;
	sex=female;
	ID="NULL";
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
CCourse::CCourse(CCourse &other):courseName(other.courseName),credit(other.credit){
}
CCourse::CCourse(){
	courseName = "NoneCourse";
	credit = 0;
	teacher = "None";
	grade = 0;
}

void CCourse::setteacher(){
cout<<"Please input teacher's name:";
cin>>teacher;
}
void CCourse::setcourseName(){
	cout<<"Please input Course Name:";
	cin>>courseName;
}
void CCourse::setcredit(){
	cout<<"Please input credit of this course:";
	cin>>credit;
}
void CCourse::setCourse(){
	setcourseName();
	setcredit();
	setteacher();
	cout<<"please input grade of this course";
	cin>>grade;
}
CStudent::CStudent(){
	setStudent();
}
void CStudent::setStudent(){
	cout<<"Please input Student number :";
	cin>>studentNumber;
}
int CStudent::totalcredit(){
	return courses[0].credit+courses[1].credit+courses[2].credit;
}
void CStudent::gettotalcredit(){
	cout<<"total credit of "<<name<<" is"<<gettotalcredit<<endl;
}
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

void CClass::setclassname(){
	cout<<"Please input class name:";
	cin>>classname;
}
void CClass::setclassnum(){
	cout<<"Please input total number of students in this class:";
	cin>>classnum;
}
void main(){
	CClass c;
}