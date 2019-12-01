
struct date 
{
	int jour;
	int mois;
	int annee;
};
typedef struct date DATE ;

struct client // contient les informations du client 
{
	 int num_enregistrement ;
	 char nom[20];
	 char prenom[20];
	 DATE date_naiss ;  // la date de naissance 
	 char etat_civil[20];
	 char nationalite[20];
	 int cin;
	 char adresse[30];
	 char telephone[10] ;
	 
};
typedef struct client CLIENT ;

struct reservation 
{
	int num_reservation;
	int nb_nuits ;
	DATE arrivee ;
	DATE depart ; 
	int nb_personne;// nombre de personnes 
	char type_chambre;// type de chambre reservée
	int num_chambre;//numero de chambre reservée
	float prix_chambre;//prix d'une chambre pour une personne et une nuit  
	float prix_reservation;
};
typedef struct reservation RESERVATION ;

int saisir1();
int saisir2();
int saisir_nclients();
int saisir_nreservation();
CLIENT* allocation1(int);
RESERVATION* allocation2(int);
CLIENT saisir_client();
RESERVATION saisir_reservation();
void remplir_tabClient(CLIENT*,int);
void remplir_tabReservation(RESERVATION*,int);
void affiche_tabClient(CLIENT*,int );
void affiche_tabRESERVATION(RESERVATION* ,int );
void CONSULTER_cl (CLIENT );
void CONSULTER_res(RESERVATION);
void TRIER ( CLIENT*, int);
void RECHERCHER1( CLIENT*, int );
/*void RECHERCHER2(RESERVATION* , int );*/
int RECHERCHER( RESERVATION* , int );
/*void SUPPRIMER(RESERVATION*, int,CLIENT*,int);*/
void affiche_res(RESERVATION* , int  );
int rechercher_pos(CLIENT *,int);
/*void SUPPRIMER_reservation(RESERVATION*,int);*/
void AJOUTER(CLIENT *t,int n);
void MODIFIER(CLIENT*,int);
void remplir_la_modification(CLIENT *,int );
int rechercher_pos2(CLIENT*,int,int);
int rechercher_pos1(RESERVATION*,int,int );
void SUPPRIMER_client(CLIENT*,int);
