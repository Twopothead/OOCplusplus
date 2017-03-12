#include <iostream>
#include <windows.h>
using namespace std;
int displayfloat(float temp);
int displayint(int temp);
void displaynumber();
void displaydouble(double temp);
int float2int(const float flo);
int int2float(const int integer);
double flo2double(float temp);
float double2flo(double temp);
double int2double(int temp);
int double2int(double temp);
void Demodouble2flo();
void Demoflo2double();
void Demoint2flo();
void Demoflo2int();
void Demo();
void haha();
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
void displaynumber()
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
void displaydouble(double temp)
{
	displaynumber();
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
	displayint(hightemp);
	displayint(lowtemp);
    cout<<endl;
	int mantissa=0;
}
int float2int(const float flo)
{
    int hello,resultint=0,sign=0,exponent=0,mantissa=0;
    float temp=0.0;
    temp=*(float*)&flo;
    float temppos=0;
    temppos=temp;
    int flag=0;
    if(temppos<0)
    {
        flag=1;
        temppos=-temppos;
    }
    _asm{
        mov eax,temppos;
        shr eax,31;
        mov sign,eax;
        mov eax,temppos;
        and eax,0x7f800000;
        shr eax,23;
        sub eax,127;
        mov exponent,eax;
        cmp exponent,0
        jb expnotpos
        mov cl,al
        mov esi,1
        shl esi,cl
        mov eax,temppos
        and eax,0x7fffff
        mov ecx,23
        sub ecx,exponent
        shr eax,cl
        add eax,esi
        mov hello,eax
        mov resultint,eax
        cmp sign,1
        jnz expnotpos
        neg resultint
expnotpos:
        cmp exponent,0
        jnz nextjudge
        mov resultint,1
        nextjudge:
        cmp sign,1
        jnz ok
        mov resultint,-1
        ok:nop
    }
    if (flag!=0)
    {
       resultint=-resultint;
    }
    //displayint(resultint);
    return resultint;
}

int int2float(const int integer)
{
    float resultfloat=0.0;
    int hello,resultint,exponent,mantissa=0;
    int sign=0;
     int integerpos;
     integerpos=(integer>=0)?integer:(-integer);
     if(integer<0)
        sign=1;
    //displayint(integer);
    int k,i=0;
    _asm{
        mov eax,integerpos
        mov mantissa,eax
        mov resultfloat,eax
        and resultfloat,0x80000000
    }
    for (i = 1; i <= 32; i++)
    {
        mantissa=mantissa<<1;
        if(((mantissa&0x80000000)!=0)?1:0)
            break;
    }
    i=32-i;
    i--;
    exponent=i;
    exponent+=127;
    exponent=exponent<<23;
    //displayint(exponent);
    //cout<<"exponent="<<exponent<<endl;
    mantissa=mantissa<<1;
    mantissa=mantissa>>9;
    _asm and mantissa,0x7fffff
    _asm{
        mov eax,resultfloat
        or eax,mantissa
        or eax,exponent
        mov resultfloat,eax
    }
    if(sign!=0)
    _asm or resultfloat,0x80000000
    //cout<<"resultfloat:"<<endl;
    //displayfloat(resultfloat);
    return resultfloat;
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
  //  cout<<endl;
	int mantissa=0;
	_asm{
		mov eax,hightemp
		and eax,0x7ff00000
		mov mantissa,eax
	}
	mantissa=mantissa>>20;
	mantissa=mantissa-1023+127;
	mantissa=mantissa<<23;
	//cout<<"mantissa:"<<mantissa<<endl;
	//displayint(mantissa);
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
	//displaynumber();
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
	//cout<<"highdouble:"<<highdouble<<endl;
	//displayint(highdouble);
	//cout<<endl<<"resultdouble:"<<resultdouble<<endl;
	return resultdouble;
}
double int2double(int temp)
{
	return flo2double(int2float(temp));
}
int double2int(double temp)
{
	return  float2int((double2flo(temp)));
}
void Demoflo2int()
{
    float numfloat=-520.131;
    int tempint=0;
    tempint=float2int(numfloat);
    cout<<"float2int:"<<numfloat<<"->"<<tempint<<endl;
    cout<<numfloat<<"(float):"<<endl;
  displayfloat(numfloat);
   cout<<tempint<<"(int):"<<endl;
  displayint(tempint);
}
void Demoint2flo()
{
     int numinteger=520;
     float tempflo=0.0;
     tempflo=int2float(numinteger);
     cout<<"int2float:"<<numinteger<<"->"<<tempflo<<endl;
     cout<<numinteger<<"(int):"<<endl;
     displayint(numinteger);
     cout<<tempflo<<"(float):"<<endl;
     displayfloat(tempflo);
}
void Demodouble2flo()
{
	double tempdouble=-520.131;
	cout<<"double2float:"<<tempdouble<<"->"<<double2flo(tempdouble)<<endl;
}
void Demoflo2double()
{
	float tempfloat=520;
	cout<<"float2double:"<<tempfloat<<"->"<<flo2double(tempfloat)<<endl;
}
void Test()
{
	Demoflo2double();
	Demodouble2flo();
	double i=3.0;
	displaydouble(i);
}
void haha()
{
	
	cout<<endl;
	for(int i=0;i<30;i++)
	{
	cout<<"#";
	Sleep(100);
	}
	cout<<endl<<"....done"<<endl;
}
void Demo()
{	int    tempint=-520;
	float  tempfloat=-520.13;
	double tempdouble=-520.13;
	int    resultint=0;
	float  resultfloat=0.0;
	double resultdouble=0.0;
	cout<<"Demo:	int <-> float <-> double:"<<endl<<endl;
	haha();
	cout<<"Demo: double2float:"<<endl;
	haha();
	cout<<endl<<endl<<"double2float:"<<tempdouble<<"(double)"<<"->"<<double2flo(tempdouble)<<"(float)"<<endl;
	cout<<tempdouble<<"(double):"<<endl;
	displaydouble(tempdouble);
	cout<<endl<<double2flo(tempdouble)<<"(float):"<<endl;
	displayfloat(double2flo(tempdouble));
	cout<<endl<<endl<<endl;
	cout<<endl<<endl<<"Demo: float2double:"<<endl;
	haha();
	cout<<endl<<"float2double:"<<tempfloat<<"(float)"<<"->"<<flo2double(tempfloat)<<"(double)"<<endl;
	cout<<tempfloat<<"(float):"<<endl;
	displayfloat(tempfloat);
	cout<<endl<<flo2double(tempfloat)<<"(double):"<<endl;
	displaydouble(flo2double(tempfloat));
	cout<<endl<<endl<<"Demo:int2float";
	haha();
	cout<<endl<<"int2float:"<<tempint<<"(int)"<<"->"<<int2float(tempint)<<"(float)"<<endl;
	cout<<tempint<<"(int):"<<endl;
	displayint(tempint);
	cout<<endl<<int2float(tempint)<<"(float):"<<endl;
	displayfloat(int2float(tempint));
	cout<<endl<<endl<<"Demo:float2int";
	haha();
	cout<<endl<<"float2int:"<<tempfloat<<"(float)"<<"->"<<float2int(tempfloat)<<"(int)"<<endl;
	cout<<tempfloat<<"(float):"<<endl;
	displayfloat(tempfloat);
	cout<<endl<<float2int(tempfloat)<<"(int):"<<endl;
	displayint(float2int(tempfloat));
	haha();
}
int main()
{
	Demo();
	system("pause");
	return 0;
}