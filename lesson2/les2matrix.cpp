#include <iostream>
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
void labelList(LinkList &L,int M,int N)
{
	LinkList p;
	p=L->next;
	int m=0,n=0;
	for(p=L->next;p->next!=NULL;p=p->next,n++)
	{
	   n=n%N;
	   p->n=n;
	   if(p->n==N-1)
	   	m++;
	   p->m=m;
	}
}
void CreatList(LinkList &L,int m,int n)
{
	LinkList p,r;
	r=L;
	int i=0;
	for(i=0;i<=m*n;i++)
	{
		/*p=(LinkList)new LNode;
		p->data=i;
		r->next=p;
		r=p;
		p->next=NULL;
		*/
		p=(LinkList)new LNode;
		p->data=i;
		r->next=p;
		r=p;
		p->next=NULL;
		p->Qnext=NULL;

	}
labelList(L,m,n);

}
void InitList(LinkList &L)
{
	L=(LinkList) new LNode;
	L->next=NULL;
	L->Qnext=NULL;
}
void displayMatrix(LinkList &L,int m,int n)
{
	LinkList p;
	cout<<endl;
	for(p=L->next;p->next!=NULL;p=p->next)
	{
		cout<<p->data<<"\t";
		if((p->n)==n-1)
			cout<<endl;
	}
	cout<<endl;

}
void displayMatrixLabel(LinkList &L,int m,int n)
{
	LinkList p;
	cout<<endl;
	for(p=L->next;p->next!=NULL;p=p->next)
	{
		cout<<"("<<p->m<<","<<p->n<<")"<<"\t";
		if((p->n)==n-1)
			cout<<endl;
	}
	cout<<endl;

}
void ListMatMul(LinkList &L,int num)
{
	LinkList p;
	for(p=L->next;p->next!=NULL;p=p->next)
		p->data*=num;
}
void ListMatTraverse(LinkList &L,int N,int M)
{
	LinkList p;
	labelList(L,N,M);

}
void ListMatrotate(LinkList &L,int M,int N)
{
	LinkList p;
	for(p=L->next;!((p->m==M)&&(p->n==0));p=p->next)
		;


}
void ListMatrix()
{
	LinkList L;
	InitList(L);
	int m=4,n=6;
	CreatList(L,m,n);
	cout<<endl<<"ListMatrix"<<endl;
	displayMatrix(L,m,n);
	ListMatMul(L,8);
	displayMatrix(L,m,n);
	ListMatTraverse(L,n,m);
	displayMatrix(L,n,m);
	ListMatTraverse(L,m,n);
	displayMatrixLabel(L,m,n);

}
void DynamicMatrix()
{
	int m=4,n=6;
	int i,j;
	typedef int* intMatrixptr;
	intMatrixptr *matrix=new intMatrixptr[m];
	for(i=0;i<m;i++)
			matrix[i]=new int[n];
	int count=0;
	for(i=0;i<m;i++)
		{for(j=0;j<n;j++)
		{
			count++;
			matrix[i][j]=count;
		}
	}
			//matrix[i][j]=rand()%(m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<matrix[i][j]<<"\t";
		cout<<endl;
	}
	cout<<endl;
	int temp=0;
	//for(i=0;i<m;i++){
      //  for(j=0;j<=(int)n/2;j++)
        //{
          //  temp=matrix[i][j];
           // matrix[i][j]=matrix[i][n-j-1];
           //matrix[i][n-j-1]=temp;
        //}
	//}
	intMatrixptr *traversematrix=new intMatrixptr[n];
	for(i=0;i<n;i++)
			traversematrix[i]=new int[m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
  		  traversematrix[i][j]=matrix[j][i];
  		  cout<<traversematrix[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	int num=5;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			cout<<matrix[i][j]*num<<"\t";
		cout<<endl;
	}
	intMatrixptr *rotatematrix=new intMatrixptr[n];
	for(i=0;i<n;i++)
			rotatematrix[i]=new int[m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
  		  rotatematrix[i][j]=matrix[m-1-j][i];
		}
	}
	cout<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<rotatematrix[i][j]<<"\t";
		cout<<endl;
	}
	for(i=0;i<m;i++)
		delete[] matrix[i];
	delete []matrix;
	for(i=0;i<n;i++)
		delete[] rotatematrix[i];
	delete []rotatematrix;
	for(i=0;i<n;i++)
		delete[] traversematrix[i];
	delete []traversematrix;
	

}

int main()
{
	DynamicMatrix();
	ListMatrix();
	return 0;
}
/*#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int **pmat;
	int n;
	int i=0;
	int j=0;
	cout<<"input n:";
	cin>>n;
	cout<<endl;
	pmat=(int **)malloc(sizeof(int*)*n);
	for ( i = 0; i < n; i++ )
	{
		pmat[i]=(int *)malloc(sizeof(int*)*n);
		
	}
	int count=0;
	for ( i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			//cin>>pmat[i][j];
			//pmat[i][j]=count;
			pmat[i][j]=(rand()%(n*n));
			//count++;
		}
		
	}
	for ( i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout<<pmat[i][j]<<"    ";
		}
		cout<<endl;
	}
	return 0;
}
*/
