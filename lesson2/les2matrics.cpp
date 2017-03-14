#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	int m,n;
	struct LNode *next;
	struct LNode *Qnext;
}LNode,*LinkList;
typedef int* intMatrixptr;
class DynamicMatrix
{
public:
	DynamicMatrix();

private:
	int m,n;
	int *matrix;
};
DynamicMatrix(){

	
}


int main()
{
	
	return 0;

}