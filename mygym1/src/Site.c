#include<stdio.h>
#include <gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include"Site.h"
#include"Ajoutadherent.h"
#include"Coach.h"
#include"Medical.h"
void Ajouter_Ev(Evenement E)
{
	FILE *f;
	f=fopen("/home/parallels/Desktop/mygym1/src/Evenements.txt","a");

	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %d %d %d \n",E.ID, E.nom,E.type,E.date.jour,E.date.mois,E.date.annee);
		fclose(f);
	}
	
}


enum
{
	ID,NOM,TYPE,JOUR,MOIS,ANNEE,COLUMNS
};

void afficher_ev(GtkWidget *liste)
{
	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
char id[50];
char nom[30];
char type[30];
int jour;
int mois;
int annee;

	store=NULL;
	FILE *f;
	
	store=gtk_tree_view_get_model(liste);

	if (store==NULL);
	{
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",ID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",JOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",MOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",ANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);



store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);

f=fopen("/home/parallels/Desktop/mygym1/src/Evenements.txt","r");

if (f==NULL)
{
	return;
}

else

{
	f=fopen("/home/parallels/Desktop/mygym1/src/Evenements.txt","a+");
	while (fscanf(f,"%s %s %s %d %d %d \n",id,nom,type,&jour,&mois,&annee)!=EOF)
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set (store, &iter, ID,id,NOM,nom,TYPE,type,JOUR,jour,MOIS,mois,ANNEE,annee,-1);}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref (store);
	}
}
}

int Verifier_Ev(char *ID)
{
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Evenements.txt","r+");
	int existe;
	Evenement E;

	while(fscanf(f,"%s %s %s %d %d %d \n", E.ID, E.nom,E.type,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF)
	{
	if(strcmp(E.ID,ID)==0)
	{existe=1;
		 return 1;}
	}
	fclose(f);
	if (existe==0)
	return 0;
	
	}


void Supprimer_Ev(char *ID)
{
	Evenement E;	
	FILE *F; 
	FILE *Ftemp;
	F=fopen("/home/parallels/Desktop/mygym1/src/Evenements.txt","a+");
	Ftemp=fopen ("/home/parallels/Desktop/mygym1/src/src/temp.txt","w+");
	if (F!=NULL){
	
		while (fscanf(F,"%s %s %s %d %d %d \n", E.ID, E.nom,E.type,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF)
			{
			if(strcmp(ID,E.ID)!=0)
				{
				fprintf(Ftemp,"%s %s %s %d %d %d \n", E.ID, E.nom,E.type,E.date.jour,E.date.mois,E.date.annee);
				}
			}
	
fclose(Ftemp);
fclose(F);
		    }
remove ("/home/parallels/Desktop/mygym1/src/Evenements.txt");
rename ("/home/parallels/Desktop/mygym1/src/temp.txt","/home/parallels/Desktop/mygym1/src/Evenements.txt");
}

int Nbr_Adherent()
{
	int n=0;	
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","r+");
	Adherent A;
	while(fscanf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
	{n++;}
	fclose(f);
	return n;
}

int Nbr_Adherent_H()
{
	int n=0;	
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","r+");
	Adherent A;
	while(fscanf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
	{	
	if(strcmp(A.sexe,"Homme")==0)	
	n++;
	}
	fclose(f);
	return n;
}

int Nbr_Adherent_F()
{
	int n=0;	
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","r+");
	Adherent A;
	while(fscanf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
	{	
	if(strcmp(A.sexe,"Femme")==0)	
	n++;
	}
	fclose(f);
	return n;
}

int Nbr_Coach()
{
	int n=0;	
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Coaches.txt","r+");
	Coach C;

	while(fscanf(f,"%s %s %s %s %s %s \n", C.ID, C.nom,C.prenom,C.sexe,C.num,C.adresse)!=EOF)
	n++;
	fclose(f);
	return n;
}

int Nbr_Med()
{
	int n=0;	
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Medical.txt","r+");
	Medical M;

	while(fscanf(f,"%s %s %s %s %s %s %s \n", M.ID, M.nom,M.prenom,M.sexe,M.num,M.adresse,M.role)!=EOF)
	n++;
	fclose(f);
	return n;
}
