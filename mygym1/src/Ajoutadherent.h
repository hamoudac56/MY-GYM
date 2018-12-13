#include<gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Date;
typedef struct
{
char ID[50];
char nom[30];
char prenom[30];
char adresse[50];
char num[20];
char sexe[20];
char taille[10];
char poids[10];
char abonnement[30];
Date datenaissance;
}Adherent;

void Ajouter_Adherent(Adherent A);

void afficher_adherent(GtkWidget *liste);

int Verifier_Adherent(char *ID);

void Modifier_Adherent(char *ID, Adherent A);

Adherent Chercher_Adherent(char *ID);

void Supprimer_Adherent(char *ID);


