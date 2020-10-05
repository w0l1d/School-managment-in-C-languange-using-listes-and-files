#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
/***************************************** Les stuctures de donnee ******************************/

typedef struct etudiant
{
     char *cne;
     char *nom;
     char *prenom;
     char *phone;
     char *code_fill;
}etudiant;
//-------------------------
typedef struct prof
{
     char* CIN;
     char* nom;
     char* prenom;
	 char* phone;
}prof;
//-------------------------

typedef struct fillier
{
	 char *code_fill;
	 char *nom_fill;
//	 char *code_depa;
     
}fillier;
//-------------------------

typedef struct module
{
     int num_mod;
	 char *nom;
     int duree;
     int semestre;
     
}module;
//-------------------------

typedef struct ensegnier	//last
{
	 int ID_prof;
	 int num_module;
}ense;
//-------------------------

typedef struct note		//last
{
     int nt_DS1;
     int nt_DS2;
     int num_mod;
     char *cne;
}note;

/***************************************** Les Listes simplement Chaînée ******************************/
typedef struct Element_etud
{
	etudiant val;
	struct Element_etud* Suivant;
}Elem_etud;
//++++++++++++++++++++++++++
typedef struct Elem_prof
{
	prof val;
	struct Elem_prof* Suivant;
}Elem_prof;
//++++++++++++++++++++++++++

typedef struct Elem_fill
{
	fillier val;
	struct Elem_fill* Suivant;
}Elem_fill;
//++++++++++++++++++++++++++

typedef struct Elem_modu
{
	module val;
	struct Elem_modu* Suivant;
}Elem_modu;
//++++++++++++++++++++++++++

typedef struct Elem_note
{
	note val;
	struct Elem_note* Suivant;
}Elem_note;                                                          
                                          


//*************************************************************************************************************************//
//**************************************************************************************************************************///*
 /*
  										   _____          __     ____ 
											 |   |\   |  |   \  |      \  /
											 |   | \  |  |    | |____   \/
											 |   |  \ |  |    | |       /\
  										   __|__ |   \|  |__ /  |____  /  \
//*************************************************************************************************************************************/
//*************************************************************************************************************************//
Elem_prof* init_prof(Elem_prof *P);
//initialisation de liste chainnee des professeurs Elem_prof
Elem_prof* inser_prof(Elem_prof *P);
//inserer les informations d'un element dans la liste chainnee des Professeurs Elem_prof
Elem_prof* insert_prof_plus(Elem_prof* P);
//inserer les infos de plusieure element dans la liste chainnee des professeurs Elem_prof
void sauvegarde_prof(Elem_prof *P);
//sauvegarder les informations de la liste chainnee des Professeurs dans le fichier principal
void sauvegarde_prof11(Elem_prof *P);
//sauvegarder les informations de la liste chainnee des professeurs dans le fichier principal SANS PRINTF() (commentaires des erreurs)
void affiche_new_prof(Elem_prof *P);
//afficher les informations des Professeurs de la liste chainne qui ne sont pas sauvegarder
void read_prof(void);
//afficher les infos des Professeurs qui sont sauvegardees dans le fichier principal
int compte_prof(void);
//compter combien de Professeurs on a sauvegarde dans le fichier principal
int supp_prof(void);
//supprimer les infos d'un Professeurs recherchee par son CIN dans le fichier principale et sauvegarder la resultat dans le fichier temporaire
int modif_prof(void);
//modifier les infos d'un Professeur recherchee par son CIN dans le fichier principale et sauvegarder la resultat dans le fichier temporaire
Elem_modu* init_mod(Elem_modu *N);
//initialisation de liste chainnee des modules Elem_modu
Elem_modu* inserte_modu(Elem_modu* M);
//inserer les informations d'un element dans la liste chainnee des modules Elem_modu
Elem_modu* inserte_modu_plus(Elem_modu* M );
//inserer les infos de plusieure element dans la liste chainnee des modules Elem_modu
void sauv_list_modu(Elem_modu* M);
//sauvegarder les informations de la liste chainnee des modules dans le fichier principal
void affiche_new_mod(Elem_modu* M);
//afficher les informations des modules de la liste chainne qui ne sont pas sauvegarder
void read_modu(void);
//afficher les infos des modules qui sont sauvegardees dans le fichier principal
int modife_modul(void);
//modifier les infos d'un module recherchee par son NUMERO dans le fichier principale et sauvegarder la resultat dans le fichier temporaire
void copier_mod(void);
//NOT_SUR_IF_WORKING copier les infos de fichier temporaire aux fichier principale
int compte_mod(void);
//compter combien de module on a sauvegarde dans le fichier principal
int supp_mod(void);
//supprimer les infos d'un module recherchee par son NUMERO dans le fichier principale et sauvegarder la resultat dans le fichier temporaire
Elem_note* init_note(Elem_note *N);
//initialiser la liste chainee des notes Elem_note
Elem_note* inserte_note_mod(Elem_note* N , int num_mod );
//inserer un element en tete de la liste chainee des notes Elem_note PAR UN NUMERO DE MODULE
Elem_note* inserer_note_plus_mod(Elem_note* F);
//inserer plusieur elements en tete de la liste chainee des notes Elem_note PAR UN NUMERO DE MODULE
Elem_note* inserte_note_cne(Elem_note* N , char *cne );
//inserer un element en tete de la liste chainee des notes Elem_note PAR UN CNE
Elem_note* inserer_note_plus_cne(Elem_note* F);
//inserer plusieur elements en tete de la liste chainee des notes Elem_note PAR UN CNE
void sauver_liste_note(Elem_note*F);
//sauvegarder le contenue de la liste chainee dans le fichier principal AVEC printf
void sauver_liste_note11(Elem_note*F);
//sauvegarder le contenue de la liste chainee dans le fichier principal SANS printf
void read_note_val(void);
//lire le fichier ou on a sauvegardee les note des etudiant et afficher les etudiants qui'on une moyenne plus que 12 (Validee) dans un module
void read_note_modu(void);
//lire le fichier ou on a sauvegardee les note des etudiant et afficher les notes des etudiants d'un module
void read_note_cne(void);
//lire le fichier ou on a sauvegardee les note des etudiant et afficher les notes d'un cne (etudiant) specifiee
void read_note(void);
//lir le fichier ou on a sauvegardee les note des etudiant et afficher toutes les notes et informations des etudiants 
Elem_etud* init_etud ( Elem_etud *F );
//initialiser la liste chainee de l'etudiant Elem_etud
Elem_etud* InsererEnTete(Elem_etud* L , char* code_fill);
//inserer un element en tete de la liste chainee de l'etudiant Elem_etud
Elem_etud* inserer_etud_plus(Elem_etud* F);
//inserer plusieur elements en tete de la liste chainee de l'etudiant
void sauver_liste(Elem_etud*F);
//sauvegarder les elements de la liste chainee de l'etudiant Elem_etud avec printf
void sauver_liste11(Elem_etud*F);
//sauvegarder les elements de la liste chainee de l'etudiant Elem_etud sans aucun printf
void sauve_fill_cne(Elem_etud *F);
//sauvegarder les elements de la liste chainee de fillier Elem_fill avec printf
void sauve_fill_cne_delete(char* cne);
//copier toutes les donnes du fichier principal CNE-CODE_FILL.txt --sans se qui'a le cne du parametre-- au fichier temporaire CNE-CODE_FILL tmp.txt
int compte_etud_sauv(void);
//compter combien d'etudiant en a sauvegarder dans le fichier des etudiants
void read_etu (void);
//lire les etudiant sauvegrdee au fichier et les afficher
void sauv_supp(void);
//copier toutes les donnes du fichier temporaire des etudiant au fichier principal des etudiant
void sauv_supp_fill(void);
//copier toutes les donnes du fichier temporaire CNE-CODE_FILL tmp.txt au fichier principal CNE-CODE_FILL.txt
void affiche_new_etu(Elem_etud* F);
//afficher les etudiants de la list chainne Elem_etud qui ne sont pas sauvegardee
void sauve_fill_cne_modif(char* cne , char *cne_new);
//copier les donnees du fichier principal des filliers et CNE's en modifiant le parametre cne par le parametre cne_new
etudiant* cherche_etu( char *cne);
//chercher un etudiant paar CNE dans le fichier principal des etudiants et le reterner 
int delete_etud(void);
//supprimer les infos d'un etudiant recherchee par la fonction(precedant) "cherche_etu" dans le fichier principale et sauvegarder la resultat dans le fichier temporaire
Elem_etud* inserer_de_file(Elem_etud* tmp , Elem_etud* F);
//N.W
Elem_etud* read_in_file (Elem_etud *F);
//N.W
void cree_file_etud(void);
//N.W
int cherche_etu_modif( char *cne);
//verifier par le CNE si un etudiant existe dans les infos stockee dans le fichier principal
void modifier_etud(Elem_etud* E);
//supprimer les infos d'un etudiant recherchee par la fonction "cherche_etu" dans le fichier principale et sauvegarder la resultat dans le fichier temporaire
etudiant* cherche_etu_simple( char *cne);
//rechercher les infos d'un etudiant par CNE dans le fichier principal et retourner ses infos s'il exite et "NULL" IF NOT
void sauve_note_cne_modif(char* cne , char *cne_new);
//sauvegardee les modifications des CNEs et leurs Notes dans un fichier temporaire 
void sauv_supp_note(void);
//sauvegardee les Suppressions des CNEs et leurs Notes dans un fichier temporaire 




//*******************************************************************************************************************************//
//**************************************
Elem_fill* init_fill(Elem_fill *N)
{
	Elem_fill* tmp=N;
	Elem_fill* tmp2=N;
	N=NULL;
	if(tmp!=NULL)
		do
		{
			tmp2=tmp;
			tmp = tmp->Suivant;
			free(tmp2->val.code_fill);
			free(tmp2->val.nom_fill);
			free(tmp2);
		}while(tmp !=NULL);
	return N;
}


//************************************
Elem_fill* inserte_fill(Elem_fill* M)
{
	Elem_fill* tmp=(Elem_fill*)malloc(sizeof(Elem_fill));
	tmp->val.code_fill=(char*)malloc(sizeof(char)*6);
	tmp->val.nom_fill=(char*)malloc(sizeof(char)*50);
	system("cls");
	printf("\n\ntapez le code du filliers [max: 5c]: ");
	scanf("%s",tmp->val.code_fill);
	tmp->val.code_fill=strupr(tmp->val.code_fill);
	printf("\n\nentrer le nom du Fillier [utiliser _ au lieu d'espace] : ");
	scanf("%s",tmp->val.nom_fill);
	tmp->Suivant = M;
	return tmp;
}




//*************************************
Elem_fill* inserte_fill_plus(Elem_fill* M )
{
	char check='y';
	system("cls");
	while((check == 'y') || (check == 'Y')) 
	{
		M=inserte_fill(M);
		printf("\n\nVoulez vous continuee [Y or y] ?\t");
		check=getch();
	}
	return M;
}




//************************************
void sauv_list_fill(Elem_fill* M)
{
	FILE *f;
	Elem_fill *tmp=M;
	int cmp=0;
	if(tmp == NULL)
		printf("\n\nPas de sauvegarde pour une list vide !!! \n\n\n");
		
	else
	{
		f=fopen("./Fillier/Filliers_save.txt" , "a");
		if(f != NULL)
		{
			while(tmp!=NULL)
			{
				cmp++;
				fprintf(f,"%s\n%s\n\n",tmp->val.nom_fill,tmp->val.code_fill);
				tmp=tmp->Suivant;
			}
			fclose(f);
		}
		if(cmp == 1)
			printf("Vous avez sauvegardees %d Fillier",cmp);
		else
			printf("Vous avez sauvegardees %d Filliers",cmp);
		getch();
	}
}




//************************************
void sauv_list_fill11(Elem_fill* M)
{
	FILE *f;
	Elem_fill *tmp=M;
	if(tmp == NULL)
		return;
		
	else
	{
		f=fopen("./Fillier/Filliers_save.txt" , "a");
		if(f != NULL)
		{
			while(tmp!=NULL)
			{
				fprintf(f,"%s\n%s\n\n",tmp->val.nom_fill,tmp->val.code_fill);
				tmp=tmp->Suivant;
			}
			fclose(f);
		}
}
}


//**************************************
void affiche_new_fill (Elem_fill* M)
{
	if(M==NULL)
	{
		printf("\n\n\nPAS DE FILLIER DANS LA LIST !!!\n\n\n\n\n");
		getch();
		system("cls");
	}
	else
	{
		Elem_fill* tmp=M;
		while(tmp!=NULL)
		{
			printf("Nom de Fillier : %s\nCode de Fillier : %s\n\n",tmp->val.nom_fill,tmp->val.code_fill);
			tmp=tmp->Suivant;
		}
		getch();
	}
	
}




//***************************************
void read_fill(void)
{
	fillier* tmp=(fillier*)malloc(sizeof(fillier));
	tmp->code_fill=(char*)malloc(sizeof(char)*6);
	tmp->nom_fill=(char*)malloc(sizeof(char)*50);
	FILE *f;
	f=fopen("./Fillier/Filliers_save.txt" , "r");
	system("cls");
	if(f== NULL)
	{
		printf("\n\n\n\nPAS d'etudiant Sauvegardee !!!!\n\n\n");
	}
	else
	{
		while(!feof(f))
		{
			if(feof(f))
				break;
			fscanf(f,"%s\n%s\n\n",tmp->nom_fill,tmp->code_fill);
			printf("Nom de Fillier :%s\nCode de Fillier : %s\n\n",tmp->nom_fill,tmp->code_fill);
		}
	}
	getch();
	free(tmp->code_fill);
	free(tmp->nom_fill);
	free(tmp);
	fclose(f);
}


//***************************
int modife_fill(void)
{
	fillier tmp;
	tmp.code_fill=(char*)malloc(sizeof(char)*6);
	tmp.nom_fill=(char*)malloc(sizeof(char)*50);
	FILE *f,*g;
	char codef[6];
	int qwerty=0;
	f=fopen("./Fillier/Filliers_save.txt" , "r");
	g=fopen("./Fillier/Filliers_save_tmp.txt" , "w+");
	if((f==NULL) || (g==NULL))
	{
		system("cls");
		printf("\n\n\n\n\nERREUR DE(OUVERTURE || CREATION) DE FICHIER !!!\n\n\n\n");
		getch();
	}
	else
	{
		printf("tapez le code de Fillier : ");
		scanf("%s",codef);
		while(!feof(f))
		{
			fscanf(f,"%s\n%s\n\n",tmp.nom_fill,tmp.code_fill);
			if(strcmp(codef , tmp.code_fill) == 0)
			{
				system("cls");
				printf("\n\nENTRER LES NOUVEAUX DANNEES DU Fillier '%s'\n",tmp.nom_fill);
				printf("\n\nentrer le nom du Fillier [utiliser _ au lieu d'espace] : ");
				scanf("%s",tmp.nom_fill);
				printf("\n\ntapez le code du filliers : ");
				scanf("%s",tmp.code_fill);
				system("cls");
				qwerty=1;
			}
			fprintf(g,"%s\n%s\n\n",tmp.nom_fill,tmp.code_fill);
		}
		fclose(f);
		fclose(g);
	}
	return qwerty;
}





//*****************************************
void copier_fill(void)
{
	fillier tmp15;
	tmp15.code_fill=(char*)malloc(sizeof(char)*6);
	tmp15.nom_fill=(char*)malloc(sizeof(char)*50);
	FILE *f,*g;
	f=fopen("./Fillier/Filliers_save.txt" , "w+");
	g=fopen("./Fillier/Filliers_save_tmp.txt" , "r");
	if((f==NULL) || (g==NULL))
	{
		system("cls");
		printf("\n\n\n\n\nERREUR DE(OUVERTURE || CREATION) DE FICHIER !!!\n\n\n\n");
		getch();
	}
	else
	{
		while(!feof(f))
		{
			fscanf(g,"%s\n%s\n\n",tmp15.nom_fill,tmp15.code_fill);
			fprintf(f,"%s\n%s\n\n",tmp15.nom_fill,tmp15.code_fill);
		}
		fclose(f);
		fclose(g);
	}
}





//*****************************************
int compte_fill(void)
{
	fillier tmp;
	tmp.code_fill=(char*)malloc(sizeof(char)*6);
	tmp.nom_fill=(char*)malloc(sizeof(char)*50);
	FILE *f;
	int cmp=0;
	f=fopen("./Fillier/Filliers_save.txt" , "r");
	if(f == NULL)
		return 0;

	while(!feof(f))
	{
		cmp++;
		fscanf(f,"%s\n%s\n\n",tmp.nom_fill,tmp.code_fill);
		
	}
	fclose(f);
	return cmp;
}



//***********************************************
int supp_fill(void)
{
	fillier tmp;
	tmp.code_fill=(char*)malloc(sizeof(char)*6);
	tmp.nom_fill=(char*)malloc(sizeof(char)*50);
	FILE *f,*g;
	int qwerty=0;
	g=fopen("./Fillier/Filliers_save.txt" , "r");
	f=fopen("./Fillier/Filliers_save_tmp.txt" , "w+");
	if((f==NULL) || (g==NULL))
	{
		system("cls");
		printf("\n\n\n\n\nERREUR DE(OUVERTURE || CREATION) DE FICHIER !!!\n\n\n\n");
		getch();
	}
	else
	{
		char codef[6];
		printf("tapez le code de Fillier : ");
		scanf("%s",codef);
		while(!feof(g))
		{
			fscanf(g,"%s\n%s\n\n",tmp.nom_fill,tmp.code_fill);
			if(strcmp(codef , tmp.code_fill) != 0)
				fprintf(f,"%s\n%s\n\n",tmp.nom_fill,tmp.code_fill);
			else
				if(qwerty == 0)
					qwerty=1;
		}
		fclose(f);
		fclose(g);
	}
	return qwerty;
	
}




//**********************************************************************************************************************************///
//***************************************
Elem_prof* init_prof(Elem_prof *P)
{
	Elem_prof* tmp=P;
	Elem_prof*tmp2;
	P=NULL;
	if(tmp!=NULL)
		do
		{
			tmp2=tmp;
			tmp = tmp->Suivant;
			free(tmp2->val.nom);
			free(tmp2->val.prenom);
			free(tmp2->val.CIN);
			free(tmp2->val.phone);
			free(tmp2);
		}while(tmp !=NULL);
	return P;
}



//*****************************************

Elem_prof* inser_prof(Elem_prof *P)
{
	Elem_prof *tmp=(Elem_prof*)malloc(sizeof(Elem_prof));
	tmp->val.nom=(char*)malloc(sizeof(char)*15);
	tmp->val.prenom=(char*)malloc(sizeof(char)*15);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->val.CIN=(char*)malloc(sizeof(char)*10);
	system("cls");
	printf("\nEntrer le CIN de Professeur : ");
	scanf("%s",tmp->val.CIN);
	tmp->val.CIN=strupr(tmp->val.CIN);
	printf("\n\nEntrer le nom : ");
	scanf("%s",tmp->val.nom);
	printf("\n\nEntrer le prenom : ");
	scanf("%s",tmp->val.prenom);
	printf("\n\nEntrer le Numero de telephone : ");
	scanf("%s",tmp->val.phone);
	tmp->Suivant=P;
	return tmp;
}


//*****************************************
Elem_prof* insert_prof_plus(Elem_prof* P)
{
	char check;
	system("cls");
	do
	{
		P=inser_prof(P);
		printf("\n\nVoulez vous continuee [Y|y] ?\t");
		check=getch();
	}while((check == 'y') || (check == 'Y'));
	system("cls");
	return P;
}



//***********************************************
void sauvegarde_prof(Elem_prof *P)
{
	Elem_prof *tmp=P;
	FILE *f;
	int cmp=0;
	f=fopen("./Professeur/list_prof.txt" , "a");
	system("cls");
	if (P == NULL)
		printf("\n\n\n\n\tPas De Professeur dans la liste !!!!\n\n");
	if (f == NULL)
		printf("\n\n\n\n\tERREUR de création de Fichier !!\n\n\n\n\n");
	if ( (f != NULL) && (P != NULL) )
	{
		while(tmp!=NULL)
		{
			cmp++;
			fprintf(f, "%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			tmp=tmp->Suivant;
		}
		printf("\n\n\n\n\n@@@@@@@\tVous avez sauvegardee %d Professeur's'",cmp);
		fclose(f);
	}
	getch();
}




//*************************************************
void sauvegarde_prof11(Elem_prof *P)
{
	Elem_prof *tmp=P;
	FILE *f;
	f=fopen("./Professeur/list_prof.txt" , "a");
	system("cls");
	if ( (f != NULL) && (P != NULL) )
	{
		while(tmp!=NULL)
		{
			fprintf(f, "%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			tmp=tmp->Suivant;
		}
		fclose(f);
	}
}



//*****************************************************
void affiche_new_prof(Elem_prof *P)
{
	Elem_prof *tmp=P;
	system("cls");
	if (tmp == NULL)
	{
		printf("\n\n\n\n\n\tPas de Professeur Non Sauvegardee !!\n\n\n\n");
	}
	else
	{
		while(tmp!=NULL)
		{
			printf("\nnom : %s,\tprenom : %s,\tCIN : %s,\ttelephone : %s\n",tmp->val.nom,tmp->val.prenom,tmp->val.CIN,tmp->val.phone);
			tmp=tmp->Suivant;
		}
	}
	getch();
}


//*************************************************
void read_prof(void)
{
	Elem_prof* tmp;
	tmp=(Elem_prof*)malloc(sizeof(Elem_prof));
	tmp->val.nom=(char*)malloc(sizeof(char)*15);
	tmp->val.prenom=(char*)malloc(sizeof(char)*15);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->val.CIN=(char*)malloc(sizeof(char)*10);
	FILE *f;
	f=fopen("./Professeur/list_prof.txt" , "r");
	system("cls");
	if(f == NULL)
	{
		printf("\n\n\n\nPAS d'etudiant Sauvegardee !!!!\n\n\n");
	}
	else
	{
		while(!feof(f))
		{
			fscanf(f, "%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			printf("\nnom : %s,\tprenom : %s,\tCIN : %s,\ttelephone : %s\n",tmp->val.nom,tmp->val.prenom,tmp->val.CIN,tmp->val.phone);
		}
	}
	getch();
	fclose(f);
	free(tmp->val.CIN);
	free(tmp->val.phone);
	free(tmp->val.prenom);
	free(tmp->val.nom);
	free(tmp);
}




//*****************************************************
int compte_prof(void)
{
	Elem_prof* tmp;
	tmp=(Elem_prof*)malloc(sizeof(Elem_prof));
	tmp->val.nom=(char*)malloc(sizeof(char)*15);
	tmp->val.prenom=(char*)malloc(sizeof(char)*15);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->val.CIN=(char*)malloc(sizeof(char)*10);
	FILE *f;
	int cmp=0;
	f=fopen("./Professeur/list_prof.txt" , "r");
	if(f == NULL)
		return 0;
	else
	{
		while(!feof(f))
		{
			cmp++;
			fscanf(f, "%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
		}
	}
	fclose(f);
	free(tmp->val.CIN);
	free(tmp->val.phone);
	free(tmp->val.prenom);
	free(tmp->val.nom);
	free(tmp);
	return cmp;
}




//***********************************************************
int supp_prof(void)
{
	Elem_prof* tmp;
	tmp=(Elem_prof*)malloc(sizeof(Elem_prof));
	tmp->val.nom=(char*)malloc(sizeof(char)*15);
	tmp->val.prenom=(char*)malloc(sizeof(char)*15);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->val.CIN=(char*)malloc(sizeof(char)*10);
	FILE *f,*g;
	char *cin=(char*)malloc(sizeof(char)*10);
	f=fopen("./Professeur/list_prof.txt" , "r");
	g=fopen("./Professeur/list_prof_tmp.txt" , "w+");
	int a=0;
	system("cls");
	if(f == NULL)
	{
		printf("\n\n\n\nPAS d'etudiant Sauvegardee !!!!\n\n\n");
		getch();
	}
	else
	{
		printf("tapez le CIN du Professeur : ");
		scanf("%s",cin);
		cin=strupr(cin);
		while(!feof(f))
		{
			fscanf(f,"%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			if (strcmp(cin , tmp->val.CIN) != 0)
				fprintf(g,"%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			else
				a=1;
		}
	}
	fclose(f);
	fclose(g);
	free(tmp->val.CIN);
	free(tmp->val.phone);
	free(tmp->val.prenom);
	free(tmp->val.nom);
	free(tmp);
	return a;
}




//***********************************************
int modif_prof(void)
{
	Elem_prof* tmp;
	tmp=(Elem_prof*)malloc(sizeof(Elem_prof));
	tmp->val.nom=(char*)malloc(sizeof(char)*15);
	tmp->val.prenom=(char*)malloc(sizeof(char)*15);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->val.CIN=(char*)malloc(sizeof(char)*10);
	FILE *f,*g;
	char *cin=(char*)malloc(sizeof(char)*10);
	f=fopen("./Professeur/list_prof.txt" , "r");
	g=fopen("./Professeur/list_prof_tmp.txt" , "w+");
	int a=0;
	system("cls");
	if(f == NULL)
	{
		printf("\n\n\n\nPAS d'etudiant Sauvegardee !!!!\n\n\n");
		getch();
	}
	else
	{
		printf("tapez le CIN du Professeur : ");
		scanf("%s",cin);
		cin=strupr(cin);
		while(!feof(f))
		{
			fscanf(f,"%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			if (strcmp(cin , tmp->val.CIN) == 0)
			{
				system("cls");
				printf("\n\nENTRER LES NOUVEAUX DANNEES DU PROFESSEUR '%s %s'\n\n",tmp->val.nom,tmp->val.prenom);
				printf("\nEntrer le CIN de Professeur : ");
				scanf("%s",tmp->val.CIN);
				printf("\n\nEntrer le nom : ");
				scanf("%s",tmp->val.nom);
				printf("\n\nEntrer le prenom : ");
				scanf("%s",tmp->val.prenom);
				printf("\n\nEntrer le Numero de telephone : ");
				scanf("%s",tmp->val.phone);
				a=1;
			}
			fprintf(g,"%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
		}
	}
	fclose(f);
	fclose(g);
	free(tmp->val.CIN);
	free(tmp->val.phone);
	free(tmp->val.prenom);
	free(tmp->val.nom);
	free(tmp);
	return a;
}




//****************************************************
Elem_prof* find_prof(char *CIN)
{
	Elem_prof* tmp;
	tmp=(Elem_prof*)malloc(sizeof(Elem_prof));
	tmp->val.nom=(char*)malloc(sizeof(char)*15);
	tmp->val.prenom=(char*)malloc(sizeof(char)*15);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->val.CIN=(char*)malloc(sizeof(char)*10);
	FILE *f;
	f=fopen("./Professeur/list_prof.txt" , "r");
	if(f == NULL)
		return NULL;
	else
	{
		while(!feof(f))
		{
			fscanf(f, "%s\n%s\n%s\n%s\n\n",tmp->val.CIN,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			if(strcmp(CIN , tmp->val.CIN) == 0)
			{
				fclose(f);
				return tmp;
			}
		}
	}
	fclose(f);
	free(tmp->val.CIN);
	free(tmp->val.phone);
	free(tmp->val.prenom);
	free(tmp->val.nom);
	free(tmp);
	return NULL;

}




//****************************************************
int insert_prof_mod(void)
{
	FILE *f;
	Elem_prof *tmp;
	char *cint=(char*)malloc(sizeof(char)*10);
	int nmod;
	char check,check0;
	do
	{
		system("cls");
		printf("Entrer le CIN du Professeur : ");
		scanf("%s",cint);
		cint=strupr(cint);
		tmp=find_prof(cint);
		if(tmp == NULL)
		{
			printf("\n\nLe Professeur '%s' N'est pas Trouve\n\n",cint);
			system("cls");
		}
		else
		{
			system("cls");
			printf("\n\nLes Modules ensegniees Par Le Professeur %s %s ::\n\n\n",tmp->val.nom,tmp->val.prenom);
			f=fopen("./Professeur/list_prof_mod.txt" , "a");
			do
			{
				printf("\n\nTapez -1 dans le Numero de Module pour FINIR !! \n\n\n");
				printf("Entrer le Numero De module : ");
				scanf("%d",&nmod);
				if (nmod == -1)
					break;			
				fprintf(f, "%d\t%d\n",cint,nmod);
			}while(true);
			free(tmp->val.CIN);
			free(tmp->val.phone);
			free(tmp->val.prenom);
			free(tmp->val.nom);
			free(tmp);
		}
		printf("\n\n\nVoulez Reessayez ?\t\n");
		check0=getch();
		system("cls");

	}while((check0 == 'y') || (check0 == 'Y'));
	
	fclose(f);
}


//*******************************************************************************************************************************//
//**************************************
Elem_modu* init_mod(Elem_modu *N)
{
	Elem_modu* tmp=N;
	Elem_modu* tmp2=N;
	N=NULL;
	if(tmp!=NULL)
		do
		{
			tmp2=tmp;
			tmp = tmp->Suivant;
			free(tmp2->val.nom);
			free(tmp2);
		}while(tmp !=NULL);
	return N;
}


//************************************
Elem_modu* inserte_modu(Elem_modu* M)
{
	Elem_modu* tmp=(Elem_modu*)malloc(sizeof(Elem_modu));
	tmp->val.nom=(char*)malloc(sizeof(char)*50);
	system("cls");
	printf("\nentrer le Numero de module : ");
	scanf("%d",&(tmp->val.num_mod));
	printf("\nentrer le nom du modul [utiliser _ au lieu d'espace] : ");
	scanf("%s",tmp->val.nom);
	printf("\ntapez la duree du modul (en semaine) : ");
	scanf("%d",&(tmp->val.duree));
	printf("\nqu'il est le semestre de ce modul ? 	S");
	scanf("%d",&(tmp->val.semestre));
	tmp->Suivant = M;
	return tmp;
}




//*************************************
Elem_modu* inserte_modu_plus(Elem_modu* M )
{
	int n;
	system("cls");
	printf("\n\ntapez le nombre des modules a ajoutees : ");
	scanf("%d",&n);
	system("cls");
	for(int i=0 ; i < n ; i++) 
	{
		M=inserte_modu(M);
	}
	return M;
}




//************************************
void sauv_list_modu(Elem_modu* M)
{
	FILE *f;
	Elem_modu *tmp=M;
	int cmp=0;
	if(tmp == NULL)
		printf("\n\nPas de sauvegarde pour une list vide !!! \n\n\n");
		
	else
	{
		f=fopen("./module/Modules_save.txt" , "a");
		if(f != NULL)
		{
			while(tmp!=NULL)
			{
				cmp++;
				fprintf(f,"%s\n%d\n%d\n%d\n\n",tmp->val.nom,tmp->val.num_mod,tmp->val.duree,tmp->val.semestre);
				tmp=tmp->Suivant;
			}
			fclose(f);
		}
		
		printf("Vous avez sauvegardees %d Module(s)",cmp);
		getch();
	}
}




//**************************************
void affiche_new_mod(Elem_modu* M)
{
	if(M==NULL)
	{
		printf("\n\n\nPAS D'ELEMET DANS LA LIST !!!\n\n\n\n\n");
		getch();
		system("cls");
	}
	else
	{
		Elem_modu* tmp=M;
		while(tmp!=NULL)
		{
			printf("Numero de module :%d\tnom :%s\tSemestre :%d\tDuree en semaine :%d\n\n",tmp->val.num_mod,tmp->val.nom,tmp->val.semestre,tmp->val.duree);
			tmp=tmp->Suivant;
		}
		getch();
	}
	
}




//***************************************
void read_modu(void)
{
	module* tmp=(module*)malloc(sizeof(module));
	tmp->nom=(char*)malloc(sizeof(char)*50);
	FILE *f;
	
	f=fopen("./module/Modules_save.txt" , "r");
	system("cls");
	if(f== NULL)
	{
		printf("\n\n\n\nPAS de Module Sauvegardee !!!!\n\n\n");
	}
	else
	{
		while(!feof(f))
		{
			if(feof(f))
				break;
			fscanf(f,"%s\n%d\n%d\n%d\n\n",tmp->nom,&(tmp->num_mod),&(tmp->duree),&(tmp->semestre));
			printf("\nNumero de module :%d\tnom :%s\tSemestre :%d\tDuree en semaine :%d\n",tmp->num_mod,tmp->nom,tmp->semestre,tmp->duree);
		}
	}
	getch();
	free(tmp);
	fclose(f);
}


//***************************
int modife_modul(void)
{
	module tmp;
	tmp.nom=(char*)malloc(sizeof(char)*50);
	FILE *f,*g;
	int NM_tmp;
	int qwerty=0;
	f=fopen("./module/Modules_save.txt" , "r");
	g=fopen("./module/Modules_tmp.txt" , "w+");
	if((f==NULL) || (g==NULL))
	{
		system("cls");
		printf("\n\n\n\n\nERREUR DE(OUVERTURE || CREATION) DE FICHIER !!!\n\n\n\n");
		getch();
	}
	else
	{
		printf("tapez le Numero du module : ");
		scanf("%d",&NM_tmp);
		while(!feof(f))
		{
			fscanf(f,"%s\n%d\n%d\n%d\n\n",tmp.nom,&(tmp.num_mod),&(tmp.duree),&(tmp.semestre));
			if(tmp.num_mod == NM_tmp)
			{
				system("cls");
				printf("\n\nENTRER LES NOUVEAUX DANNEES DU MODULE '%s'\n",tmp.nom);
				printf("\nentrer le Numero de module : ");
				scanf("%d",&(tmp.num_mod));
				printf("\nentrer le nom du module : ");
				scanf("%s",tmp.nom);
				printf("\ntapez la duree du module (en semaine) : ");
				scanf("%d",&(tmp.duree));
				printf("\nqu'il est le semestre de ce module ? 	S");
				scanf("%d",&(tmp.semestre));
				system("cls");
				qwerty=1;
			}
			fprintf(g,"%s\n%d\n%d\n%d\n\n",tmp.nom,tmp.num_mod,tmp.duree,tmp.semestre);
		}
		fclose(f);
		fclose(g);
	}
	return qwerty;
}





//*****************************************
void copier_mod(void)
{
	module tmp15;
	tmp15.nom=(char*)malloc(sizeof(char)*50);
	FILE *f,*g;
	f=fopen("./module/Modules_save.txt" , "r");
	g=fopen("./module/Modules_tmp.txt" , "w+");
	if((f==NULL) || (g==NULL))
	{
		system("cls");
		printf("\n\n\n\n\nERREUR DE(OUVERTURE || CREATION) DE FICHIER !!!\n\n\n\n");
		getch();
	}
	else
	{
		while(!feof(f))
		{
			fscanf(f,"%s\n%d\n%d\n%d\n\n",tmp15.nom,&(tmp15.num_mod),&(tmp15.duree),&(tmp15.semestre));
			fprintf(g,"%s\n%d\n%d\n%d\n\n",tmp15.nom,tmp15.num_mod,tmp15.duree,tmp15.semestre);
		}
		fclose(f);
		fclose(g);
	}
	free(tmp15.nom);
}





//*****************************************
int compte_mod(void)
{
	module* tmp=(module*)malloc(sizeof(module));
	tmp->nom=(char*)malloc(sizeof(char)*50);
	FILE *f;
	int cmp=0;
	f=fopen("./module/Modules_save.txt" , "r");
	if(f == NULL)
		return 0;

	while(!feof(f))
	{
		cmp++;
		fscanf(f,"%s\n%d\n%d\n%d\n\n",tmp->nom,&(tmp->num_mod),&(tmp->duree),&(tmp->semestre));
		
	}
	fclose(f);
	free(tmp->nom);
	free(tmp);
	return cmp;
}



//***********************************************
int supp_mod(void)
{
	module tmp15;
	tmp15.nom=(char*)malloc(sizeof(char)*50);
	FILE *f,*g;
	int qwerty=0;
	g=fopen("./module/Modules_save.txt" , "r");
	f=fopen("./module/Modules_tmp.txt" , "w+");
	if((f==NULL) || (g==NULL))
	{
		system("cls");
		printf("\n\n\n\n\nERREUR DE(OUVERTURE || CREATION) DE FICHIER !!!\n\n\n\n");
		getch();
	}
	else
	{
		int num_m;
		printf("entrer le Numero du module : ");
		scanf("%d",&num_m);
		while(!feof(g))
		{
			fscanf(g,"%s\n%d\n%d\n%d\n\n",tmp15.nom,&(tmp15.num_mod),&(tmp15.duree),&(tmp15.semestre));
			if(num_m != tmp15.num_mod)
				fprintf(f,"%s\n%d\n%d\n%d\n\n",tmp15.nom,tmp15.num_mod,tmp15.duree,tmp15.semestre);
			else
				if(qwerty == 0)
					qwerty=1;
		}
		fclose(f);
		fclose(g);
	}
	return qwerty;
	
}




//*******************************************NOTE**********************************************************//

Elem_note* init_note(Elem_note *N)
{
	Elem_note* tmp=N;
	Elem_note* tmp2=N;
	N=NULL;
	if(tmp!=NULL)
	do
	{
		tmp2=tmp;
		tmp = tmp->Suivant;
		free(tmp2->val.cne);
		free(tmp2);
	}while(tmp != NULL);
	return N;
}




//**************************************
Elem_note* inserte_note_mod(Elem_note* N , int num_mod )
{
	Elem_note* Nouveau;
	Nouveau=(Elem_note*)malloc(sizeof(Elem_note));
	Nouveau->val.cne=(char*)malloc(sizeof(char)*10);
	system("cls");
	if (N==NULL)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\non va initialiser la liste\n\n");
		getch();
		system("cls");
	}

	printf("\n\n\nEntrer le CNE de l'etudiant : ");
	scanf("%s",Nouveau->val.cne);
	Nouveau->val.cne=strupr(Nouveau->val.cne);
	printf("\n\nEntrer la note du DS1 : ");
	scanf("%d", &(Nouveau->val.nt_DS1));
	if((Nouveau->val.nt_DS1 >= 20) || (Nouveau->val.nt_DS1 <= 0))
		while((Nouveau->val.nt_DS1 >= 20) || (Nouveau->val.nt_DS1 <= 0))
		{
			printf("\nla note doit etre entre 0 et 20!!!!!\n");
			printf("\n\nRe-entrer la note du DS1 : ");
			scanf("%d", &(Nouveau->val.nt_DS1));
		}
	printf("\n\nEntrer la note du DS2 : ");
	scanf("%d", &(Nouveau->val.nt_DS2));
	if((Nouveau->val.nt_DS2 >= 20) || (Nouveau->val.nt_DS2 <= 0))
		while((Nouveau->val.nt_DS2 >= 20) || (Nouveau->val.nt_DS2 <= 0))
		{
			printf("\nla note doit etre entre 0 et 20!!!!!\n");
			printf("\n\nRe-entrer la note du DS1 : ");
			scanf("%d", &(Nouveau->val.nt_DS2));
		}
	Nouveau->val.num_mod=num_mod;
	printf("\n\n");
	Nouveau->Suivant = N;
	return Nouveau;
}



//**************************************
Elem_note* inserer_note_plus_mod(Elem_note* F)
{
	int num_mod;
	char check;
	printf("\n\n\n\nentrer le numero de module : ");
	scanf("%d",&num_mod);
	system("cls");
	do
	{
		F=inserte_note_mod(F,num_mod);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("Voulez vous continue [y/n] ??\t");
		check=getch();
		system("cls");
	}while((check == 'y') || (check == 'Y'));
	return F;
}



//**************************************
Elem_note* inserte_note_cne(Elem_note* N , char *cne )
{
	Elem_note* Nouveau;
	Nouveau=(Elem_note*)malloc(sizeof(Elem_note));
	Nouveau->val.cne=(char*)malloc(sizeof(char)*11);
	system("cls");
	if (N==NULL)
	{
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\non va initialiser la liste\n\n");
		getch();
		system("cls");
	}
		
	printf("\nEntrer le numero de module : ");
	scanf("%d", &(Nouveau->val.num_mod));
	printf("\n\nEntrer la note du DS1 : ");
	scanf("%d", &(Nouveau->val.nt_DS1));
	if((Nouveau->val.nt_DS1 > 20) || (Nouveau->val.nt_DS1 < 0))
		while((Nouveau->val.nt_DS1 > 20) || (Nouveau->val.nt_DS1 < 0))
		{
			printf("\nla note doit etre entre 0 et 20!!!!!\n");
			printf("\n\nRe-entrer la note du DS1 : ");
			scanf("%d", &(Nouveau->val.nt_DS1));
		}
	printf("\n\nEntrer la note du DS2 : ");
	scanf("%d", &(Nouveau->val.nt_DS2));
	if((Nouveau->val.nt_DS2 > 20) || (Nouveau->val.nt_DS2 < 0))
		while((Nouveau->val.nt_DS2 > 20) || (Nouveau->val.nt_DS2 < 0))
		{
			printf("\nla note doit etre entre 0 et 20!!!!!\n");
			printf("\n\nRe-entrer la note du DS2 : ");
			scanf("%d", &(Nouveau->val.nt_DS2));
		}
	strcpy(Nouveau->val.cne , cne);
	printf("\n\n");
	Nouveau->Suivant = N;
	return Nouveau;
}



//**************************************
Elem_note* inserer_note_plus_cne(Elem_note* F)
{
	char* cne1=(char*)malloc(sizeof(char)*11);
	char check;
	do
	{
		printf("\n\nentrer le CNE de l'etudiant : ");
		scanf("%s",cne1);
		cne1=strupr(cne1);
		if(cherche_etu_simple(cne1) == NULL)
		{
			system("cls");
			printf("\n\n\n\nLe CNE '%s' n'existe pas parmi les etudiant sauvegardee !!!!\n\n",cne1);
			getch();
		}
		else
		{
			F=inserte_note_cne(F,cne1);
		}
		system("cls");
		printf("\n\n\n\n\n\n\n");
		printf("Voulez vous continue [y|Y] ??\t");
		check=getch();
		system("cls");
	}while((check == 'y') || (check == 'Y'));
	free(cne1);
	return F;
}



//************************
void sauver_liste_note(Elem_note*F)
{
	FILE*f;
	Elem_note* prem = F;
	int cmp=0;
	system("cls");
	 // si liste non vide
	if(prem!=NULL)
	{
		f=fopen("./Note/notes.txt","a");
		if(f == NULL)
			f=fopen("./Note/notes.txt","w+");
		if(f!=NULL)
		{
			// parcourir la liste jusque fin
			while(prem!=NULL)
			{
				fprintf(f,"%s\t\t%d\t%d\t%d\n",prem->val.cne,prem->val.num_mod,prem->val.nt_DS1,prem->val.nt_DS2); // copier chaque maillon
				prem=prem->Suivant; // passer au maillon suivant
				++cmp;
			}
			fclose(f); // fermer le fichier
			
			printf("\n\n\n\n\n\n@@@@vous avez sauvegardee les notes de %d etudiants \n\n\n",cmp);
			getch();
		}
		else
			printf("\n\nerreur création fichier\n");
	}
	else
		printf("pa0s de sauvegarde pour une liste vide\n");
	
}



//************************
void sauver_liste_note11(Elem_note*F)
{
	FILE*f;;
	Elem_note* prem = F;
	system("cls");
	// si liste non vide
	if(prem!=NULL)
	{
		f=fopen("./Note/notes.txt","a");
		if(f == NULL)
			f=fopen("./Note/notes.txt","w+");
		if(f!=NULL)
		{
			// parcourir la liste jusque fin
			while(prem!=NULL)
			{
				fprintf(f,"%s\t\t%d\t%d\t%d\n",prem->val.cne,prem->val.num_mod,prem->val.nt_DS1,prem->val.nt_DS2); // copier chaque maillon
				prem=prem->Suivant; // passer au maillon suivant
			}
			fclose(f); // fermer le fichier
		}
		else
			printf("\n\nerreur création fichier\n");
	}
}



//********************************
void read_note_val(void)
{
	note *tmp;
	FILE *f;
	FILE *g;
	etudiant *target;
	int tmp_mod;
	tmp=(note*)malloc(sizeof(note));
	tmp->cne=(char*)malloc(sizeof(char)*11);
	f=fopen("./Note/notes.txt" , "r");
	if(f==NULL)
		f=fopen("./Note/notes.txt" , "w+");
	printf("entrer le Numero de module : ");
	scanf("%d",&tmp_mod);
	while (!feof(f))
	{
		fscanf(f,"%s\t\t%d\t%d\t%d",tmp->cne,&(tmp->num_mod),&(tmp->nt_DS1),&(tmp->nt_DS2));
		if(((tmp->nt_DS1+tmp->nt_DS2)/2 >= 12) && (tmp_mod == tmp->num_mod))
		{
			target=cherche_etu_simple(tmp->cne);
			if(target != NULL)
					printf("\nCNE: %s\t\tnom: %s\tprenom: %s\tnote DS1: %d\tnote DS2: %d\tLa Moyenne: %d\n",target->cne,target->nom,target->prenom,tmp->nt_DS1,tmp->nt_DS2,(tmp->nt_DS1+tmp->nt_DS2)/2);
		}
	}
	getch();
	fclose(f);
	free(tmp->cne);
	free(tmp);
}





//********************************
void read_note_modu(void)
{
	note *tmp;
	FILE *f;
	FILE *g;
	etudiant *target;
	int tmp_mod;
	tmp=(note*)malloc(sizeof(note));
	tmp->cne=(char*)malloc(sizeof(char)*11);
	f=fopen("./Note/notes.txt" , "r");
	if(f==NULL)
		f=fopen("./Note/notes.txt" , "w+");
	printf("entrer le Numero de module : ");
	scanf("%d",&tmp_mod);
	printf("Liste de Notes du module N'%d : ",tmp_mod);
	//ajouter une fonction de recherche dans le fichier des modules pour verifier s'il existe d'abord
	while (!feof(f))
	{
		fscanf(f,"%s\t\t%d\t%d\t%d",tmp->cne,&(tmp->num_mod),&(tmp->nt_DS1),&(tmp->nt_DS2));
		if(tmp_mod == tmp->num_mod)
		{
			target=cherche_etu_simple(tmp->cne);
			if(target != NULL)
					printf("\nCNE: %s\t\tnom: %s\tprenom: %s\tnote DS1: %d\tnote DS2: %d\tLa Moyenne: %d\n",target->cne,target->nom,target->prenom,tmp->nt_DS1,tmp->nt_DS2,(tmp->nt_DS1+tmp->nt_DS2)/2);
		}
	}
	getch();
	fclose(f);
	free(tmp->cne);
	free(tmp);
}




//********************************
void read_note_cne(void)
{
	note *tmp;
	FILE *f;
	FILE *g;
	etudiant *target;
	char *tmp_cne=(char*)malloc(sizeof(char)*11);
	tmp=(note*)malloc(sizeof(note));
	tmp->cne=(char*)malloc(sizeof(char)*11);
	f=fopen("./Note/notes.txt" , "r");
	if(f==NULL)
		f=fopen("./Note/notes.txt" , "w+");
	printf("entrer le CNE de l'etudiant : ");
	scanf("%s",tmp_cne);
	tmp_cne=strupr(tmp_cne);
	target=cherche_etu_simple(tmp_cne);
	if(target != NULL)
	{
		printf("les Notes de l'etudiant: CNE: %s, nom: %s, prenom: %s :\n\n",tmp_cne,target->nom,target->prenom);
		while (!feof(f))
		{
			fscanf(f,"%s\t\t%d\t%d\t%d",tmp->cne,&(tmp->num_mod),&(tmp->nt_DS1),&(tmp->nt_DS2));
			if(strcmp(tmp_cne , tmp->cne) == 0)
			{
				printf("\nNumero de module: %d\tnote DS1: %d\tnote DS2: %d\tLa Moyenne: %d\n",tmp->num_mod,tmp->nt_DS1,tmp->nt_DS2,(tmp->nt_DS1+tmp->nt_DS2)/2);
			}
		}
	}
	else
	{
		system("cls");
		printf("\n\n\n\n\nLe CNE '%s' n'est pa trouvee \n\n\n",tmp_cne);
		getch();
	}
	getch();
	fclose(f);
	free(tmp->cne);
	free(tmp);
}





//********************************
void read_note(void)
{
	note *tmp;
	FILE *f;
	FILE *g;
	etudiant *target;
	tmp=(note*)malloc(sizeof(note));
	tmp->cne=(char*)malloc(sizeof(char)*11);
	f=fopen("./Note/notes.txt" , "r");
	if(f==NULL)
		f=fopen("./Note/notes.txt" , "w+");
	else
		while (!feof(f))
		{
			fscanf(f,"%s\t\t%d\t%d\t%d",tmp->cne,&(tmp->num_mod),&(tmp->nt_DS1),&(tmp->nt_DS2));
			target=cherche_etu_simple(tmp->cne);
			if(target == NULL)
				continue;
			else
				printf("\nCNE: %s\tN? Module: %d\tnom: %s\tprenom: %s\nnote DS1: %d\tnote DS2: %d\tLa Moyenne: %d\n\n",target->cne,tmp->num_mod,target->nom,target->prenom,tmp->nt_DS1,tmp->nt_DS2,(tmp->nt_DS1+tmp->nt_DS2)/2);
		}
	fclose(f);
	free(tmp->cne);
	free(tmp);
}






//**********************************************ETUDIANT***********************************************************/

Elem_etud* init_etud ( Elem_etud *F )
{
	Elem_etud* tmp=F;
	Elem_etud* tmp2=F;
	F=NULL;
	if(tmp!=NULL)
	do
	{
		tmp2=tmp;
		tmp = tmp->Suivant;
		free(tmp2->val.cne);
		free(tmp2->val.nom);
		free(tmp2->val.prenom);
		free(tmp2->val.code_fill);
		free(tmp2);
	}while(tmp!=NULL);
	
	return F;
}

//************************
Elem_etud* InsererEnTete(Elem_etud* L , char* code_fill)
{
	Elem_etud* Nouveau;
	Nouveau=(Elem_etud*)malloc(sizeof(Elem_etud));
	Nouveau->val.cne=(char*)malloc(sizeof(char)*10);
	Nouveau->val.nom=(char*)malloc(sizeof(char)*30);
	Nouveau->val.prenom=(char*)malloc(sizeof(char)*30);
	Nouveau->val.phone=(char*)malloc(sizeof(char)*15);
	Nouveau->val.code_fill=(char*)malloc(sizeof(char)*6);
	if (L==NULL)
	{
		printf("\n\n\n\n\n\n\n\n\n");
		printf("\non va initialiser la liste\n\n");
		getch();
		system("cls");
	}
	printf("\n\nEntrer le CNE de l'etudiant : ");
	scanf("%s",Nouveau->val.cne);
	Nouveau->val.cne=strupr(Nouveau->val.cne);
	printf("\n\nEntrer le nom de l'etudiant : ");
	scanf("%s",Nouveau->val.nom);
	printf("\n\nEntrer le prenom de l'etudiant : ");
	scanf("%s",Nouveau->val.prenom);
	printf("\n\nEntrer le numero de telephone de l'etudiant : ");
	scanf("%s",Nouveau->val.phone);
	strcpy(Nouveau->val.code_fill , code_fill);
	printf("\n\n");
	Nouveau->Suivant = L;
	return Nouveau;
}



//************************
Elem_etud* inserer_etud_plus(Elem_etud* F)
{
	int n;
	char *code_fill=(char*)malloc(sizeof(char)*5);
	printf("\n\n\nentrer le nombre des etudiants a ajoutees : ");
	scanf("%d",&n);
	printf("\n\n\n\nentrer le code de Fillier : ");
	scanf("%s",code_fill);
	for(int i=0 ; i<n ; i++)
	{
		F=InsererEnTete(F , code_fill);
		system("cls");
	}
	return F;
}


//************************
void sauver_liste11(Elem_etud*F)
{
	FILE*f;
	Elem_etud *prem = F;
	int cmp=0;
	 // si liste non vide
	if(prem!=NULL)
	{
	 	
		f=fopen("./etudiant/save liste.txt","a");
		if(f == NULL)
			f=fopen("./etudiant/save liste.txt","w+");
		if(f!=NULL)
		{
			// parcourir la liste jusque fin
			while(prem!=NULL)
			{
				fprintf(f,"%s\n%s\n%s\n%s\n",prem->val.cne,prem->val.nom,prem->val.prenom,prem->val.phone); // copier chaque maillon
				prem=prem->Suivant; // passer au maillon suivant
				++cmp;
			}
			fclose(f); // fermer le fichier
			printf("\n\n@@@@vous avez sauvegardee %d etudiants \n\n\n",cmp);
		}
		else
			printf("\nerreur création fichier\n");
	}
}



//****************************
void sauve_fill_cne(Elem_etud *F)
{
	FILE*f;
	Elem_etud *prem=F;
	f=fopen("./etudiant/CNE-CODE_FILL.txt","a");
	if(f!=NULL)
	{
		// parcourir la liste jusque fin
		while(prem!=NULL)
		{
			fprintf(f,"%s\t\t%s\n",prem->val.cne,prem->val.code_fill); // copier chaque maillon
			prem=prem->Suivant; // passer au maillon suivant
		}
		fclose(f); // fermer le fichier
	}
	else
		printf("erreur création fichier\n");
}




//****************************
void sauve_fill_cne_delete(char* cne)
{
	FILE*f;
	FILE*g;
	char *cne1=(char*)malloc(sizeof(char)*11);
	char *code_fill=(char*)malloc(sizeof(char)*5);
	f=fopen("./etudiant/CNE-CODE_FILL.txt" , "r");
	g=fopen("./etudiant/CNE-CODE_FILL tmp.txt" , "w+");
	if(f == NULL)
		printf("\n\nErreur d'ouverture de fichier\n");
	if(f!=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s\t\t%s\n",cne1,code_fill);
			if(strcmp(cne , cne1) != 0)
				fprintf(g,"%s\t\t%s\n",cne1,code_fill);
		}
	}
	else
		printf("erreur création fichier\n");
	fclose(f);
}



//************************
void sauver_liste(Elem_etud*F)
{
	FILE*f;
	Elem_etud *prem = F;
	int cmp=0;
	 // si liste non vide
	 if(prem!=NULL)
	 {
		f=fopen("./etudiant/save liste.txt","a");
		if(f!=NULL)
		{
			// parcourir la liste jusque fin
			while(prem!=NULL)
			{
				fprintf(f,"%s\n%s\n%s\n%s\n",prem->val.cne,prem->val.nom,prem->val.prenom,prem->val.phone); // copier chaque maillon
				prem=prem->Suivant; // passer au maillon suivant
				++cmp;
			}
			fclose(f); // fermer le fichier
			system("cls");
			printf("\n\n\n\n\n\n\n\n@@@@vous avez sauvegardee %d etudiants \n\n\n",cmp);
			getch();
		}
			 else
			 printf("erreur création fichier\n");
	}
	else
	{
	 	system("cls");
		printf("\n\n\n\npas de sauvegarde pour une liste vide\n");
		getch();
	}
}




//************************
int compte_etud_sauv(void)
{
	
	FILE *f;
	int cmp=0;
	f=fopen("./etudiant/save liste.txt" , "r");
	if(f==NULL)
		return 0;
	char* cne=(char*)malloc(sizeof(char)*11);
	char* nom=(char*)malloc(sizeof(char)*30);
	char* prenom=(char*)malloc(sizeof(char)*30);
	char* phone=(char*)malloc(sizeof(char)*15);
	while (!feof(f))
	{
		fscanf(f,"%s\n%s\n%s\n%s\n",cne,nom,prenom,phone);
		cmp++;
	}
	fclose(f);
	return cmp;
}




//************************
void read_etu(void)
{
	Elem_etud *tmp;
	FILE *f;
	tmp=(Elem_etud*)malloc(sizeof(Elem_etud));
	tmp->val.cne=(char*)malloc(sizeof(char)*11);
	tmp->val.nom=(char*)malloc(sizeof(char)*30);
	tmp->val.prenom=(char*)malloc(sizeof(char)*30);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->Suivant=NULL;
	f=fopen("./etudiant/save liste.txt" , "r");
	if(f==NULL)
	{
		system("cls");
		printf("\n\n\nERREURE DE CREATION DE FICHIER !!!!!\n\n");
		getch();
	}	
	while (!feof(f))
	{
		fscanf(f,"%s\n%s\n%s\n%s\n",tmp->val.cne,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
		printf("CNE: %s, nom: %s, prenom: %s, number phone: %s;\n\n",tmp->val.cne,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
	}
	free(tmp->val.cne);
	free(tmp->val.nom);
	free(tmp->val.prenom);
	free(tmp->val.phone);
	free(tmp);
	fclose(f);
}



//************************
void sauv_supp(void)
{
	Elem_etud *tmp ;
	FILE *f;
	FILE *g;
	tmp=(Elem_etud*)malloc(sizeof(Elem_etud));
	tmp->val.cne=(char*)malloc(sizeof(char)*11);
	tmp->val.nom=(char*)malloc(sizeof(char)*30);
	tmp->val.prenom=(char*)malloc(sizeof(char)*30);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->Suivant=NULL;
	f=fopen("./etudiant/save liste.txt" , "w+");
	g=fopen("./etudiant/save liste tmp.txt" , "r");
	if(g==NULL || f==NULL)
	{
		system("cls");
		printf("\n\n\nERREURE DE CREATION DE FICHIER !!!!!\n\n");
		getch();
	}	
	while (!feof(g))
	{
		fscanf(g,"%s\n%s\n%s\n%s\n",tmp->val.cne,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
		fprintf(f,"%s\n%s\n%s\n%s\n",tmp->val.cne,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
	}
	free(tmp->val.cne);
	free(tmp->val.nom);
	free(tmp->val.prenom);
	free(tmp->val.phone);
	free(tmp);
	fclose(f);
	fclose(g);
}



//************************
void sauv_supp_fill(void)
{
	FILE *f;
	FILE *g;
	char *cne=(char*)malloc(sizeof(char)*11),*code_fill=(char*)malloc(sizeof(char)*5);
	f=fopen("./etudiant/CNE-CODE_FILL.txt" , "w+");
	g=fopen("./etudiant/CNE-CODE_FILL tmp.txt" , "r");
	if(g==NULL || f==NULL)
	{
		system("cls");
		printf("\n\n\nERREURE DE CREATION DE FICHIER !!!!!\n\n");
		getch();
	}	
	else
	{
		while(!feof(g))
		{
			fscanf(g,"%s\t\t%s\n",cne,code_fill);
			fprintf(f,"%s\t\t%s\n",cne,code_fill);
		}
		fclose(f);
		fclose(g); // fermer les fichiers
	}
	free(cne);
}


//************************
void affiche_new_etu(Elem_etud* F)
{
	int i;
	Elem_etud* tmp=F;
	if(F==NULL)
	{
		printf("\a\nERREUR: Pas D'Etudiant !!!!\n");
	}
	else
	{
		do
		{
			printf("\n\nCNE: %s, nom: %s, prenom: %s, number phone: %s;\n\n\n",tmp->val.cne,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
			tmp=tmp->Suivant;
			
		}while(tmp!=NULL);
	}
}




//****************************
void sauve_fill_cne_modif(char* cne , char *cne_new)
{
	FILE*f;
	FILE*g;
	char *cne1=(char*)malloc(sizeof(char)*11);
	char *code_fill=(char*)malloc(sizeof(char)*5);
	f=fopen("./etudiant/CNE-CODE_FILL.txt" , "r");
	g=fopen("./etudiant/CNE-CODE_FILL tmp.txt" , "w+");
	if(f == NULL)
		printf("\n\nErreur d'ouverture de fichier\n");
	if(f!=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s\t\t%s\n",cne1,code_fill);
			if(strcmp(cne , cne1) == 0)
				strcpy(cne1 , cne_new);
			fprintf(g,"%s\t\t%s\n",cne1,code_fill);
		}
	}
	else
		printf("erreur création fichier\n");
	free(cne1);
	free(code_fill);
	fclose(f);
	fclose(g);
}



//************************
etudiant* cherche_etu( char *cne)
{
	etudiant *target=NULL;
	FILE *f; FILE *g;
	char* cne1=(char*)malloc(sizeof(char)*11);
	char nom[30],prenom[30],phone[15];
	
	f=fopen("./etudiant/save liste.txt" , "r");
	g=fopen("./etudiant/save liste tmp.txt" , "w+");
	if(g==NULL || f==NULL)
	{
		system("cls");
		printf("\n\n\nERREURE DE CREATION DE FICHIER !!!!!\n\n");
		getch();
	}
	while (!feof(f))
	{
		fscanf(f,"%s\n%s\n%s\n%s\n",cne1,nom,prenom,phone);
		if(strcmp(cne1 , cne) == 0)
		{
			target=(etudiant*)malloc(sizeof(etudiant));
			target->cne=(char*)malloc(sizeof(char)*11);
			target->nom=(char*)malloc(sizeof(char)*30);
			target->prenom=(char*)malloc(sizeof(char)*30);
			target->phone=(char*)malloc(sizeof(char)*15);
			strcpy(target->cne , cne);
			strcpy(target->nom , nom);
			strcpy(target->prenom , prenom);
			strcpy(target->phone , phone);
		}
		
		else
		{
			fprintf(g,"%s\n%s\n%s\n%s\n",cne1,nom,prenom,phone);
			continue;
		}
	}
	free(cne1);
	fclose(g);
	fclose(f);
	
	return target;
}



//************************
int delete_etud(void)
{
	char *cne=(char*)malloc(sizeof(char)*11);;
    FILE*f;
	etudiant *target;
	printf("\n\n\nEntrer le CNE de l'etudiant : ");
	scanf("%s",cne);
	cne=strupr(cne);
	sauve_fill_cne_delete(cne);
	target=cherche_etu(cne);
	if(target == NULL)
	{
		printf("\nl'etudiant n'est pas trouvee !!\n\n");
		return 0;
	}
	else{
		printf("l'etudiant :[CNE: %s, nom: %s, prenom: %s, number phone: %s] est supprimee...\n",target->cne,target->nom,target->prenom,target->phone);
		free(cne);
		free(target->cne);
		free(target->nom);
		free(target->prenom);
		free(target->phone);
		free(target);
		return 1;
	}
}




//************************
Elem_etud* inserer_de_file(Elem_etud* tmp , Elem_etud* F)
{
	Elem_etud* Nouveau;
	Nouveau=(Elem_etud*)malloc(sizeof(Elem_etud));
	Nouveau->val.cne=(char*)malloc(sizeof(char)*11);
	Nouveau->val.nom=(char*)malloc(sizeof(char)*30);
	Nouveau->val.prenom=(char*)malloc(sizeof(char)*30);
	Nouveau->val.phone=(char*)malloc(sizeof(char)*15);
	strcpy(Nouveau->val.cne , tmp->val.cne);
	strcpy(Nouveau->val.nom , tmp->val.nom);
	strcpy(Nouveau->val.prenom , tmp->val.prenom);
	strcpy(Nouveau->val.phone , tmp->val.phone);
	Nouveau->Suivant = F;
	return Nouveau;
}



//**************************
Elem_etud* read_in_file (Elem_etud *F)
{
	Elem_etud *tmp;
	FILE *f;
	tmp=(Elem_etud*)malloc(sizeof(Elem_etud));
	tmp->val.cne=(char*)malloc(sizeof(char)*11);
	tmp->val.nom=(char*)malloc(sizeof(char)*30);
	tmp->val.prenom=(char*)malloc(sizeof(char)*30);
	tmp->val.phone=(char*)malloc(sizeof(char)*15);
	tmp->Suivant=NULL;
	f=fopen("./etudiant/save liste.txt" , "r");
	if(f==NULL)
		return NULL;
	while (!feof(f))
	{
		fscanf(f,"%d\n%s\n%s\n%s\n",tmp->val.cne,tmp->val.nom,tmp->val.prenom,tmp->val.phone);
		F=inserer_de_file(tmp , F);
	}
	fclose(f);
	return F;
}


//**************************
void cree_file_etud(void)
{
	FILE *f,*g;
	int i=0;
	etudiant *target=(etudiant*)malloc(sizeof(etudiant));
	target->cne=(char*)malloc(sizeof(char)*11);
	target->nom=(char*)malloc(sizeof(char)*30);
	target->prenom=(char*)malloc(sizeof(char)*30);
	target->phone=(char*)malloc(sizeof(char)*15);
	f=fopen("./etudiant/etudiants.txt" , "w+");
	g=fopen("./etudiant/save liste.txt" , "r");
	while(feof(g))
	{
		fscanf(g,"%s\n%s\n%s\n%s\n",target->cne,target->nom,target->prenom,target->phone);
		fprintf(f,"CNE: %s\t\tnom: %s\t\tprenom: %s\t\tnumber phone: %s\n",target->cne,target->nom,target->prenom,target->phone);
	}
	fclose(f);
	fclose(g);
}

//********************************
int cherche_etu_modif( char *cne)
{
	FILE *f; FILE *g;
	char *cne1=(char*)malloc(sizeof(char)*11);
	char nom[30],prenom[30],phone[15];
	int check=0;
	f=fopen("./etudiant/save liste.txt" , "r");
	g=fopen("./etudiant/save liste tmp.txt" , "w+");
	if(g==NULL || f==NULL)
	{
		system("cls");
		printf("\n\n\nERREURE DE CREATION DE FICHIER !!!!!\n\n");
		getch();
	}
	else
		while (!feof(f))
		{
			fscanf(f,"%s\n%s\n%s\n%s\n",cne1,nom,prenom,phone);
			if(strcmp(cne1 , cne) == 0)
			{
				system("cls");
				printf("\n\n\t\tLa saisie des Nouveau Donnees de L'etudiant %s %s\n\n",nom , prenom);
				printf("\n\nEntrer le CNE de l'etudiant : ");
				scanf("%s",cne1);
				printf("\n\nEntrer le nom de l'etudiant : ");
				scanf("%s",nom);
				printf("\n\nEntrer le prenom de l'etudiant : ");
				scanf("%s",prenom);
				printf("\n\nEntrer le numero de telephone de l'etudiant : ");
				scanf("%s",phone);
				sauve_fill_cne_modif(cne ,cne1);
				sauve_note_cne_modif(cne ,cne1);
				check = 1;
			}
			fprintf(g,"%s\n%s\n%s\n%s\n",cne1,nom,prenom,phone);
		}
	if(g != NULL)
		fclose(g);
	if(f != NULL)
		fclose(f);
	free(cne1);
	return check;
}




//********************************
void modifier_etud(Elem_etud* E)
{
	if(E != NULL)
	{
		sauver_liste11(E);
	}
	char cne[11],check;
	do
	{
		system("cls");
		printf("\n\n\nentrer le CNE de l'etudiant a modifier : ");
		scanf("%s",cne);
		if(cherche_etu_modif(cne) == 0)
		{
			printf("\n\nle CNE '%s' n'exist pas !!!\n\n",cne);
			printf("\n\n\nVoulez vous continue [Y|y] ??\t");
			check=getch();
		}
		else
		{
			sauv_supp();
			sauv_supp_fill();
			sauv_supp_note();
			
		}
		
	}while((check == 'y') || (check == 'Y'));
}




//********************************
etudiant* cherche_etu_simple( char *cne)
{
	etudiant *target=NULL;
	FILE *f; FILE *g;
	char* cne1=(char*)malloc(sizeof(char)*11);
	char *nom=(char*)malloc(sizeof(char)*30),*prenom=(char*)malloc(sizeof(char)*30),*phone=(char*)malloc(sizeof(char)*15);
	f=fopen("./etudiant/save liste.txt" , "r");
	if(f==NULL)
		printf("\n\nERREUR D'OUVERTURE DE FICHIER !!!!\n\n");
	else
	{
		while (!feof(f))
		{
			fscanf(f,"%s\n%s\n%s\n%s\n",cne1,nom,prenom,phone);
			if(strcmp(cne1 , cne) == 0)
			{
				target=(etudiant*)malloc(sizeof(etudiant));
				target->cne=(char*)malloc(sizeof(char)*11);
				target->nom=(char*)malloc(sizeof(char)*30);
				target->prenom=(char*)malloc(sizeof(char)*30);
				target->phone=(char*)malloc(sizeof(char)*15);
				strcpy(target->cne , cne);
				strcpy(target->nom , nom);
				strcpy(target->prenom , prenom);
				strcpy(target->phone , phone);
			}
		}
		fclose(f);
	}
	free(nom);
	free(prenom);
	free(phone);
	free(cne1);
	return target;
}





//****************************
void sauve_note_cne_modif(char *cne , char *cne_new)
{
	FILE*f;
	FILE*g;
	char *cne1=(char*)malloc(sizeof(char)*11);
	int nt_DS1,nt_DS2,num_mod;
	f=fopen("./Note/notes.txt" , "r");
	g=fopen("./Note/notes tmp.txt" , "w+");
	if(f == NULL)
		printf("\n\nErreur d'ouverture de fichier\n");
	if(f!=NULL)
	{
		while(!feof(f))
		{
			fscanf(f,"%s\t\t%d\t%d\t%d\n",cne1,&(num_mod),&(nt_DS1),&(nt_DS2));
			if(strcmp(cne , cne1) == 0)
				strcpy(cne1 , cne_new);
			fprintf(g,"%s\t\t%d\t%d\t%d\n",cne1,num_mod,nt_DS1,nt_DS2);
		}
	}
	else
		printf("erreur création fichier\n");
	free(cne1);
	fclose(f);
	fclose(g);
}



//*****************************
void sauv_supp_note(void)
{
	FILE *f;
	FILE *g;
	char *cne=(char*)malloc(sizeof(char)*11);
	int nt_DS1,nt_DS2,num_mod;
	f=fopen("./Note/notes.txt" , "w+");
	g=fopen("./Note/notes tmp.txt" , "r");
	if(g==NULL || f==NULL)
	{
		system("cls");
		printf("\n\n\n\nERREURE DE CREATION DE FICHIER !!!!!\n\n");
		getch();
	}	
	else
	{
		while(!feof(g))
		{
			fscanf(g,"%s\t\t%d\t%d\t%d\n",cne,&(num_mod),&(nt_DS1),&(nt_DS2));
			fprintf(f,"%s\t\t%d\t%d\t%d\n",cne,num_mod,nt_DS1,nt_DS2);
		}
		fclose(f);
		fclose(g); // fermer les fichiers
	}
	free(cne);
}
