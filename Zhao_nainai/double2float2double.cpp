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

float double2float(double doublenum)
{
    float resultfloat;
    int dnumlow=0;
    int dnumhigh=0;
   _asm{
    lea edx,doublenum
    mov eax,[edx]
    mov dnumlow,eax
    mov eax,[edx+32]
    mov dnumhigh,eax
   }
   displayint(dnumlow);
   displayint(dnumhigh);
   

    return resultfloat;
}
double float2double(float floatnum)
{
    double resultdouble;
    _asm{

    }

    return resultdouble;
}

int main()
{
    double2float(3.0);
    
    return 0;
}