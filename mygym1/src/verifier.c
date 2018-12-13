#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"verifier.h"
int verifier (char login[], char password[])
{
	FILE*f;
	char temppass[20]; char templog[20];
	int role, existe=0;
	f=fopen("/home/parallels/Desktop/mygym1/src/users.txt","r");
	if(f !=NULL) {
	while(fscanf(f,"%s %s %d \n",templog,temppass,&role)!=EOF)
	{
		if(strcmp(login,templog)==0 && strcmp(password,temppass)==0)
		{existe=1;
		 return role;}
	}
	if (existe==0)
	return -1;
	fclose(f);
	}
	else printf("impossible d'ouvrir le fichier");
	return role;
}
