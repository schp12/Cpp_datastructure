#include <bits/stdc++.h>
using namespace std;
void yerdegistirme(int* eski,int* yeni){
int temp=*eski;
*eski=*yeni;
*yeni=temp;
}
void selectsort(int dizi[],int n)
{
	int i,j,min;
for(i=0;i<n-1;i++){
min=i;
for(j=i;j<n;j++){
	
if(dizi[j]<dizi[min])
	min=j;	
		};
yerdegistirme(&dizi[min],&dizi[i]);	
	};	
};

void bastir(int dizi[],int boyut){
int i;
for(i=0;i<boyut;i++){
	cout <<dizi[i]<<" ";
	};
cout<<endl;
	
};	
	
int main(){

int dizi[]={5,2,3,4,6,7,1};
int n= sizeof(dizi)/sizeof(dizi[0]);
selectsort(dizi, n);
cout<<"sorted dizi: \n";
bastir(dizi, n);
return 0;	
};
