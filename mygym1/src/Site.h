#include<gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Datee;
typedef struct
{
char ID[50];
char nom[30];
char type[30];
char num[20];
Datee date;
}Evenement;

void Ajouter_Ev(Evenement E);

void afficher_ev(GtkWidget *liste);

int Verifier_Ev(char *ID);

void Supprimer_Ev(char *ID);

int Nbr_Adherent();

int Nbr_Adherent_H();

int Nbr_Adherent_F();

int Nbr_Coach();

int Nbr_Med();




