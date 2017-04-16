#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <windows.h>
using namespace std;
enum Gender{male,female};
class CPerson;
class CCourse;
class CStudent;
class CClass;
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
