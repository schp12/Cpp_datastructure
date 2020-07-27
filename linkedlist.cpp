#include <stdio.h>;
#include <stdlib.h>; //malloc komutu icin ekliyoruz
/// struct yapisi olusturuyoruz n* next pointer olusturuyor ve sonraki elemani gösteriyor//

struct n	{    
	int x;
	 n * next;

};
typedef n node; // bu sekilde int gibi node tipinde degisken tanimliyoruz.

int main(){
node * root;
root = (node *) malloc (sizeof(node));// bos kutu olusturuyoruz
root -> x=10; // rootun gosterdigi kutuya 10 degerini atiyoruz.
root -> next = (node *) malloc (sizeof(node));
root -> next -> x=20; // roottan sonraki 2. kutunun data degerine 20 atiyoruz.
root -> next -> next = (node*)malloc(sizeof(node)); // rootun 2sonrasina bos kutu ekliyoruz.
node * ilter;
ilter = root;	
printf("%d",ilter->x);//ilterin gosterdigi kutudaki datayi x'i goster.
ilter = ilter -> next;//bir sonraki kutuya gec.
printf("%d",ilter->x);
	
}
