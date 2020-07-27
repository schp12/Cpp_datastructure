#include<stdio.h>
#include<stdlib.h>

int sira=0,sirabasi=0,boyut=2;
int *dizi=NULL;


void enque(int a){
	if(dizi==NULL) {
		dizi=(int*)malloc(sizeof(int)*2);
	};
	if(sira>=boyut){
	boyut *= 2;
	int *dizi2=(int*)malloc(sizeof(int)*boyut);
	for(int i=0;i<boyut/2;i++){
	dizi2[i]=dizi[i];
	};	
	free(dizi);
	dizi=dizi2;
		
	};
	dizi[sira++];
};

void toparla(){
if(sirabasi==0){
return;	
};
for(int i=0;i<boyut;i++){
dizi[i]=dizi[i+sirabasi];	
};
sira -=sirabasi;
sirabasi=0;
};

int deque(){
	if(sira==sirabasi){
	printf("sira bos");
	return -1;
	};	
	if(sira-sirabasi <= boyut/4){
	int*dizi2=(int*)malloc(sizeof(int)*boyut/2);
	for(int i=0;i<sira-sirabasi;i++){
	dizi2[i]=dizi[sirabasi+i];
	};							
	
	free(dizi);
	sira -= sirabasi;
	sirabasi = 0;
	boyut /= 2;
	dizi=dizi2;		
	};

return dizi[sirabasi++];	
};


int main(){
	for(int i=0;i<10;i++){
	enque(i*10);	
	};
	printf("durum: boyut : %d sira :%d sirabasi : %d\n",boyut,sira,sirabasi);
	for(int i=0;i<5;i++){
	printf("%d\t",deque());
	};
		for(int i=0;i<10;i++){
	enque(i*10);	
	};
	printf("durum: boyut : %d sira :%d sirabasi : %d\n",boyut,sira,sirabasi);
	for(int i=0;i<5;i++){
	printf("%d\t",deque());
	};
};
