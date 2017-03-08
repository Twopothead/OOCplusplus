#include <iostream>  
  
using namespace std;  
  
void main()  
{  
    /************************************************************************/  
    /* 结论： 
        Memory中存储的是补码，是根据存入的具体数据的值进行转换为二进制 
        后的形式，如果超过该数据类型范围则不知道存的形式是什么了，这个 
        应该是编译器相关的，对越界数的处理方式；（无论存入的时候是用什 
        么进制表示的，在这里注意+/-单目运算符的作用） 
 
        无论要做什么运算都要先看这个数存入内存是什么样子的； 
 
        类型提升/截断的时候都是对内存中数据的操作，提升的时候就是需要 
        进行扩位：对无符号数扩位的时候直接把扩出的位上补零即可(因为unsigned都是正数)；有符号 
        数进行扩位，则进行符号位扩展(sign extension)如果是整数即原最高位 
        是零则补零，如果是负数即原最高位是1则全补1;进行数据截断的时候是 
        从低位开始数位数然后截断，这里注意我们使用的一般都是小端机(little Endian) 
         
        类型强制转换其实也是对内存中存储的数据的一种呈现方式而已，如：内存 
        中是8000的时候(即1000 0000 0000 0000)，如果用unsigned short int则打印出 
        来的是2的15次方，如果用short int则打印出来是负2的16次方 
         
        在进行算术运算和双目的位运算的时候如果操作数数据类型不一致，首先进 
        行数据 Arithmetical Conversion类型提升(其实提升就是进行扩位，然后把扩位后的内存二进制代码强制转为某种数据类型之后进行打印)，然后       才开始运算 
         
        在进行单目位运算的时候，首先进行整型提升，然后开始运算Integer Promotion*/  
    /************************************************************************/  
    //目的：计算机内部存储形式（无符号数、有符号正数、有符号负数、直接十六进制；及其  
    //扩位后规则及其扩位后的存储形式）  
    unsigned char uch1 = 0x80; //80  
    unsigned char uch2 = 128;  //80   
  
    //注意+/-作为单目运算符的作用和意义，就是让存入内存的时候，最高位写为1  
    //同时要注意各个数据类型的表示范围  
    char sch1 = -0x7f; //Memory中应该是81  
    char sch2 = 0x80;   
    cout << (short int)sch1 << endl;//-127  
    cout << (short int)sch2 << endl;//-128  
  
    unsigned usch3 = 0x7f;  
    unsigned ushc4 = 0x80;  
    cout << (short int)usch3 << endl;//127  
    cout << (short int)ushc4 << endl;//128  
  
    char sch3 = 127;  
    char sch4 = -128;  
    cout << (short int)sch3 << endl;//127  
    cout << (short int)sch4 << endl;//-128  
  
    unsigned uch3 = 0;  
    unsigned uch4 = 255;  
    cout << (short int)uch3 << endl;//0  
    cout << (short int)uch4 << endl;//255  
  
    char a = -0x80;  
    short int b = 0x7f80;  
    short int result = a&b;//0111 1111 1000 0000  
  
    cout << result <<endl;  
  
}