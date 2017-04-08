#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <windows.h>
using namespace std;
class Student;
class Course;
class Score;
class Score{
public:
	friend class Student;
    Score(){
    	cout<<"input score: ";
    	cin>>score;
    };
private:
	int score;
};
class Course{
public:
	friend class Student;
	Course(){
		cout<<"input Course cname: ";
		cin>>cname;
		cout<<"input Course cno  : ";
		cin>>cno;
	};
private:
		int cno;
		string cname;
};

class Student{
public:
	friend class Course;
	friend class Score;
	Student();
	void setsname(){
		cout<<" input sname:";
		cin>>this->sname; 
	};
	void setsno(){
		cout<<" input sno:";
		cin>>this->sno;
	};
	void setsgrade(){
		cout<<" input sgrade:";
		cin>>this->sgrade;
	};
	void disp_stud(){
		cout<<"Student "<<" No."<<setw(10)<<sno<<setw(10)<<"  name:"<<setw(10)<<sname<<"  grade:"<<setw(5)<<sgrade<<"  ";
		cout<<"CourseNo."<<setw(5)<<getCourseNo()<<"  CourseName:"<<setw(10)<<getCourseName()<<endl;
	};
	int getCourseNo(){
		return scourse.cno;
	};
	string getCourseName(){
		return scourse.cname;
	}
	int getScore(){
		return sscore.score;
	}
private: 
		int sno;
		string sname;
		int sgrade;
		Course scourse;
		Score sscore;
};
Student::Student(){	
	setsname();
	setsgrade();
	setsno();
	cout<<endl;
}
bool Coursesorter(Student &A,Student &B){
return A.getCourseNo()<B.getCourseNo();
}
bool Gradesorter(Student &A,Student &B){
return A.getScore()>B.getScore();
}
void Courseinfo(vector<Student> &StuVec,vector<Student> &CourseVec){
vector<Student>::iterator head;
vector<Student>::iterator tail;
vector<Student>::iterator it;
int flag=0;
int CourseNum;
tail=StuVec.end()-1;
cout<<"Please input Course Number:"<<endl;
cin>>CourseNum;
for(it=StuVec.begin();it!=StuVec.end();it++){
		if((it->getCourseNo()==CourseNum)&&(flag==0)){
			head=it;
			flag=1;
		}
	    if((flag==1)&&(it->getCourseNo()!=CourseNum)){
	    	tail=it-1;
	    	goto ok;
	    }
}
ok:
CourseVec.assign(head,tail);
cout<<endl<<"Search Results about  No."<<CourseNum<<setw(10)<<head->getCourseName()<<endl;
int totalStu=0;
int ScoreSum=0;
int Average=0;
for(it=CourseVec.begin();it!=CourseVec.end();it++){
		it->disp_stud();
		totalStu++;
		ScoreSum+=it->getScore();

}
cout<<endl<<"Highest Score:"<<head->getScore()<<endl;
head->disp_stud();
cout<<endl<<"Lowest Score:"<<tail->getScore()<<endl;
tail->disp_stud();
if(totalStu!=0){
	Average=ScoreSum/totalStu;
	cout<<endl<<"Average Score of "<<head->getCourseName()<<" is"<<Average<<endl;
}

}
QueryCourse(vector<Student> &StuVec,vector<Student> &CourseVec){
char temp;
label:
Courseinfo(StuVec,CourseVec);
cout<<endl<<"Do you want to search information of another  Course(y/n)";
cin>>temp;
if(temp=='y'||temp=='Y')
	goto label;
}
void Test(){
vector <Student> StuVec;
vector <Student> CourseVec;
int i;
cout<<"Please input the total number of Records:";
cin>>i;
for(int k=0;k<i;k++){
 	Student a;
 	StuVec.push_back(a);
}
vector<Student>::iterator it;
cout<<endl<<"Original Records:"<<endl;
for(it=StuVec.begin();it!=StuVec.end();it++)
	it->disp_stud();
sort(StuVec.begin(),StuVec.end(),Coursesorter);
cout<<endl<<endl<<endl<<"Sorted Records"<<endl;
for(it=StuVec.begin();it!=StuVec.end();it++)
	it->disp_stud();
QueryCourse(StuVec,CourseVec);
}
int main()
{	
	Test();
	system("pause");
	return 0;
}