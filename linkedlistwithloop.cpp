#include <stdio.h>
#include <stdlib.h> //malloc komutu icin ekliyoruz
/// struct yapisi olusturuyoruz n* next pointer olusturuyor ve sonraki elemani gösteriyor//

struct n	{    
	int x;
	 n * next;

};
typedef n node; // bu sekilde int gibi node tipinde degisken tanimliyoruz.
/// linkedlistin icerigini alip bastiran fonksiyon
void bastir(node* r){
	while(r != NULL){
	printf("%d\n",r->x);
	r = r->next;	
	}
}
// ekleme fonksiyonu
void ekle(node *r,int x){
	while(r->next != NULL){
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->x= x;
	r->next->next = NULL;
}
int main(){
node * root;
root = (node *) malloc (sizeof(node));// bos kutu olusturuyoruz
root -> x = 100;//baslangic degeri.
root -> next= NULL;
node * ilter;
ilter = root;
for (int i=0;i<=4;i++){
ekle(ilter,i*10);
}	
bastir(ilter); // yukaridaki while yerine bu sekilde bastiriyoruz.
}

