#include <iostream>
#include <vector>
using namespace std;
int displayint(int temp)
{
	int onezero[32]={0};
_asm{
		mov eax,32;
		mov ecx,eax;
		lea ebx,onezero;
		mov eax,temp;
		mov esi,0;
	s:	clc
		shl eax,1;
		mov edx,0;
		rcl edx,1;
		mov [ebx+esi*4],edx;
		inc esi;
		loop s;
	}
	for(int i=0;i<32;i++)
	{
		cout<<onezero[i]<<" ";
	}
	cout<<endl;
	return 0;	
}
int displayfloat(float temp)
{
	int onezero[32]={0};
_asm{
		mov eax,32;
		mov ecx,eax;
		lea ebx,onezero;
		mov eax,temp;
		mov esi,0;
	s:	clc
		shl eax,1;
		mov edx,0;
		rcl edx,1;
		mov [ebx+esi*4],edx;
		inc esi;
		loop s;
	}
	for(int i=0;i<32;i++)
	{
		cout<<onezero[i]<<" ";
	}
	cout<<endl;
	return 0;	
}
int displaydouble(double temp)
{
	int onezero[64]={0};
_asm{
		mov eax,32;
		mov ecx,eax;
		lea ebx,onezero;
		mov eax,temp;
		mov esi,0;
	s:	clc
		shl eax,1;
		mov edx,0;
		rcl edx,1;
		mov [ebx+esi*4],edx;
		inc esi;
		loop s;
	}
	for(int i=0;i<64;i++)
	{
		cout<<onezero[i]<<" ";
	}
	cout<<endl;
	return 0;	
}

int main()
{
	int a=15;
	
	displayint(a);
	float b=(float)a;
	displayfloat(b);
	double c=(double)a;
	displaydouble(c);
	return 0;
}