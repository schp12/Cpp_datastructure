#include<stdio.h>
#include<stdlib.h>

struct n{
 int data;
 n * sag;
 n * sol;

};

typedef n node;
node* ekle(node *agac,int x){
	if(agac == NULL){
	node * root = (node*)malloc(sizeof(node));
	root -> sag = NULL;
	root -> sol = NULL;
	root -> data = x;	
	return root;
	};	
	if(agac -> data < x){
	agac -> sag = ekle(agac -> sag,x);
	return agac;	
	};
	agac -> sol = ekle(agac -> sol,x);
	return agac;
};
/* kucukten buyuge siralama */
/*  eger sag ve sol yer degistirirse buyukten kucuge olur  */ 
void dolas(node *agac){
	if(agac==NULL)
	return;
	dolas(agac->sol);
	printf("%d\t",agac->data);
	dolas(agac->sag);
};

/*  Arama komutu */ 
int bul(node*agac,int aranan){
if(agac == NULL)
  return -1;
if(agac->data == aranan){
	return aranan;
}
if(bul(agac->sag,aranan)>1)
 	return aranan;
if(bul(agac->sol,aranan)>1)
	return aranan;
return -1; 	
	
};

/* Max Min bulma*/
int max(node* agac){
 while(agac->sag != NULL)
 		agac = agac->sag;
	return agac->data;	 	
	
};
int min(node* agac){

while (agac -> sol !=NULL)
		agac = agac->sol;
	return agac -> data;		
};

/* Silme   */
node * sil(node *agac, int x){
	if(agac==NULL)
	return NULL;
if(agac->data==x){
	if(agac->sag==NULL && agac->sol==NULL)
		return NULL;
	if(agac->sag!=NULL){
	agac->data=min(agac->sag);
	agac->sag=sil(agac->sag,min(agac->sag));
	return agac;
	};
	agac->data=max(agac->sol);
	agac->sol=sil(agac->sol,max(agac->sol));
	return agac;
	};
if(agac->data < x){
	agac->sag=sil(agac->sag,x);
	return agac;
};
agac->sol=sil(agac->sol,x);
return agac;
};



int main(){
node* agac= NULL;
agac=ekle(agac,10);
agac=ekle(agac,50);
agac=ekle(agac,30);
agac=ekle(agac,20);
agac=ekle(agac,60);
agac=ekle(agac,40);
agac=ekle(agac,70);
agac=ekle(agac,80);
agac=ekle(agac,55);
dolas(agac);
printf("aranan deger: %d\n",bul(agac,10));
printf("en buyuk deger: %d\n",max(agac));
printf("en kucuk deger: %d\n",min(agac));
agac=sil(agac,55);
dolas(agac);
agac=sil(agac,10);
dolas(agac);

};
