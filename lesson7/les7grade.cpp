#include "les7grade.h"
using namespace std;
CCourse Lesson[3];
CClass::CClass(){
	setclassname();
	setclassnum();
	Stu =new CStudent[classnum];
}
void InitCourse(){
	
	int i=0;
	for(i=0;i<3;i++){
		cout<<"Please input information of Course No."<<(i+1)<<endl;
		Lesson[i].setCourse();
	}
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
void CPerson::setPerson(){
	setname();
	setGender();
	setage();
	setID();
}
void CPerson::showinfo(){
	cout<<"Name:\t"<<setw(10)<<name<<"\t\tGender:\t";
	if(sex==female)
		cout<<setw(7)<<"female";
	else
		cout<<setw(7)<<"male";
	cout<<"\t\tAge:"<<setw(4)<<age<<"\t\t"<<"ID number:"<<setw(10)<<ID<<endl;
}
void CStudent::setStudent(){
	cout<<endl<<endl<<"Please input Student number :";
	cin>>studentNumber;
	for(int i=0;i<3;i++){
		this->courses[i]=Lesson[i];
		courses[i].setgrade();
	}
	char temp;
	cout<<"Do you want to fill in the details?(y/n)";
	cin>>temp;
	if(temp=='y')
		this->setPerson();
	this->showinfo();
}
CStudent::CStudent(){
	setStudent();
}
CCourse::CCourse(CCourse &other):courseName(other.courseName),credit(other.credit){
}
CCourse::CCourse(){
	courseName = "NoneCourse";
	credit = 0;
	teacher = "None";
	grade = 0;
}
void CCourse::setgrade(){
	cout<<"please input grade of "<<courseName<<":";
	cin>>grade;
}
void CCourse::setCourse(){
	setcourseName();
	setcredit();
	setteacher();
	cout<<endl;
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
	double min=100;
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
	cout<<endl<<endl;
	for(int i=0;i<3;i++){
	cout<<"information of "<<Lesson[i].courseName<<"are as follows"<<endl;
	cout<<" Highest score: "<<Max(i);
	cout<<" Lowest score : "<<Min(i);
	cout<<" Average score : "<<Average(i);
	cout<<endl;
	}
}
void CStudent::stuinfo(){
	cout<<endl<<"information of student "<<name<<endl;
    for(int i=0;i<3;i++){
		cout<<"\t"<<courses[i].courseName<<courses[i].grade<<endl;
	}
}
void CClass::Seek(){
	int i;
	char temp;
label:cout<<"Seek Student No.";
	cin>>i;
	if((i>classnum)||(i<0))
		cout<<"Student No."<<i<<"is not found!"<<endl;
	else
		{
			Stu[i-1].showinfo();
			Stu[i-1].stuinfo();
		}
	cout<<"Do you want to search again?(y/n):";
	cin>>temp;
	if(temp=='y')
		goto label;

}
void CClass::setclassname(){
	cout<<"Please input class name:";
	cin>>classname;
}
void CClass::setclassnum(){
	classnum=0;
	cout<<"Please input total number of students in this class:";
	cin>>classnum;
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
void main(){
	InitCourse();
	CClass C;
	C.classInfo();
	C.Seek();
}