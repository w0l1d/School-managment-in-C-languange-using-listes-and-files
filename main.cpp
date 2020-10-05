#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fonction.h"
#include<conio.h>


void menu(void)
{
	
	Elem_etud *E = NULL;
	Elem_prof *P = NULL;
	Elem_fill *F = NULL;
	Elem_modu *M = NULL;
	Elem_note *N = NULL;
	int choix0;
	do
	{	
		system("cls");
		system("color F0");
		printf( "\n#########*****MENU GENERAL*****#########\n"
				"\n1>> Gestion des Etudiants :\n"
				"\n2>> Gestion des Professeurs :\n"
				"\n3>> Gestion des Filliers :\n"
				"\n4>> Gestion des Modules :\n"
				"\n5>> Gestion des Notes :\n"
				"\n6>> Sauvegarder TOUTES :\n"
				"\n7>> QUITTER...");
		printf("\n\n\nentrer le nombre de votre choix :");
		scanf("%d",&choix0);
		system("cls");
		printf("\n");
		switch(choix0)
		{
			case 1 :		
					{
						int choix1;
						do
						{
							system("cls");
							printf(	"\n#########*****MENU D'ETUDIANT*****#########\n\n"
									"\n\tTOTALE DES ETUDIANTS SAUVEGARDEES :: %d"
									"\n\n1>> afficher les etudiants Non Sauvegardes :"
									"\n\n2>> sauvegarder et afficher toutes les etudiants :"
									"\n\n3>> ajouter des etudiant :"
									"\n\n4>> Modifier les donnees d'un etudiant :"
									"\n\n5>> supprimer des etudiant :"
									"\n\n6>> Sauvegarder :"
									"\n\n7>> Retour ....\n",compte_etud_sauv());
							printf("\n\nentrer le nombre de votre choix :");
							scanf("%d",&choix1);
							system("cls");
							printf("\n\n");
							switch(choix1)
							{
								case 1 : 	
										{
											system("cls");
											affiche_new_etu(E);
											getch();
											break;
										}



								case 2 :	
										{
											system("cls");
											sauve_fill_cne(E);
											sauver_liste11(E);
											E=init_etud(E);
											read_etu();
											getch();
											system("cls");
											break;
										}



								case 3 :	
										{
											system("cls");
											E=inserer_etud_plus(E);
											break;
										}



								case 4 :	
										{
											
											if(E!=NULL)
											{
												char check = 'y';
												printf("Voulez vous Sauvegarder les nouveaux etudiants d'Abord [Y|y] ?\t");
												check=getch();
												if((check == 'y') || (check == 'Y'))
												{
													sauve_fill_cne(E);
													sauver_liste11(E);
													E=init_etud(E);
												}
											}
											modifier_etud(E);
											break;
										}	
								

								
								case 5 :	
										{
											system("cls");
											char pick;
											int a;
											if(delete_etud()==1)
											{
												system("cls");
												printf("\n\n\n\nVoulez vous sauvegardee la suppression [Y-y | N-n] ?\t ");
												pick=getch();
												if((pick == 'Y') || (pick == 'y'))
												{
														sauv_supp();
														sauv_supp_fill();
														system("cls");
														printf("\n\n\nLa suppression est Validee !!!\n\n");
												}
												else if((pick == 'N') || (pick == 'n'))
													printf("\n\n\nla suppression n'est pas sauvegardee...\n\n");
												else
												{
													system("cls");
													printf( "\n\n\nChoix Invalide !!!!!!!!!!!"
															"\n\nla suppression n'est pas sauvegardee...\n\n");
												}													
											}
											getch();
											system("cls");
											break;

										}	



								case 6 :	
										{
											sauve_fill_cne(E);
											sauver_liste(E);
											if(E != NULL)
												E=init_etud(E);
											getch();
											break;
										}

								
								case 7 :	
										{
											system("cls");
											break;
										}



								default : 	
										{
											system("cls");
											printf("\n\n\n\n\n\n\n\n\n");
											printf("\n\n\a\a***************choix invalide *************\n\n");
											getch();
											break;
										}
							}	
						}while(choix1!=7);
					}break;


			case 2 :		
					{
						int choix1;
						do
						{
							
							system("cls");
							printf(	"\n#########*****MENU DES PROFESSEURS*****#########\n"
									"\n\tTOTALE DES MODULES SAUVEGARDEE :: %d \n"
									"\n\n1>> Ajouter des Professeurs :"
									"\n\n2>> Inserer les modules d'un Professeur :"
									"\n\n3>> Afficher les Professeurs non sauvegardee :"
									"\n\n4>> Sauvegarder et afficher toutes les Professeurs :"
									"\n\n5>> Modifier les information d'un Professeurs :"
									"\n\n6>> Supprimer un Professeurs :"
									"\n\n7>> Sauvegarder :"
									"\n\n8>> Retour ....\n",compte_prof());
							printf("\n\nEntrer le nombre de votre choix :");
							scanf("%d",&choix1);
							system("cls");
							switch(choix1)
							{
								case 1 :	P=insert_prof_plus(P);
											break;


								case 2 :	insert_prof_mod();
											break;


								case 3 :	affiche_new_prof(P);
											break;


								case 4 :	if (P != NULL)
											{
												sauvegarde_prof11(P);
												P=init_prof(P);
											}
											read_prof();
											break;


								case 5 :	
										{
											char pick;
											system("cls");
											if(modif_prof() == 1)
											{
												printf("\n\n\n\nVoulez vous sauvegardee les modification [Y-y | N-n] ?\t ");
												pick=getch();
												if((pick == 'Y') || (pick == 'y'))
												{
													int z=remove("./Professeur/list_prof.txt"),x=rename("./Professeur/list_prof_tmp.txt" , "./Professeur/list_prof.txt");
												
													if (z==0 && x==0)
														printf("\n\n\nModifications bien sauvegardees !!!\n\n");									
													else
														printf("\n\n\n\nERREUR dans 'rename' et 'remove' des fichier \n\n\n\n");
												}
												else if((pick == 'N') || (pick == 'n'))
													printf("\n\n\nModifications Non sauvegardees...\n\n");
												else
												{
													system("cls");
													printf( "\n\n\nChoix Invalide !!!!!!!!!!!"
															"\n\nModifications Non sauvegardees ...\n\n");
												}
											}
											else
												printf("\n\n\n Le CIN n'est pas trouvee !! \n\n\n");
											getch();
											break;
										}



								case 6 :	
										{
											char pick;
											system("cls");
											if(supp_prof() == 1)
											{
												printf("\n\n\n\nVoulez vous sauvegardee la suppression [Y-y | N-n] ?\t ");
												pick=getch();
												if((pick == 'Y') || (pick == 'y'))
												{
													int z=remove("./Professeur/list_prof.txt"),x=rename("./Professeur/list_prof_tmp.txt" , "./Professeur/list_prof.txt");
												
													if (z==0 && x==0)
														printf("\n\n\nLa suppression est Validee !!!\n\n");									
													else
														printf("\n\n\n\nERREUR dans 'rename' et 'remove' des fichier \n\n\n\n");
												}
												else if((pick == 'N') || (pick == 'n'))
													printf("\n\n\nla suppression n'est pas sauvegardee...\n\n");
												else
												{
													system("cls");
													printf( "\n\n\nChoix Invalide !!!!!!!!!!!"
															"\n\nla suppression n'est pas sauvegardee...\n\n");
												}
											}
											else
												printf("\n\n\n Le CIN n'est pas trouvee !! \n\n\n");
											getch();
											break;
										}
											


								case 7 :	sauvegarde_prof(P);
											P=init_prof(P);
											break;



								case 8 :	system("cls");
											break;



								default :
										{
											printf("\n\n\n\n\n\n\n\n\n");
											printf("\n\n\a\a***************choix invalide *************\n\n");
											getch();
											break;
										}
							}
							
						}while(choix1 != 8);
						break;
					}



			case 3 :		
					{
						int choix1;
						do
						{
							
							system("cls");
							printf(	"\n#########*****MENU DE FILLIER*****#########\n"
									"\n\tTOTALE DES FILLIERS SAUVEGARDEE :: %d \n"
									"\n\n1>> ajouter des Filliers : "
									"\n\n2>> afficher les Filliers non sauvegardee :"
									"\n\n3>> sauvegarder et afficher toutes les Filliers :"
									"\n\n4>> modifier les information d'une Filliers :"
									"\n\n5>> Supprimer une Filliers :"
									"\n\n6>> Sauvegarder :"
									"\n\n7>> Retour ....\n",compte_fill());
							printf("\n\nentrer le nombre de votre choix :");
							scanf("%d",&choix1);
							system("cls");
							switch(choix1)
							{
								case 1 :	F=inserte_fill_plus(F);
											break;
								
								
								case 2 :	affiche_new_fill(F);
											break;
											
								
								case 3 :
											if(F!=NULL)
											{
												sauv_list_fill11(F);
												F=init_fill(F);
											}
											read_fill();
											break;
								
								
								case 4 :
										{
											
											if(F!=NULL)
											{
												sauv_list_fill11(F);
												F=init_fill(F);
											}
											char check;
											if(modife_fill() == 0)
											{
												system("cls");
												printf("\n\n\nLa Fillier n'est pas trouvee !!! \n\n\n\n");
												getch();
											}
											else
											{
												printf("Voulez vous sauvegardee les modification [Y|y] ??");
												check=getch();
												if((check == 'y') || (check == 'Y'))
												{
													system("cls");
													int z=remove("./Fillier/Filliers_save.txt"),x=rename("./Fillier/Filliers_save_tmp.txt" , "./Fillier/Filliers_save.txt");
												
													if (z==0 && x==0)
														printf("\n\nmodification bien sauvegardee !!!\n\n");
													getch();
												}
												else
												{
													system("cls");
													printf("\n\n\nModification Non Sauvegardee !!!\n\n");
													getch();
												}
											}
											break;
										}
								
								case 5 :	
										{
											
											if(F!=NULL)
											{
												sauv_list_fill11(F);
												F=init_fill(F);
											}
											char check;
											if(supp_fill() == 0)
											{
												system("cls");
												printf("\n\n\nLa Fillier n'est pas trouvee !!! \n\n\n\n");
												getch();
											}
											else
											{
												printf("Voulez vous sauvegardee les suppression [Y|y] ??");
												check=getch();
												if((check == 'y') || (check == 'Y'))
												{
													system("cls");
													int z=remove("./Fillier/Filliers_save.txt"),x=rename("./Fillier/Filliers_save_tmp.txt" , "./Fillier/Filliers_save.txt");
												
													if (z==0 && x==0);
														printf("\n\nmodification Bien Sauvegardee !!!\n\n");
													getch();
												}
												else
												{
													system("cls");
													printf("\n\n\nModification Non Sauvegardee !!!\n\n");
													getch();
												}
											}
											break;
										}
											
											
								case 6 :	if(F!=NULL)
											{
												sauv_list_fill(F);
												F=init_fill(F);
											}
											break;
											
											
											
								
								case 7 :	
											break;
							
								
								default :
										{
											system("cls");
											printf("\n\n\n\n\n\n\n\n\n");
											printf("\n\n\a\a***************choix invalide *************\n\n");
											getch();
											break;
										}
							}
							
							
							
								
						}while(choix1!=7);
						
						break;
					}


			case 4 :		
					{
						int choix1;
						do
						{
							
							system("cls");
							printf(	"\n#########*****MENU DE MODULE*****#########\n"
									"\n\tTOTALE DES MODULES SAUVEGARDEE :: %d \n"
									"\n\n1>> ajouter des modules : "
									"\n\n2>> afficher les modules non sauvegardee :"
									"\n\n3>> sauvegarder et afficher toutes les modules :"
									"\n\n4>> modifier les information d'un module :"
									"\n\n5>> Supprimer un module :"
									"\n\n6>> Sauvegarder :"
									"\n\n7>> Retour ....\n",compte_mod());
							printf("\n\nentrer le nombre de votre choix :");
							scanf("%d",&choix1);
							system("cls");
							switch(choix1)
							{
								case 1 :	M=inserte_modu_plus(M);
											break;
								
								
								case 2 :	affiche_new_mod(M);
											break;
											
								
								case 3 :
											if(M!=NULL)
											{
												sauv_list_modu(M);
												M=init_mod(M);
											}
											read_modu();
											break;
								
								
								case 4 :
										{
											
											if(M!=NULL)
											{
												sauv_list_modu(M);
												M=init_mod(M);
											}
											char check;
											if(modife_modul() == 0)
											{
												system("cls");
												printf("\n\n\nLe module n'est pas trouvee !!! \n\n\n\n");
												getch();
											}
											else
											{
												printf("Voulez vous sauvegardee les modification [Y|y] ??");
												check=getch();
												if((check == 'y') || (check == 'Y'))
												{
													system("cls");
													int z=remove("./module/Modules_save.txt"),x=rename("./module/Modules_tmp.txt" , "./module/Modules_save.txt");
												
													if (z==0 && x==0)
														printf("\n\nmodification bien sauvegardee !!!\n\n");
													getch();
												}
												else
												{
													system("cls");
													printf("\n\n\nModification Non Sauvegardee !!!\n\n");
													getch();
												}
											}
											break;
										}
								
								case 5 :	
										{
											
											if(M!=NULL)
											{
												sauv_list_modu(M);
												M=init_mod(M);
											}
											char check;
											if(supp_mod() == 0)
											{
												system("cls");
												printf("\n\n\nLe module n'est pas trouvee !!! \n\n\n\n");
												getch();
											}
											else
											{
												printf("Voulez vous sauvegardee les suppression [Y|y] ??");
												check=getch();
												if((check == 'y') || (check == 'Y'))
												{
													system("cls");
													int z=remove("./module/Modules_save.txt"),x=rename("./module/Modules_tmp.txt" , "./module/Modules_save.txt");
												
													if (z==0 && x==0);
														printf("\n\nmodification Bien Sauvegardee !!!\n\n");
													getch();
												}
												else
												{
													system("cls");
													printf("\n\n\nModification Non Sauvegardee !!!\n\n");
													getch();
												}
											}
											break;
										}
											
											
								case 6 :	if(M!=NULL)
											{
												sauv_list_modu(M);
												M=init_mod(M);
											}
											break;
											
											
											
								
								case 7 :	
											break;
							
								
								default :
										{
											system("cls");
											printf("\n\n\n\n\n\n\n\n\n");
											printf("\n\n\a\a***************choix invalide *************\n\n");
											getch();
											break;
										}
							}
						}while(choix1!=7);
						break;
					}		

				
			case 5 :		
					{	int choix1;
							do
							{
								system("cls");
								printf(	"\n#########*****MENU DE NOTE*****#########\n"
										"\n\n1>> sauvegarder et afficher les notes de toutes les etudiants : "
										"\n\n2>> sauvegarder et afficher les notes d'un CNE :"
										"\n\n3>> sauvegarder et afficher les notes d'un Module :"
										"\n\n4>> Entrer les Notes par Module : "
										"\n\n5>> Entrer les Notes par etudiant : "
										"\n\n6>> Sauvegarder :"
										"\n\n7>> afficher les etudiant qui'on Validee :"
										"\n\n8>> Retour ....\n");
								printf("\n\nentrer le nombre de votre choix : ");
								scanf("%d",&choix1);
								system("cls");
								switch(choix1)
								{
									
									case 1 :
											{
												if(N != NULL)
												{
													sauver_liste_note(N);
													N=init_note(N);
												}
												read_note();
												getch();
												break;
											}
									
			
									
									case 2 :	if(N != NULL)
												{
													sauver_liste_note(N);
													N=init_note(N);
												}
												system("cls");
												printf("\n");
												read_note_cne();
												getch();
												break;
									
			
									
									case 3 :	if(N != NULL)
												{
													sauver_liste_note(N);
													N=init_note(N);
												}
												system("cls");
												printf("\n");
												read_note_modu();
												break;
									
			
									
									case 4 :
											{
												system("cls");
												N=inserer_note_plus_mod(N);
												break;
											}
									
									
									case 5 :
											{
												system("cls");
												N=inserer_note_plus_cne(N);
												break;
											}
									
			
									
									case 6 :
											{
												if(N != NULL)
												{
													sauver_liste_note(N);
													N=init_note(N);
												}
												break;
											}
									
			
									
									case 7 :
											{
												system("cls");
												if(N != NULL)
												{
													sauver_liste_note(N);
													N=init_note(N);
												}
												read_note_val();
												
												break;
											}
									
									
									case 8 :	
												system("cls");
												break;
									
																		
									default : 	
											{
												system("cls");
												printf("\n\n\n\n\n\n\n\n\n");
												printf("\n\n\a\a***************choix invalide *************\n\n");
												getch();
												break;
											}
								}
							}while(choix1 != 8);
							break;
					}			
			
			
			case 6 :		
					{
						// Sauvegarde des Etudiants Et Choix de filliers
						if(E != NULL)
						{
							sauve_fill_cne(E);
							sauver_liste(E);
							E=init_etud(E);
						}
						// Sauvegarde des Professeurs
						if (P != NULL)
						{
							sauvegarde_prof11(P);
							P=init_prof(P);
						}
						// Sauvegarde des Filliers
						if(F!=NULL)
						{
							sauv_list_fill(F);
							F=init_fill(F);
						}
						// Sauvegarde des Modules
						if(M!=NULL)
						{
							sauv_list_modu(M);
							M=init_mod(M);
						}
						// Sauvegarde des Notes
						if(N != NULL)
						{
							sauver_liste_note(N);
							N=init_note(N);
						}
					}


			case 7 :	system("cls");
						break;
				
			default :		
					{
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n");
						printf("\n\n\a\a***************choix invalide *************\n\n");
						getch();
						break;
					}
		}
	}while(choix0!=7);
}











main(void)
{
	printf("\n\n\n\n\n BONJOUR, :)");
	getch();
	menu();
	printf("\n\n\n\nGOOD BAY :-) !!");
	getch();
}
