#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int total=0;
int queen[8]={0};
int checkF(int n)
{
	for(int i=0;i<n;i++)
	{
		if( (queen[i]==queen[n])||( abs(queen[i]-queen[n])==abs(i-n) ) )
			return 1;
	}

return 0;
}
void display()
{
	cout<<++total<<" solution:(";
	for(int i=0;i<8;i++)
		cout<<queen[i]<<" ";
	cout<<")"<<endl;

}
void Nqueen(int n)
{
	int i;
	for(i=0;i<8;i++)
	{
		queen[n]=i;
		if(!checkF(n))
		{
			if(n==7)
				display();
			else 
				Nqueen(n+1);
			
		}
	}
}
int main()
{
	cout<<"The positions of the queens in every row are as follows:"<<endl;
	Nqueen(0);
	system("pause");
	return 0;
}