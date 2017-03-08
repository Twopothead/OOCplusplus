#include <iostream>
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
	double i=m;
	double j=n;
	return i/j;
}
int jiecheng(int x)
{
	if ((x==0)||(x==1)){
		return 1;}
	else return(x*jiecheng(x-1));
}
double xishu(double a,int ci)
{
	double temp;
	temp=a-ci;
	double result=1.0;
	while(temp!=a)
	{
		temp+=1.0;
		result*=temp;
	}
	return result;
}
int exp(int x,int ci)
{
	int result=1;
	for(int i=0;i<ci;i++)
	 result*=x;
	 return result;
}
double every(int x,int xiang)
{
	double result=1.0;
	if(xiang==0){
		result=double(x);
	}else{
		result*=xishu(0.5,xiang);
		result*=exp(x,xiang);
	}
	return result;
}
double sqrt(int n)
{
	int wei=7;
	double result=1.0;
	double temp=double(n-1);
	for (int i = 0; i < wei; i++)
	{
		result+=every(n,wei);
	}
	return result;
}
int  main()
{
	//cout<<sqrt(2);
	cout<<jiecheng(10);
	cout<<xishu(2,0)<<" "<<xishu(2,1)<<" "<<xishu(2,2)<<" "<<xishu(2,3)<<" "<<endl;
	cout<<every(1,0)<<" "<<every(2,1)<<" "<<every(2,2)<<" "<<every(2,3)<<" ";
	cout<<"hello world!"<<endl<<sqrt(2);
return 0;
}