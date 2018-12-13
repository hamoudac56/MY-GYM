#include<stdio.h>
#include <gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include"Ajoutadherent.h"
void Ajouter_Adherent(Adherent A)
{
	FILE *f;
	f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","a");

	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n",A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,A.datenaissance.jour,A.datenaissance.mois,A.datenaissance.annee,A.abonnement);
		fclose(f);
	}
	
}


enum
{
	ID,NOM,PRENOM,SEXE,ADRESSE,NUM,TAILLE,POIDS,JOUR,MOIS,ANNEE,ABONNEMENT,COLUMNS
};

void afficher_adherent(GtkWidget *liste)
{
	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
char id[50];
char nom[30];
char prenom[30];
char adresse[50];
char num[20];
char sexe[20];
char taille[10];
char poids[10];
char abonnement[30];
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
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" sexe",renderer,"text",SEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",ADRESSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" num",renderer,"text",NUM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" taille",renderer,"text",TAILLE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" poids",renderer,"text",POIDS,NULL);
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

renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" abonnement",renderer,"text",ABONNEMENT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,  G_TYPE_STRING);

f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","r");

if (f==NULL)
{
	return;
}

else

{
	f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","a+");
	while (fscanf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n",id, nom,prenom,sexe,num,adresse,taille,poids,&jour,&mois,&annee,abonnement)!=EOF)
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set (store, &iter, ID,id,NOM,nom,PRENOM,prenom,SEXE,sexe,ADRESSE,adresse,NUM,num,TAILLE,taille,POIDS,poids,JOUR,jour,MOIS,mois,ANNEE,annee,ABONNEMENT,abonnement,-1);}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref (store);
	}
}
}

int Verifier_Adherent(char *ID)
{
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","r+");
	int existe;
	Adherent A;

	while(fscanf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
	{
	if(strcmp(A.ID,ID)==0)
	{existe=1;
		 return 1;}
	}
	fclose(f);
	if (existe==0)
	return 0;
	
	}

void Modifier_Adherent(char *ID, Adherent B)
{

    		    Adherent A ;
   		    FILE* F;
		    FILE* F_temp;
		    F=fopen("Adherents.txt","r+");
		    F_temp=fopen("temp.txt","a+");

		    while(fscanf(F,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
		    {

			if (strcmp(ID,A.ID)==0)

			   { fprintf(F_temp,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,A.datenaissance.jour,A.datenaissance.mois,A.datenaissance.annee,A.abonnement);}
			else if (strcmp(ID,A.ID)!=0)
 {	    fprintf(F_temp,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,A.datenaissance.jour,A.datenaissance.mois,A.datenaissance.annee,A.abonnement);
}
		    };

		    fclose(F);
		    fclose(F_temp);
		    remove("Adherents.txt");
		    rename("temp.txt","Adherents.txt");


}



Adherent Chercher_Adherent(char *ID)
{
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","r+");
	int existe;
	Adherent A;

	while(fscanf(f,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
	{
	if(strcmp(A.ID,ID)==0)
		 return A;
	}	
	fclose(f);

	}

void Supprimer_Adherent(char *ID)
{
	Adherent A;	
	FILE *F; 
	FILE *Ftemp;
	F=fopen("/home/parallels/Desktop/mygym1/src/Adherents.txt","a+");
	Ftemp=fopen ("/home/parallels/Desktop/mygym1/src/temp.txt","w+");
	if (F!=NULL){
	
		while (fscanf(F,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,&A.datenaissance.jour,&A.datenaissance.mois,&A.datenaissance.annee,A.abonnement)!=EOF)
			{
			if(strcmp(ID,A.ID)!=0)
				{
				fprintf(Ftemp,"%s %s %s %s %s %s %s %s %d/%d/%d %s \n", A.ID, A.nom,A.prenom,A.sexe,A.num,A.adresse,A.taille,A.poids,A.datenaissance.jour,A.datenaissance.mois,A.datenaissance.annee,A.abonnement);
				}
			}
	
fclose(Ftemp);
fclose(F);
		    }
remove ("/home/parallels/Desktop/mygym1/src/Adherents.txt");
rename ("/home/parallels/Desktop/mygym1/src/temp.txt","/home/parallels/Desktop/mygym1/src/Adherents.txt");
}



