#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ajouter.h"
void ajouter(char login[], char password[],int role)
{
	FILE*f;
	f=fopen("/home/parallels/Desktop/mygym1/src/users.txt","a+");
	if(f!=NULL)
	{
		printf("Saisir les données");
		fflush(stdin);
		gets(login);
		fflush(stdin);
		gets(password);
		scanf("%d",&role);
		fprintf(f,"%s %s %d \n",login,password,role);
		fclose(f);
		}
	 else
		printf("Impossible d'ouvrir le fichier");
	return 0;
}
