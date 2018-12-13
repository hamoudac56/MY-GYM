#include<stdio.h>
#include <gtk/gtk.h>
#include<stdlib.h>
#include<string.h>
#include"Coach.h"
void Ajouter_Coach(Coach C)
{
	FILE *f;
	f=fopen("/home/parallels/Desktop/mygym1/src/Coaches.txt","a");

	if(f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %s \n",C.ID, C.nom,C.prenom,C.sexe,C.num,C.adresse);
		fclose(f);
	}
	
}


enum
{
	ID,NOM,PRENOM,SEXE,ADRESSE,NUM,COLUMNS
};

void afficher_coach(GtkWidget *liste)
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



store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);

f=fopen("/home/parallels/Desktop/mygym1/src/Coaches.txt","r");

if (f==NULL)
{
	return;
}

else

{
	f=fopen("/home/parallels/Desktop/mygym1/src/Coaches.txt","a+");
	while (fscanf(f,"%s %s %s %s %s %s \n",id,nom,prenom,sexe,num,adresse)!=EOF)
{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set (store, &iter, ID,id,NOM,nom,PRENOM,prenom,SEXE,sexe,ADRESSE,adresse,NUM,num,-1);}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
g_object_unref (store);
	}
}
}

int Verifier_Coach(char *ID)
{
	FILE *f=fopen("/home/parallels/Desktop/mygym1/src/Coaches.txt","r+");
	int existe;
	Coach C;

	while(fscanf(f,"%s %s %s %s %s %s \n", C.ID, C.nom,C.prenom,C.sexe,C.num,C.adresse)!=EOF)
	{
	if(strcmp(C.ID,ID)==0)
	{existe=1;
		 return 1;}
	}
	fclose(f);
	if (existe==0)
	return 0;
	
	}


void Supprimer_Coach(char *ID)
{
	Coach C;	
	FILE *F; 
	FILE *Ftemp;
	F=fopen("/home/parallels/Desktop/mygym1/src/Coaches.txt","a+");
	Ftemp=fopen ("/home/parallels/Desktop/mygym1/src/temp.txt","w+");
	if (F!=NULL){
	
		while (fscanf(F,"%s %s %s %s %s %s \n", C.ID, C.nom,C.prenom,C.sexe,C.num,C.adresse)!=EOF)
			{
			if(strcmp(ID,C.ID)!=0)
				{
				fprintf(Ftemp,"%s %s %s %s %s %s \n", C.ID, C.nom,C.prenom,C.sexe,C.num,C.adresse);
				}
			}
	
fclose(Ftemp);
fclose(F);
		    }
remove ("/home/parallels/Desktop/mygym1/src/Coaches.txt");
rename ("/home/parallels/Desktop/mygym1/src/temp.txt","/home/parallels/Desktop/mygym1/src/Coaches.txt");
}



