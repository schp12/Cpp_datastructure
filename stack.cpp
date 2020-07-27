#include <stdio.h>
#include <stdlib.h>

int *dizi; // diziyi dinamik tanimliyoruz.
int boyut =2;
int tepe =0;

int pop(){
	if(dizi==NULL)
	printf("dizi bos");
	if(tepe <=boyut/4){
		int*dizi2=(int*)malloc(sizeof(int)*boyut/2);
		for(int i=0;i<boyut;i++)
			dizi2[i]=dizi[i];
		free(dizi);// eski diziyi siliyor.
		dizi=dizi2;
		boyut =boyut/2;
	};
	
	
 return dizi[--tepe];
};

void push (int a ){
	if(dizi=NULL)
	dizi=(int*)malloc(sizeof(int)*2);
	if(tepe>=boyut){
	int*dizi2=(int*)malloc(sizeof(int)*boyut*2);
		for(int i=0;i<boyut;i++)
			dizi2[i]=dizi[i];
		free(dizi);// eski diziyi siliyor.
		dizi=dizi2;
		boyut =boyut *2;

	};
	dizi[tepe++]=a;
  };
void bastir(){
	printf("%d boyutumuz\n",boyut);
for(int i=0;i<tepe;i++){
	printf("%d\t",dizi[i]);	
	
	}	
	
};                  

int main(){
	dizi=(int*)malloc(sizeof(int)*2);//dinamikleri ilk kullanimda initialize et.
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	bastir();
	printf("popped %d\t",pop());
	printf("popped %d\t",pop());
	printf("popped %d\t",pop());
};
