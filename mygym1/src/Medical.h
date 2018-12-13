#include<gtk/gtk.h>
typedef struct
{
char ID[50];
char nom[30];
char prenom[30];
char adresse[50];
char num[20];
char sexe[20];
char role[100]
}Medical;

void Ajouter_Med(Medical C);

void afficher_med(GtkWidget *liste);

int Verifier_Med(char *ID);

void Supprimer_Med(char *ID);


