#include <bits/stdc++.h>
using namespace std;

void insert(int dizi[], int n)
{
int i,j,temp;

for(i=1;i<n;i++)
{
temp=dizi[i];
j=i-1;
while(j>=0 && dizi[j]>temp)
	{
	dizi[j+1]=dizi[j];
	j=j-1;
	}	
dizi[j+1]=temp;	
} 		
}

void bastir(int dizi[],int n)
{
 int i;
 for(i=0;i<n;i++)
 	cout<<dizi[i]<<" ";
cout<<endl;
 
	
	
}

int main()
{
	int dizi[]={4,2,3,5,6,7,1,12,45,9};
	int n=sizeof(dizi)/sizeof(dizi[0]);
	insert(dizi,n);
	bastir(dizi,n);
	
	return 0;
}

