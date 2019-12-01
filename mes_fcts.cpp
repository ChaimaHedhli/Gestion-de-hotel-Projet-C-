#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include"mes_fcts.h"

int saisir1()
{
	int x;
	do
	{
	printf("\n donner votre choix entre gestion client ou reservation\n");
	scanf("%d",&x);
	}
	while((x>2)||(x<0));
	return(x);
}
int saisir2()
{
	int y;
	do 
	{
	printf("\n choisir la fonction\n");
	scanf("%d",&y);
	}
	while((y<0)||(y>7));
	return(y);
}

CLIENT saisir_client()
{
	CLIENT cl;
	printf("\n donner le numero d'enregistrement du client \n");
	scanf("%d",&cl.num_enregistrement);
	printf("\n donner le nom du client \n");
	scanf("%s",&cl.nom);
	printf("\n donner le prenom du client \n");
	scanf("%s",&cl.prenom);
	printf("\n donner la date de naissance \n");
	scanf("%d%d%d",&cl.date_naiss.jour,&cl.date_naiss.mois,&cl.date_naiss.annee);
	printf("\n donner l'etat civil du client \n");
	scanf("%s",&cl.etat_civil);
	printf("\n donner la nationalite du client \n");
	scanf("%s",&cl.nationalite);
	printf("\n donner cin du client \n");
	scanf("%s",&cl.cin);
	printf("\n donner l'adresse du client \n");
	scanf("%s",&cl.adresse);
	printf("\n donner le telephone du client \n");
	scanf("%s",&cl.telephone);
	printf("\n donner le sexe\n");
	
	return(cl);
}
RESERVATION saisir_reservation()
{
	RESERVATION res;
	printf("\n donner le nombre des nuits \n");
	scanf("%d",&res.nb_nuits);
	printf("\n donner date d'arrivee\n");
	scanf("%d%d%d",&res.arrivee.jour,&res.arrivee.mois,&res.arrivee.annee);
	printf("\n donner date de depart du client \n");
	scanf("%d%d%d",&res.depart.jour,&res.depart.mois,&res.depart.annee);
	printf("\n donner le nbre des personne \n");
	scanf("%d",&res.nb_personne);
	printf("\n donner le type de chambre \n");
	scanf("%s", &res.type_chambre);
	printf("\n donner le prix de chambre \n");
	scanf("%f",&res.prix_chambre);
	printf("\n donner prix totale de resercation \n");
	scanf("%f",&res.prix_reservation);
	return(res);
}


void CONSULTER_cl (CLIENT cl)
{
	printf("\n le numero d'enregistrement du client est %d \n",cl.num_enregistrement);
	printf("\n le nom du client est : %s \n",cl.nom);
	printf("\n le prenom du client est : %s \n",cl.prenom);
	printf("\n la date de naissance est : %d/%d/%d ",cl.date_naiss.jour,cl.date_naiss.mois,cl.date_naiss.annee);
	printf("\n l'etat civil est : %s ",cl.etat_civil);
	printf("\n la nationalite du client est : %s",cl.nationalite);
	printf("\n cin est : %d",cl.cin);
	printf("\n l'adresse du client est : %s ",cl.adresse);
	printf("\n le numero telephone est : %s",cl.telephone);


}

void CONSULTER_res(RESERVATION res)
{
	printf("\n le nombre des nuits est : %d",res.nb_nuits);
	printf("\n la date d'arrivee est : %d/%d/%d ",res.arrivee.jour,res.arrivee.mois,res.arrivee.annee);
	printf("\n la date de depart est : %d/%d/%d ",res.depart.jour,res.depart.mois,res.depart.annee);
	printf("\n le nombre des personnes est %d",res.nb_personne);
	printf("\n le type de chambre est : %s", res.type_chambre);
	printf("\n le prix d'une chambre est : %f",res.prix_chambre);
	printf("\n le prix total de reservation est : %f",res.prix_reservation);

}
void affiche_tabClient(CLIENT* tab,int n)
{
	int i;
	for(i=0;i<n;i++)
		CONSULTER_cl(*(tab+i));
}

void affiche_tabRESERVATION(RESERVATION* tab2,int n)
{
	int i;
	for(i=0;i<n;i++)
	
		CONSULTER_res(*(tab2+i));
	

}


int saisir_nclients()
{
	int nc;
	printf("\n donner le nombre des clients a saisir \n");
	scanf("%d",&nc);
	return(nc);
}

int saisir_nreservation()
{
	int nr;
	printf("\n donner le nombre des reservations à saisir \n");
	scanf("%d",&nr);
	return(nr);
}
CLIENT* allocation1(int n)
{
	CLIENT *t ;
	t=(CLIENT*)malloc(n*sizeof(CLIENT));
	if(!t) exit(-1);
	return(t);
}

RESERVATION* allocation2(int n)
{
	RESERVATION *tab2;
	tab2=(RESERVATION*)malloc(n*sizeof(RESERVATION));
	if(!tab2) exit(-1);
	return(tab2);
}

void remplir_tabClient(CLIENT *tab,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n donner les information du client %d \n", i+1);
		*(tab+i)=saisir_client();

	}
}

void remplir_tabReservation(RESERVATION* tab2,int n)
{
int i;
	for(i=0;i<n;i++)
	{
		printf("\n donner les information sur la reservation numero %d \n", i+1);
		*(tab2+i)=saisir_reservation();
	}
}



/*void affiche_res(RESERVATION * tab, int n )
{
	memset(tab,0,sizeof(RESERVATION));

	for(int i=0;i<n;i++)
	{
		printf("\n le numero de reservation est %d",(tab+i)->num_reservation);
		printf("\n cin du client : %s ",(tab+i)->cin);
		printf("\n le nombre des nuits est : %d",(tab+i)->nb_nuits);
		printf("\n la date d'arrivee est : %d/%d/%d ",(tab+i)->arrivee.jour,(tab+i)->arrivee.mois,(tab+i)->arrivee.annee);
		printf("\n la date de depart est : %d/%d/%d ",(tab+i)->depart.jour,(tab+i)->depart.mois,(tab+i)->depart.annee);
		printf("\n le nombre des personnes est %d",(tab+i)->nb_personne);
		printf("\n le type de chambre est : %s", (tab+i)->type_chambre);
		printf("\n le prix d'une chambre est : %f",(tab+i)->prix_chambre);
		printf("\n le prix total de reservation est : %f",(tab+i)->prix_reservation);
	}
}*/

void TRIER ( CLIENT *tab, int n)// tri  dans l'ordre croissant par rapport à la carte cin 
{
	int i,permut=1;
	CLIENT aux;
	while(permut)
	{
		permut=0;
		for(i=0;i<n;i++)
		{
			if((*(tab+i)).cin > (*(tab+i+1)).cin)
			{
				aux=*(tab+i+1);
				*(tab+i+1)=*(tab+i);
				*(tab+i)=aux;
				permut=1;
			}
		}
	}
	affiche_tabClient(tab,n);

}





void RECHERCHER1( CLIENT *tab, int n)// recherche du client par le numero d'enregistrement 
{
	int i;
	int num_cherche;
	printf("\n donner le numero d'enregistrement du client à chercher\n");
	scanf("%d",&num_cherche);
	for(i=0;i<n;i++)
	{
		if ((*(tab+i)).num_enregistrement== num_cherche)
		{

			printf("\n le client cherche est le %d client ",i+1);
		}
	
		else 
		{
			printf("\n n'existe pas !!!! \n");
		}
	}

}

/*void RECHERCHER2(RESERVATION* tab , int n) 
{
	int i;
	float x;
	printf("\n donner le prix a chercher \n");
	scanf("%f",&x);
	for(i=0;i<n;i++)
	{
	   if (*(tab+i).prix_reservation==x)
	{
         printf("\n le client cherche est le %d client ",i+1);
	}
	else 
		{
			printf("\n n'existe pas !!!! \n");
		}
	}
}*/
int RECHERCHER( RESERVATION *tab2 , int n)
{
	int i;
	int num_cherche;
	int pos;
	for(i=0;i<n;i++)
	{
		if((*(tab2+i)).nb_personne==num_cherche)
		{
			pos=i;
		}
	}
	return(pos);
}

			
int rechercher_pos1(CLIENT *tab2,int n,int num1)
{
	int i;
	int num;
	printf("entrer le numero a chercher : ");
	scanf("%d",&num);
	for(i=0;i<n;i++)
	{
		if((tab2+i)->cin==num)
			return (i);
		else
			return (-1);
	}
}

void SUPPRIMER_client(CLIENT *tab2,int n)//supprimer à partie le d'enregistrement
{
	int num;
	int pos;
	printf("\n------------------------\n");
	printf("\n donner le numero d'enregistrement du client\n");
	scanf("%d",&num);
	pos=rechercher_pos2(tab2,n,num);
	if(pos==-1)
	{
		printf("\n n'existe pas !!\n");
	}
	else
	{
		*(tab2+n+1)=*(tab2+pos);
		 n=n-1;
		 tab2=(CLIENT*)realloc(tab2,(n-1)*sizeof(CLIENT));
		 printf("suppression effectuée");
		 
	}
}
int rechercher_pos2(CLIENT *t,int n,int num2)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((t+i)->num_enregistrement==num2)
			return (i);
		else
			return (-1);
	}
}

void AJOUTER(CLIENT *t,int n)// ajout d'un seul client 
{
	printf("\n donner les informations a ajouter \n");
	printf("\n donner le numero d'enregistrement du client \n");
	scanf("%d",&t->num_enregistrement);
	printf("\n donner le nom du client \n");
	scanf("%s",&t->nom);
	printf("\n donner le prenom du client \n");
	scanf("%s",&t->prenom);
	printf("\n donner la date de naissance \n");
	scanf("%d%d%d",&t->date_naiss.jour,&t->date_naiss.mois,&t->date_naiss.annee);
	printf("\n donner l'etat civil du client \n");
	scanf("%s",&t->etat_civil);
	printf("\n donner la nationalite du client \n");
	scanf("%s",&t->nationalite);
	printf("\n donner cin du client \n");
	scanf("%s",&t->cin);
	printf("\n donner l'adresse du client \n");
	scanf("%s",&t->adresse);
	printf("\n donner le telephone du client \n");
	scanf("%s",&t->telephone);
	printf("\n donner le sexe du client \n");
	t=(CLIENT*)realloc(t,(n+1)*sizeof(CLIENT));
	if(!t) exit(-1);
	affiche_tabClient(t,n);// affichage du nouveau client qui a été ajouté 
}



void MODIFIER ( CLIENT *tab, int nc)// modification du client , l'emlpoyé doit faire la saisie des informations
{
	char adress;
	int i=0,p;
	
	printf("\n donner le numero du client a modifier \n");
	scanf("%d",&p);

	if (rechercher_pos2(tab,nc,p)== -1 )
		printf("ce num de client n'existe pas ");
	else 
	{
		remplir_la_modification((tab+i),nc);
		printf("\n modification effectuée\n");
	}
	     
}

void remplir_la_modification(CLIENT * tab,int n )
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n donner les information du client %d \n", i+1);
		*(tab+i)=saisir_client();
	}
}




	














	







	










  

