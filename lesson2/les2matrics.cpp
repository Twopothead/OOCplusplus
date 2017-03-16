#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <stack>
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
class ListMatrics{
public:
	ListMatrics(int M,int N);
	displayMatrics();
	~ListMatrics();
	reflextionMatrics();
	rotationMatrics();
	transportMatrics();
	mulMatrics(int x);
	TestMatrics();
private:
	LinkList L;
	int m;
	int n;

};
ListMatrics::ListMatrics(int M,int N)
{
	L=(LinkList)new LNode;
	L->next=NULL;
	LinkList p,r;
	int i;
	m=M;
	n=N;
	r=L;
	for(i=0;i<m*n;i++){
		p=(LinkList)new LNode;
		p->data=i;
		r->next=p;
		r=p;
		p->next=NULL;
	}

}
ListMatrics::~ListMatrics()
{
	LinkList p,r;
	p=L;
	while(p->next!=NULL){
	LinkList Deltmp=p;
	p=p->next;
	delete Deltmp;
	}
}
ListMatrics::displayMatrics()
{
	LinkList p;
	p=L->next;
	int i;
	for( i=0;i<m*n;i++){
		cout<<p->data<<"\t";
		p=p->next;
		if((i+1)%m==0)
			cout<<endl;
	}
	cout<<endl;

}
ListMatrics::rotationMatrics()
{
	transportMatrics();
	reflextionMatrics();
}
ListMatrics::reflextionMatrics()
{
	vector<LinkList> tempVec;
	LinkList p;
	p=L->next;
	tempVec.push_back(p);
	int i,j;
	for( i=0;i<m*n;i++){
		p=p->next;
		if((i+1)%m==0&&p!=NULL)
			tempVec.push_back(p);
	}
	LinkList temphead;
	stack<int> tempS;
	for(i=0;i<tempVec.size();i++)
	{
			temphead=tempVec[i];
			for(j=0;j<m;j++){
				tempS.push(temphead->data);
				temphead=temphead->next;
			}
			temphead=tempVec[i];
			for(j=0;j<m;j++){
				temphead->data=tempS.top();
				temphead=temphead->next;
				tempS.pop();
			}
	}

}
ListMatrics::transportMatrics()
{
	vector<LinkList> tempVec;
	LinkList p;
	p=L->next;
	tempVec.push_back(p);
	int i,j;
	for( i=0;i<m*n;i++){
		p=p->next;
		if((i+1)%m==0&&p!=NULL)
			tempVec.push_back(p);
	}
	LinkList temphead;
	for(i=0;i<tempVec.size();i++){
			temphead=tempVec[i];
	}
	int *dataint;
	dataint =new int [m*n];
	int count=0;
	for(j=0;j<m;j++){
	for(i=0;i<tempVec.size();i++){
			dataint[count]=tempVec[i]->data;
			count++;
			tempVec[i]=tempVec[i]->next;
		}
	}
	int tempmn;
	tempmn=m;
	m=n;
	n=tempmn;
	LinkList tran;
	tran=L->next;
	for( i=0;i<m*n;i++){
	tran->data=dataint[i];
	   tran=tran->next;
	}

}
ListMatrics::mulMatrics(int x)
{
	LinkList p;
	p=L->next;
	int i;
	for( i=0;i<m*n;i++){
		p->data*=x;
		p=p->next;
	}
}
ListMatrics::TestMatrics()
{
	cout<<"orginal Matrics:"<<endl;
	displayMatrics();
	cout<<"reflextionMatrics:"<<endl;
	reflextionMatrics();
	displayMatrics();
	cout<<"transportmatrics:"<<endl;
	transportMatrics();
	displayMatrics();
	cout<<"rotationmatrics:"<<endl;
	rotationMatrics();
	displayMatrics();
	cout<<"mulMatrics:e.g x=3"<<endl;
	mulMatrics(3);
	displayMatrics();
}
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
	int i,j;
	int temp;
	for(i=0;i<m;i++){
		for(j=0;j<n/2;j++){
			temp=matrix[i][j];
			matrix[i][j]=matrix[i][n-1-j];
			matrix[i][n-1-j]=temp;
		}
	}

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
	cout<<"orginal Matrix:"<<endl;
	displayMatrix();
	cout<<"transportmatrix:"<<endl;
	transportMatrx();
	displayMatrix();
	cout<<"rotationMatrix:"<<endl;
	rotationMatrix();
	displayMatrix();
	cout<<"reflextionMatrix:"<<endl;
	reflextionMatrix();
	displayMatrix();
	cout<<"MulMatrix:e.g x=3"<<endl;
	MulMatrix(3);
	displayMatrix();
}
int main()
{

	ListMatrics matrics(4,6);
	matrics.TestMatrics();
	cout<<"----------------------------------"<<endl;
	DynamicMatrix Mat(4,6);
	Mat.TestMatrix();
	system("pause");
	return 0;
}