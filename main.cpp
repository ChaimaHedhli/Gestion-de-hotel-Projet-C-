#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"mes_fcts.h"

void main()       
	         


{

	int choice1=-1,choice2=-1,choice3=-1;
	int nc,nres=-1;  
	RESERVATION *tab2;
	CLIENT *tab1;
	printf("\n                       :::::::::::::::::::::::::::::::::::::");
    printf("\n                       ::                                 ::");
    printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
    printf("\n                       ::     @                     @     ::");
    printf("\n                       ::     @      WELCOME TO     @     ::");
    printf("\n                       ::     @                     @     ::");
    printf("\n                       ::     @      THE HOTEL      @     ::");
    printf("\n                       ::     @                     @     ::");
    printf("\n                       ::     @@@@@@@@@@@@@@@@@@@@@@@     ::");
    printf("\n                       ::                                 ::");
    printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
	printf("\n ajout manuel\n");
	nc=saisir_nclients();
    tab1=allocation1(nc);
	remplir_tabClient(tab1,nc);
	nres=saisir_nreservation();
	tab2=allocation2(nres);
	remplir_tabReservation(tab2,nres);
	y:
	choice1=saisir1();// choisir 1 pour la Gestion Client et 2 pour la Gestion Reservation
	if (choice1 ==1)// choisir 1 pour consulter,2 pour rechercher,3 pour modifier , 4 pour ajouter ,5 pour trier et 6 pour la suppression 
	{
		printf("\n ----------------------------------------------------------------------------------------------------------\n");
		printf("\n                             ***** GESTION CLIENTS*******        \n");
		printf("\n*** pour consulter saisir 1***\n");
		printf("\n*** pour rechercher saisir 2***\n");
		printf("\n ***pour modifier saisir 4***\n");
		printf("\n*** pour ajouter saisir 4 ***\n");
		printf("\n*** pour trier saisir 5***\n");
		printf("\n*** pour supprimer saisir 6*** \n");
		printf("\n------------------------------------------------------------------------------------------------------------\n");
		choice2=saisir2();
		if(choice2 ==1)
		{
			affiche_tabClient(tab1,nc);
		}
		else if(choice2 ==2)
		{
			RECHERCHER1(tab1,nc);
		}

		else if(choice2==3)
		{ 
		
			MODIFIER(tab1,nc);
		}
		else if (choice2 == 4)
		{
			AJOUTER(tab1,nc);
		}
        else if(choice2==5)	
		{
		
			TRIER ( tab1,nc);
		}
		else if(choice2==6)
		{
			
			SUPPRIMER_client(tab1,nc);
			affiche_tabClient(tab1,nc-1);
		}
		else 
		{
			printf("\n RETOURNER\n");
		}
		goto y;
	 }
	 else if(choice1==2)
	 {
		 printf("\n-----------------------------------------------------------------------------------------------------\n");
		 printf("\n               *********** GESTION RESERVATION************\n");
		 printf("\n------------------------------------------------------------------------------------------------------\n");
		 choice3=saisir2();
	
		if (choice3==1)
		{

			affiche_tabRESERVATION(tab2,nres);
		}
		else if(choice3==2)
		{
			printf("recherche");
			/*RECHERCHER2(tab2 ,nres);*/
		}
		
		
		else
		{
			printf("\n RETOURNER \n");
		}
	}
	 else 
	 {
		 printf("\n QUITTER \n");
	 }
	 
getch();
}





















