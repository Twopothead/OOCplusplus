#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int num,k,total,flag;
	total=100;cout<<"Prime number between 1 and "<<total<<":"<<endl;
	for(num=2;num<=total;num++){
		flag=0;
		for(k=2;k<num/2;k++){
				if (flag==1)
					break;
				if(num%k==0)
				    flag=1;
		}
		if(flag==0)
		cout<<num<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}
