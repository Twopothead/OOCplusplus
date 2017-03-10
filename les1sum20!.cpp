#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;
_int64  power(_int64 x)
{
	if ((x==1)){
		return 1;
	}
	else return x*power(x-1);
}
_int64 sumpower(_int64 x)
{
	_int64 temp;
	_int64 sum=0;
	for(int i=1;i<=x;i++){ 
		 temp=(_int64)i;
		 temp=power(temp);
		 cout<<i<<"!=";
		printf("%I64d",temp);
		cout<<endl;
		sum+=temp;
	}
	return sum;
}
int main()
{
   _int64 sum=0;
	sum=sumpower(20);
	printf("The sum of them is :%I64d",sum);
	cout<<endl;
	system("pause");

	return 0;
}