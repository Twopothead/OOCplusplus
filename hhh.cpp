#include <iostream>
#include <cstdio>
using namespace std;
_int64  power(_int64 x)
{
	if ((x==1)){
		return 1;
	}
	else return x*power(x-1);

}
void sumpower(_int64 x)
{
	_int64 temp;
	for(int i=1;i<=x;i++)
		{  temp=(_int64)i;
			printf("%I64d",power(temp));
			cout<<endl;
}
	//cout<<power(i)<<"  "<<endl;
}
int main()
{
	//cout<<"hello world"<<endl;
	//sumpower(20);
	_int80 x;
	return 0;
}