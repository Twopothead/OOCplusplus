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
	MulMatrix(int x);
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
	cout<<endl;
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
	int i,j;
intMatrixptr *rotationmatrix=new intMatrixptr[n];
	for(i=0;i<n;i++)
			rotationmatrix[i]=new int[m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
  		  rotationmatrix[i][j]=matrix[m-1-j][i];
	}
	intMatrixptr *tempMat;
	tempMat=matrix;
	for (i = 0; i < m; i++)
	    delete[] matrix[i];
	delete[] tempMat;
	matrix=rotationmatrix;
	int temp;
	temp=m;
	m=n;
	n=temp;

}
DynamicMatrix::transportMatrx(){
	int i,j;
	intMatrixptr *transportmatrix=new intMatrixptr[n];
	for(i=0;i<n;i++)
			transportmatrix[i]=new int[m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
  		  transportmatrix[i][j]=matrix[j][i];
	}
	intMatrixptr *tempMat;
	tempMat=matrix;
	for (i = 0; i < m; i++)
	    delete[] matrix[i];
	delete[] tempMat;
	matrix=transportmatrix;
	int temp;
	temp=m;
	m=n;
	n=temp;
}
DynamicMatrix::MulMatrix(int x){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			matrix[i][j]*=x;
	}
}
DynamicMatrix::TestMatrix(){
	displayMatrix();
	MulMatrix(8);
	displayMatrix();
	transportMatrx();
	displayMatrix();
	rotationMatrix();
	displayMatrix();
}
int main()
{
	DynamicMatrix Mat(4,6);
	Mat.TestMatrix();
	system("pause");
	return 0;

}