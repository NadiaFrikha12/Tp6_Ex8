//Ecrire un programme C permettant de :
//Charger deux tableaux t1 et t2 de dimensions respectives 5<=n1<=10 et 5<=n2<=10 par des
//entiers introduits dans un ordre croissant,
//Insérer les éléments de t1 et t2 dans t3 de telle façon que t3 reste trié par ordre croissant,
//Afficher les éléments de t3.
//La solution doit être programmée en utilisant la technique des pointeurs et l’allocation
//dynamique de la mémoire

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int n1, n2 , n3 ; //dimensions des tableaux
	//tableaux
	int* t1; int* t2; int* t3;  
	//pointeurs
	int* p1; int* p2;  int* p3; 
	
	//saisie de n1 
	p1=&n1;
	do{
		printf("donner n1 compris entre 5 et 10 :  ");
		scanf("%d",p1);
	}while((*p1<5)||(*p1>10));
	

	//allocation de la mémoire pour le tableau t1
	t1= (int*)malloc(sizeof(int)*(n1));
	if (t1==NULL){
		printf("erreur");
		return 0;
	}
	else{ //charger t1 par des entiers introduits dans un ordre croissant
		p1 =t1; //le pointeur p1 pointe sur la premiere case de t1 : c'est l'adresse de la premiere case
		printf ("donner t1[%d]",p1-t1);
		scanf("%d",p1);
		for (p1=t1+1; p1<t1+n1;p1++){
			do{
				printf ("donner t1[%d]",p1-t1);
				scanf("%d",p1);
			}while ((*p1)<*(p1-1));
		}		
	}
	
    //saisie de n2 
	p2=&n2;
	do{
		printf("donner n2 compris entre 5 et 10 :  ");
		scanf("%d",p2);
	}while((*p2<5)||(*p2>10));
	
	//allocation de la memoire pour le tableau t2
	t2=(int*)malloc(sizeof(int)*(n2));
	if (t2==NULL){
		printf ("erreur");
		if (t1 != NULL){
			free (t1);
		}
		return 0; 
	}
	else{ //charger t2 par des entiers introduits dans un ordre croissant
		p2=t2; //le pointeur p2 pointe sur la premiere case du tableau
		printf("donner t2[%d] : ",p2-t2);
		scanf("%d",p2);
		for (p2=t2+1; p2<t2+n2; p2++){
			do{
				printf("donner t2[%d] : ",p2-t2);
				scanf("%d",p2);
			}while((*p2)<*(p2-1));
		}	
	}
	
	//insertion des elements de t1 et t2 dans t3
	p1=t1; //p1 pointe sur la premiere case de t1
	p2=t2; //p2 pointe sur la premiere case de t2
	//allocation de la memoire pour t3
	t3=(int*)malloc(sizeof(int)*(n1+n2));
	if (t3==NULL){
		printf("erreur");
		if (t1 != NULL){
			free (t1);
		}
		if (t2 != NULL){
			free (t2);
		}
	}
	else{ //remplissage de t3 par ordre croissant
		p3=t3; //p3 pointe sur la premiere case de t3
		while(*p1 && *p2){ //tant que t1 et t2 non vide 
			if (*p1<*p2){ 
				*p3=*p1;
				p1++;
				p3++;
			}
			if (*p2<*p1){
				*p3=*p2;
				p2++;
				p3++;
			}
		}
		while (p1<t1+n1){ //copier les elements restant de t1
			*p3=*p1;
			p3++;
			p1++;
		}
		while (p2<t2+n2){ //copier les elements restant de t2
			*p3=*p2;
			p3++;
			p2++;
		}	
	}
	
	//affichage des elements de t3
	p3=t3;
	n3= n1+n2;
	printf("les elements de t3 sont:\n");
	for(p3=t3; p3<t3+n3; p3++){
		printf("%d\n",*p3);
	}
	
	//free la memoire 
	if (t1 != NULL){
		free(t1);
	}
	if (t2 != NULL){
		free(t2);
	}
	if (t3 != NULL){
		free(t3);
	}
	
	return 0;
}
