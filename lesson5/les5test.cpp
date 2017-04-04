#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <algorithm>
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
    Score(Student &Stu){

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
	void disp_Course(){

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
		//cin>>this->sname;
		//while(ch!='\a')
		//{
			//ch=getche();
		//	this->sname+=ch;
		//}
		//while(ch!=13)
		//{
		//	ch=getche();
		//	this->sname+=ch;
		//}
		//cout<<'\t';
			//cout<<(int)ch;
		   //while((ch=cin.get())!='\n') 
    		//{ 
        	//	cin.unget(); 
        	//	cin>>sname; 
    		//} 
		//while(ch!='\r')
		//{
		//	ch=getche();
		//	this->sname+=ch;
		//}
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
Student::Student()
{	
	setsname();
	setsgrade();
	setsno();
	cout<<endl;
}
void MAX()
{}
void MIN()
{}
void temp(){
	int i;
	cin>>i;

Student *S=new Student[i];
for(int k=0;k<i;k++)
 {
 	S[k].disp_stud();
 	cout<<S[k].getCourseNo();
 }
 int CourseStuNum=0;
 int CourNo=1;
for(k=0;k<i;k++)
{
	if(S[k].getCourseNo()==CourNo)
		CourseStuNum++;
}

int *StuScore=new int[CourseStuNum];}
void temp2(){

}
bool Coursesorter(Student &A,Student &B){
return A.getCourseNo()<B.getCourseNo();
}
bool Gradesorter(Student &A,Student &B){
return A.getScore()>B.getScore();
}
int main()
{
//Student a;
//a.disp_stud();
	
	
vector <Student> StuVec;
//vector <vector<Student>>> CourseVec;
//vector < vector <Student> > CourseVec; 
vector <Student> CourseVec;
int i;
cin>>i;
for(int k=0;k<i;k++)
 {
 	Student a;
 	StuVec.push_back(a);
 }
 vector<Student>::iterator it;
for(it=StuVec.begin();it!=StuVec.end();it++)
	it->disp_stud();
sort(StuVec.begin(),StuVec.end(),Coursesorter);
cout<<endl<<endl<<endl;

for(it=StuVec.begin();it!=StuVec.end();it++)
	it->disp_stud();
//for(it=StuVec.begin();it!=StuVec.end();it++){
//if(it.getCourseNo==1)
//	CourseVec.push_back(it);
//it=StuVec.begin();
//itt=StuVec.end();
//	CourseVec.assign(it,StuVec.end());
vector<Student>::iterator head;
vector<Student>::iterator tail;
int flag=0;
tail=StuVec.end();
for(it=StuVec.begin();it!=StuVec.end();it++){
		if((it->getCourseNo()==6)&&(flag==0)){
			head=it;
			flag=1;
		}
	    if((flag==1)&&(it->getCourseNo()!=6)){
	    	tail=it-1;
	    	goto ok;
	    }

}
ok:
CourseVec.assign(head,tail);
for(it=CourseVec.begin();it!=CourseVec.end();it++)
	it->disp_stud();
	return 0;
}