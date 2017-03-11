#include <iostream>
#include <windows.h>
using namespace std;
int displayfloat(float temp)
{
    int onezero[32]={0};
_asm{
        mov eax,32;
        mov ecx,eax;
        lea ebx,onezero;
        mov eax,temp;
        mov esi,0;
    s:  clc
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
    cout<<"   ";
    return 0;   
}
int displayint(int temp)
{
    int onezero[32]={0};
_asm{
        mov eax,32;
        mov ecx,eax;
        lea ebx,onezero;
        mov eax,temp;
        mov esi,0;
    s:  clc
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
    cout<<"   ";
    return 0;   
}
void nixu()
{
	int i=0;
	cout<<"-----------------------------------------------------------";
	cout<<"-----------------------------------------------------------";
	cout<<"-----------------"<<endl;
	for(i=63;i>=32;i--)
		cout<<((i-i%10)/10)<<" ";
	cout<<"   ";
	for(i=31;i>=0;i--)
		cout<<((i-i%10)/10)<<" ";
	//cout<<"   ";
	cout<<endl;
	for(i=63;i>=32;i--)
		cout<<i%10<<" ";
	cout<<"   ";
	for(i=31;i>=0;i--)
		cout<<i%10<<" ";
	cout<<endl;
	cout<<"----------------------------------------------------------";
	cout<<"-----------------------------------------------------------";
	cout<<"-----------------"<<endl;
}
float double2flo(double temp)
{
	int *pint =(int*)&temp;
	int hightemp=0;
	int lowtemp=0;
	int i=0;
	float resultfloat=0.0;
	_asm{
		mov eax,pint
		mov eax,[eax]
		mov lowtemp,eax
	}
	pint++;
	_asm{
		mov eax,pint 
		mov eax,[eax]
		mov hightemp,eax
	}
    cout<<endl;
	int mantissa=0;
	//_asm{//exponet
	//	mov eax,hightemp
	//	and eax,0x7f800000
	//	or resultfloat,eax;
	//}
	_asm{
		mov eax,hightemp
		//and eax,0xff00000
		and eax,0x7ff00000
		mov mantissa,eax
	}
	mantissa=mantissa>>20;
	mantissa=mantissa-1023+127;
	mantissa=mantissa<<23;
	cout<<"mantissa:"<<mantissa<<endl;
	displayint(mantissa);
	_asm {
		mov eax,mantissa
		or resultfloat,eax
	}
	_asm{//signflag
		mov eax,hightemp
		and eax,0x80000000
		cmp eax,0
		jz ok
		or resultfloat,0x80000000
		ok:
	}
	_asm{//compute mantissa
		mov eax,hightemp
		and eax,0xfffff
		mov mantissa,eax
	}
	mantissa=mantissa<<3;
	_asm {//mantissa
		mov eax,mantissa
		or resultfloat,eax
	}
	nixu();
	_asm{//high pos:52~32
		mov eax,hightemp

	}
return resultfloat;
}
double flo2double(float temp)
{
	double resultdouble=0.0;
	int mantissa=0;
	int highdouble=0;
	int lowdouble=0;
	_asm{//exponent
		mov eax,temp
		and eax,0x7f800000
		shr eax,23
		sub eax,127
		add eax,1023
		shl eax,20
		mov highdouble,eax
	}

	if(temp<0)//sign flag
	_asm or highdouble,0x80000000
    _asm{//mantissa
    	mov eax,temp
    	and eax,0x7fffff
    	shr eax,3
    	//31-22=9//63-51=12//12-9=3
    	or highdouble,eax
    }
    int *pint=(int *)&resultdouble;
    pint++;
    _asm{
    	mov esi,highdouble
    	mov eax,pint
    	mov [eax],esi;
    }

	cout<<"highdouble:"<<highdouble<<endl;
	displayint(highdouble);
	cout<<endl<<"resultdouble:"<<resultdouble<<endl;
return resultdouble;
}
int main()
{

	double tempdouble=520.131;
	cout<<double2flo(tempdouble)<<endl;
//qiuri();
	float tempfloat=3.0;

	cout<<"flo2double:"<<flo2double(3.0)<<endl;

	system("pause");
	return 0;
}