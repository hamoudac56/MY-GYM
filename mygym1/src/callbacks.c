#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#define UTF8(string) g_locale_to_utf8(string, -1, NULL, NULL, NULL)

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "Ajoutadherent.h"
#include "Coach.h"
#include "Medical.h"
#include "Site.h"


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	FILE*f;
	char login[20]; char password[20];
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *output;
	GtkWidget *Admin;
	GtkWidget *Login;
	input1=lookup_widget(objet_graphique,"entry1");
	input2=lookup_widget(objet_graphique,"entry2");
	output=lookup_widget(objet_graphique,"label4");	
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
                if(verifier(login,password)==1)
                {Admin=create_Admin();
		Login=create_Login();
		Login=lookup_widget(objet_graphique,"Login");
		gtk_widget_show(Admin);
		gtk_widget_hide(Login);}
		else gtk_label_set_text(GTK_LABEL(output),"Erreur");
}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_clist1_select_row                   (GtkCList        *clist,
                                        gint             row,
                                        gint             column,
                                        GdkEvent        *event,
                                        gpointer         user_data)
{

}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
}


void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *combobox2;  
	GtkWidget *jour; 
	GtkWidget *mois; 
	GtkWidget *annee;
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *input6;
	GtkWidget *input7;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	Adherent A;


combobox1=lookup_widget(objet_graphique, "combobox1");
combobox2=lookup_widget(objet_graphique, "combobox2");
jour=lookup_widget(objet_graphique, "spinbutton1");
mois=lookup_widget(objet_graphique, "spinbutton2");
annee=lookup_widget(objet_graphique, "spinbutton3");

input1=lookup_widget(objet_graphique,"entry3");
input2=lookup_widget(objet_graphique,"entry4");
input3=lookup_widget(objet_graphique,"entry5");
input4=lookup_widget(objet_graphique,"entry6");
input5=lookup_widget(objet_graphique,"entry7");
input6=lookup_widget(objet_graphique,"entry8");
input7=lookup_widget(objet_graphique,"entry15");

output1=lookup_widget(objet_graphique,"erreur_tel");
output2=lookup_widget(objet_graphique,"erreur_taille");
output3=lookup_widget(objet_graphique,"erreur_poids");

A.datenaissance.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
A.datenaissance.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
A.datenaissance.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


strcpy(A.ID,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(A.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(A.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(A.num,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(A.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(A.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(A.poids,gtk_entry_get_text(GTK_ENTRY(input6)));




if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(A.sexe,"Homme");
else
strcpy(A.sexe,"Femme");

if(strcmp("3 Mois",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(A.abonnement,"3_mois");
else if(strcmp("6 Mois",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(A.abonnement,"6_mois");
else
strcpy(A.abonnement,"1_année");


if(atoi(A.taille)<50 || atoi(A.taille)>999)
	gtk_label_set_text(GTK_LABEL(output2),"Valeur Incorrecte");

else if(atoi(A.poids)<10 || atoi(A.poids)>999)
	gtk_label_set_text(GTK_LABEL(output3),"Valeur Incorrecte");

else {
	if(Verifier_Adherent(A.ID)==0)
	{
	Ajouter_Adherent(A);
	gtk_label_set_text(GTK_LABEL(output3),"Adhérent Ajouté");
	gtk_label_set_text(GTK_LABEL(output2),"");
	}
	else
	{
	Supprimer_Adherent(A.ID);
	Ajouter_Adherent(A);
	gtk_label_set_text(GTK_LABEL(output3),"Adhérent Modifié");
	gtk_label_set_text(GTK_LABEL(output2),"");
	}
     }
}



void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Gestion_Adherents;
GtkWidget *Admin;
GtkWidget *treeview1;

Admin=lookup_widget(objet,"Admin");

treeview1=lookup_widget(Admin,"treeview1");

afficher_adherent(treeview1); 
}



void
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 
	GtkWidget *input7;
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	Adherent A;
	char ID[50];



input7=lookup_widget(objet_graphique,"entry15");

output1=lookup_widget(objet_graphique,"erreur_tel");
output2=lookup_widget(objet_graphique,"erreur_taille");
output3=lookup_widget(objet_graphique,"erreur_poids");



strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input7)));


	if(Verifier_Adherent(ID)==1)
	{
	Supprimer_Adherent(ID);	
	gtk_label_set_text(GTK_LABEL(output1),"Adhérent Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output1),"Adhérent n'existe pas");
	}


}


gboolean
on_label55_activate_link               (GtkLabel        *label,
                                        gchar           *arg1,
                                        gpointer         user_data)
{

  return FALSE;
}


void
on_button14_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview2;

Admin=lookup_widget(button,"Admin");

treeview2=lookup_widget(Admin,"treeview2");

afficher_coach(treeview2); 
}


void
on_button16_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;  
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *output;
	Coach C;


combobox1=lookup_widget(button, "combobox4");


input1=lookup_widget(button,"entry22");
input2=lookup_widget(button,"entry16");
input3=lookup_widget(button,"entry17");
input4=lookup_widget(button,"entry19");
input5=lookup_widget(button,"entry18");

output=lookup_widget(button,"erreur");



strcpy(C.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(C.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(C.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(C.num,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(C.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));




if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(C.sexe,"Homme");
else
strcpy(C.sexe,"Femme");

	if(Verifier_Coach(C.ID)==0)
	{
	Ajouter_Coach(C);
	gtk_label_set_text(GTK_LABEL(output),"Coach Ajouté");
	}
	else
	{
	Supprimer_Coach(C.ID);
	Ajouter_Coach(C);
	gtk_label_set_text(GTK_LABEL(output),"Coach Modifié");
	}

}


void
on_button17_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{ 
	GtkWidget *input1;
	GtkWidget *output;
	char ID[50];

	input1=lookup_widget(button,"entry22");
	output=lookup_widget(button,"erreur");

	strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(Verifier_Coach(ID)==1)
	{
	Supprimer_Coach(ID);	
	gtk_label_set_text(GTK_LABEL(output),"Coach Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"Coach n'existe pas");
	}

}


void
on_button18_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview3;

Admin=lookup_widget(button,"Admin");

treeview3=lookup_widget(Admin,"treeview3");

afficher_med(treeview3); 
}


void
on_button19_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *combobox1;
	GtkWidget *combobox2;    
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *input3;
	GtkWidget *input4;
	GtkWidget *input5;
	GtkWidget *output;
	Medical M;


combobox1=lookup_widget(button, "combobox5");
combobox2=lookup_widget(button, "combobox6");


input1=lookup_widget(button,"entry27");
input2=lookup_widget(button,"entry23");
input3=lookup_widget(button,"entry24");
input4=lookup_widget(button,"entry26");
input5=lookup_widget(button,"entry25");

output=lookup_widget(button,"erreur1");



strcpy(M.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(M.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(M.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(M.num,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(M.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));




if(strcmp("Homme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
strcpy(M.sexe,"Homme");
else
strcpy(M.sexe,"Femme");

if(strcmp("Kinésithérapeute",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(M.role,"Kinésithérapeute");

else if(strcmp("Diéticien",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
strcpy(M.role,"Diéticien");

else
strcpy(M.role,"Médecin_Nutritioniste");

	if(Verifier_Med(M.ID)==0)
	{
	Ajouter_Med(M);
	gtk_label_set_text(GTK_LABEL(output),"Staff Médical Ajouté");
	}
	else
	{
	Supprimer_Med(M.ID);
	Ajouter_Med(M);
	gtk_label_set_text(GTK_LABEL(output),"Staff Médical Modifié");
	}
}


void
on_button20_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *output;
	char ID[50];

	input1=lookup_widget(button,"entry27");
	output=lookup_widget(button,"erreur1");

	strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(Verifier_Med(ID)==1)
	{
	Supprimer_Med(ID);	
	gtk_label_set_text(GTK_LABEL(output),"Staff Médical Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"ID n'existe pas");
	}
}


void
on_button21_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin;
GtkWidget *treeview4;

Admin=lookup_widget(button,"Admin");

treeview4=lookup_widget(Admin,"treeview4");

afficher_ev(treeview4); 

}


void
on_button23_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *output;
	char ID[50];

	input1=lookup_widget(button,"entry34");
	output=lookup_widget(button,"erreur2");

	strcpy(ID,gtk_entry_get_text(GTK_ENTRY(input1)));

	if(Verifier_Ev(ID)==1)
	{
	Supprimer_Ev(ID);	
	gtk_label_set_text(GTK_LABEL(output),"Evenement Supprimé");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(output),"Evenement n'existe pas");
	}
}


void
on_button22_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	GtkWidget *input2;
	GtkWidget *combobox;
	GtkWidget *output;
	GtkWidget *jour; 
	GtkWidget *mois; 
	GtkWidget *annee;
	Evenement E;

combobox=lookup_widget(button, "combobox8");

jour=lookup_widget(button, "spinbutton4");
mois=lookup_widget(button, "spinbutton5");
annee=lookup_widget(button, "spinbutton6");

input1=lookup_widget(button,"entry34");
input2=lookup_widget(button,"entry28");

output=lookup_widget(button,"erreur2");

strcpy(E.ID,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(input2)));

E.date.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
E.date.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
E.date.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));

if(strcmp("Offre",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
strcpy(E.type,"Offre");

else if(strcmp("Cours_Spécial",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
strcpy(E.type,"Cours_Spécial");

else
strcpy(E.type,"Autre");

	if(Verifier_Ev(E.ID)==0)
	{
	Ajouter_Ev(E);
	gtk_label_set_text(GTK_LABEL(output),"Evenement Ajouté");
	}
	else
	{
	Supprimer_Ev(E.ID);
	Ajouter_Ev(E);
	gtk_label_set_text(GTK_LABEL(output),"Evenement Modifié");
	}
}


void
on_button24_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *output1;
	GtkWidget *output2;
	GtkWidget *output3;
	GtkWidget *output4;
	GtkWidget *output5;
	int A,AF,AH,C,M;
	char NbA[75];
	char NbAF[75];
	char NbAH[75];
	char NbC[75];
	char NbM[75];

A=Nbr_Adherent();

AF=Nbr_Adherent_F();

AH=Nbr_Adherent_H();

C=Nbr_Coach();

M=Nbr_Med();

snprintf( NbA, 75, "Nombre d'adhérents : %d", A );

snprintf( NbAF, 75, "Nombre de femmes : %d", AF );

snprintf( NbAH, 75, "Nombre d'hommes : %d", AH );

snprintf( NbC, 75, "Nombre de coaches : %d", C );

snprintf( NbM, 75, "Effectif Médical : %d", M );

output1=lookup_widget(button,"NB_A");
output2=lookup_widget(button,"NB_A_F");
output3=lookup_widget(button,"NB_A_H");
output4=lookup_widget(button,"NB_C");
output5=lookup_widget(button,"NB_M");

gtk_label_set_text(GTK_LABEL(output1),NbA);
gtk_label_set_text(GTK_LABEL(output2),NbAF);
gtk_label_set_text(GTK_LABEL(output3),NbAH);
gtk_label_set_text(GTK_LABEL(output4),NbC);
gtk_label_set_text(GTK_LABEL(output5),NbM);
}



