#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int add(int m,int n)
{
	return m+n;
}
int sub(int m,int n)
{
	return m-n;
}
int mul(int m,int n)
{
	return m*n;
}
double divd(int m,int n)
{
	return double(m)/double(n);
}
double  power(int x)
{
	if ((x==1)){
		return 1;
	}
	else return x*power(x-1);

}
void squareroot(int n)
{
	cout<<"x^0.5=";
	if(n<0)
		cout<<"none! "<<endl;
	else cout<<sqrt(n)<<endl;
}
int mod(int x,int y)
{
	int result=x%y;
	if(result<0)
		result+=y;
	return result;
}
void test()
{
	int x,y;
	cout<<"Please input x:"<<endl;
	cin>>x;
	cout<<"Please input y:"<<endl;
	cin>>y;
	cout<<"x+y="<<add(x,y)<<endl;
	cout<<"x-y="<<sub(x,y)<<endl;
	cout<<"x*y="<<mul(x,y)<<endl;
	cout<<"x/y="<<divd(x,y)<<endl; 
	squareroot(x);
	cout<<"x mod y="<<mod(x,y)<<endl;
	system("pause");
}
int main()
{
	test();
	return 0;
}