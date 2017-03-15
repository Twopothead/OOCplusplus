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
	DynamicMatrix(int M,int N);
	~DynamicMatrix();
	displayMatrix();
	MulMatrix();
	reflextionMatrix();
	rotationMatrix();
	transportMatrx();
	TestMatrix();
private:
	int m,n;
	intMatrixptr *matrix;
};
DynamicMatrix::DynamicMatrix(int M,int N){
	m=M;
	n=N;
	int i=0;
	int j=0;
	int count=0;
	matrix=new intMatrixptr[m];
	for(i=0;i<m;i++)
			matrix[i]=new int[n];

	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			count++;
			matrix[i][j]=count;
		}
	}
}
DynamicMatrix::displayMatrix(){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
}
DynamicMatrix::~DynamicMatrix()
{
	int i=0;
	for(i=0;i<m;i++)
		delete[] matrix[i];
	delete []matrix;
}
DynamicMatrix::reflextionMatrix(){

}
DynamicMatrix::rotationMatrix(){

}
DynamicMatrix::transportMatrx(){

}
DynamicMatrix::TestMatrix(){
	displayMatrix();

}
int main()
{
	DynamicMatrix Mat(4,6);
	Mat.TestMatrix();
	return 0;

}