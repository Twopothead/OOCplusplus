#include <iostream> 
#include <string> 
#include <algorithm>
#include <vector>
#include <windows.h>
using namespace std; 
int main() 
{ 
	string namestr;
	vector <string> namevect;
	cout<<"Please input 5 student's name:"<<endl;
	for(int i=0;i<5;i++)
	{
		cin>>namestr;
		namevect.push_back(namestr.substr(0,namestr.find('\n')));
	}
	cout<<endl<<"origin:"<<endl;
	for(vector<string>::iterator it=namevect.begin();it!=namevect.end();it++){
		cout<<*it<<endl;
	}
	cout<<endl<<"sort:"<<endl;
	sort(namevect.begin(),namevect.end());
	for(it=namevect.begin();it!=namevect.end();it++){
		cout<<*it<<endl;
	}
	cout<<endl;
	system("pause");
    return 0;
}