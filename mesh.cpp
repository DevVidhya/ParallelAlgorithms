#include<iostream>
#include<pthread.h>
using namespace std;

int m,n,k,C[100][100]={0},part=0,a[100][100],b[100][100];

void* multiply(void* arg)
{
int i=part/k, j=part%k;
for(int temp=0;temp<n;temp++)
C[i][j]+=a[i][temp]*b[temp][j];
part++;
}

int main()
{

cout<<"\nEnter m, n, k values : ";
cin>>m;
cin>>n;
cin>>k;

cout<<"\nEnter elements of first matrix \n";
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
cin>>a[i][j];

cout<<"\nEnter elements of second matrix \n";
for(int i=0;i<n;i++)
for(int j=0;j<k;j++)
cin>>b[i][j];


int t=m*k;
pthread_t threads[t];
	
for(int i=0;i<t;i++)
pthread_create(&threads[i],NULL,multiply,(void*)NULL);


cout<<"\n \n \nElements of result matrix ";
for(int i=0;i<m;i++)
{
cout<<"\n";
for(int j=0;j<k;j++)
cout<<C[i][j]<<" ";
}
cout<<"\n";

return 0;
}
