#include <iostream>
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
    cout<<endl;
    return 0;   
}
int float2int(const float flo)
{
    int hello,resultint,sign,exponent,mantissa=0;
    //float temp=3.0;
    //temp=*(float *)&flo;
    float temp=0.0;
    temp=*(float*)&flo;


    _asm{
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        mov eax,temp;
        shr eax,31;
        mov sign,eax;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        mov eax,temp;
        and eax,0x7f800000;
        shr eax,23;
        sub eax,127;
        mov exponent,eax;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
       cmp exponent,0
        jb expnotpos
        //mov resultint,1
        //mov ecx,exponent
        //shl eax,cl
        
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
       mov cl,al
        mov esi,1
        shl esi,cl
        mov eax,temp
        and eax,0x7fffff
        mov ecx,23
        sub ecx,exponent
        shr eax,cl
        add eax,esi
        mov hello,eax

       // displayint(hello);
    mov resultint,eax
        //add resultint,eax

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
         cmp sign,1
         jnz expnotpos
         neg resultint
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
    //displayint(hello);
   // cout<<"hello:"<<hello<<endl;
    //displayfloat(temp);
//cout<<"sign:"<<sign<<endl;
//cout<<"exponent:"<<exponent<<endl;

    displayint(resultint);
    return resultint;
}

int int2float(const int integer)
{
    cout<<endl<<"integer-3:"<<endl;
    displayint(-3);
    cout<<endl<<"integer3:"<<endl;
    displayint(3);
    cout<<endl<<"float3:"<<endl;
    displayfloat(3.0);
    cout<<endl<<"float-3:"<<endl;
    displayfloat(-3.0);
    float resultfloat=0.0;

 int world;
    int hello,resultint,exponent,mantissa=0;
   // float temp=0.0;
    //temp=*(int*)&integer;
    int sign=0;
     int integerpos;
     integerpos=(integer>=0)?integer:(-integer);
     if(integer<0)
        sign=1;

    displayint(integer);
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
        //world=((mantissa&0x80000000)!=0)?1:0;
        if(((mantissa&0x80000000)!=0)?1:0)
            break;

    }
    i=32-i;
    i--;
    exponent=i;
    exponent+=127;
    exponent=exponent<<23;
    displayint(exponent);

    cout<<"exponent="<<exponent<<endl;
    mantissa=mantissa<<1;
    mantissa=mantissa>>9;
    //_asm and mantissa,0xff800000
    _asm and mantissa,0x7fffff
    _asm{
        mov eax,resultfloat
        or eax,mantissa
        or eax,exponent
        mov resultfloat,eax

    }
if(sign!=0)
    _asm or resultfloat,0x80000000
   // cout<<"mantissa:"<<endl;
    //displayint(mantissa);

    cout<<"resultfloat:"<<endl;
    displayfloat(resultfloat);
   // displayint(3);
    //displayfloat(3.0);


    return resultfloat;
}
int main()
{
    float numfloat=4.9;
    int tempint=0;
tempint=float2int(numfloat);
cout<<endl<<"float2int:"<<numfloat<<"->"<<tempint<<endl;
   int numinteger=-3;
   float tempflo=0.0;
tempflo=int2float(numinteger);
cout<<"int2float:"<<numinteger<<"->"<<tempflo<<endl;
displayint(-3);
displayfloat(-3.0);

   // i=float2int(a);
    //cout<<i;
   // cout<<a<<endl;
    return 0;
}