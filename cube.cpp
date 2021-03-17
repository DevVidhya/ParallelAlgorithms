#include<iostream>
#include<pthread.h>
using namespace std;

int n,A[100][100][100],B[100][100][100],C[100][100][100],part=0,a[100][100],b[100][100];

void* multiply(void* arg)
{
int i=part/(n*n), j=(part%(n*n))/n, k=part%n;
C[i][j][k]=A[i][j][k]*B[i][j][k];
part++;
}

int main()
{

cout<<"\nEnter n : ";
cin>>n;

cout<<"\nEnter elements of first matrix \n";
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>a[i][j];

cout<<"\nEnter elements of second matrix \n";
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>b[i][j];

for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
for(int k=0;k<n;k++)
A[j][i][k]=a[i][j];

for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
for(int k=0;k<n;k++)
B[i][k][j]=b[i][j];

/*
cout<<"\n \n \nElements of A cube \n";
for(int i=0;i<n;i++)
{
cout<<"\n \n";
for(int j=0;j<n;j++)
{
cout<<"\n";
for(int k=0;k<n;k++)
cout<<A[i][j][k]<<" ";
}
}

cout<<"\n \n \nElements of B cube \n";
for(int i=0;i<n;i++)
{
cout<<"\n \n";
for(int j=0;j<n;j++)
{
cout<<"\n";
for(int k=0;k<n;k++)
cout<<B[i][j][k]<<" ";
}
}
*/

pthread_t threads[64];
	
for(int i=0;i<64;i++)
pthread_create(&threads[i],NULL,multiply,(void*)NULL);


/*
cout<<"\n \n \nElements of C cube \n";
for(int i=0;i<n;i++)
{
cout<<"\n \n";
for(int j=0;j<n;j++)
{
cout<<"\n";
for(int k=0;k<n;k++)
cout<<C[i][j][k]<<" ";
}
}
*/

for(int i=1;i<n;i++)
for(int j=0;j<n;j++)
for(int k=0;k<n;k++)
C[0][j][k]+=C[i][j][k];

cout<<"\n \n \nElements of result matrix ";
for(int j=0;j<n;j++)
{
cout<<"\n";
for(int k=0;k<n;k++)
cout<<C[0][j][k]<<" ";
}
cout<<"\n";

return 0;
}
