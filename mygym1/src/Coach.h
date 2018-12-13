#include<gtk/gtk.h>
typedef struct
{
char ID[50];
char nom[30];
char prenom[30];
char adresse[50];
char num[20];
char sexe[20];
}Coach;

void Ajouter_Coach(Coach C);

void afficher_coach(GtkWidget *liste);

int Verifier_Coach(char *ID);

void Supprimer_Coach(char *ID);


