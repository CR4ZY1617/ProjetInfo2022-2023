#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nom[20];
  int str;
  int agi;
  int aim;
  int luck;
} Heros;

int MainPage(){
  int go, choice = 0;
  FILE *fichier = NULL;
  int caraActuel = EOF+1;
  fichier = fopen("MainPage.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (caraActuel != EOF){
    caraActuel = fgetc(fichier);
    printf("%c",caraActuel);
  }
  fclose(fichier);
  while (choice != 1 && choice != 2){
    scanf("%d",&choice);
    if (choice != 1 && choice != 2){
      puts("Ce numéro n'est pas valide,veuillez réessayer !");
    }
    else if (choice == 1){
      go = 0;
      //Ecrire dans le fichier save O pour remettre à 0 la sauvegarde.
      // Ou le faire dans le fichier prologue.
    }
    else{
      FILE *made = NULL;
      made = fopen("save.txt", "r+");
      if (fichier == NULL) {
      printf("Ouverture du fichier impossible");
      exit(1);
      }
      fscanf(made, "%d", &go);
      fclose(made);
    }
  }
  return (go);
} 


int read0(int go){
  //Ouvre et lit un fichier puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("Start.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  char phrase[400];
  for (i = 0; i < 17; i++) {
    fgets(phrase, 399, fichier);
    printf("%s \n", phrase);
  }
  fclose(fichier);
  while (go != )
  scanf("%d", &go);
  return(go);
}

int list(int go){
  //Permet d'accéder à la liste des fichiers. 
  int take = -1;    
  switch(go){
    case 0 : take = read0(go);
    break;
    case 1 : take = lectureferme1(go);
    break;
    case 2 : take = lecturecomi1(go);
    break;
    case 3 : take = lecturehopital1(go);
    break;
    case 4 : take = lecturecamp1(go);
    break;
    case 5 : take = lecturefuite(go);
    break;
    case 6 : take = lectureferme2(go);
    break;
    case 7 : take = lecturerat(go);
    break;
    case 8 : take = lectureratblessé(go);
    break;
    case 9 : take = lectureferme3(go);
    break;
    case 10 : take = lecturecomi2(go);
    break;
    case 11 : take = lecturecomi2bis(go);
    break;
    case 12 : take = lecturecomi2bis2(go);
    break;
    case 13 : take = lecturecomi2bis3(go);
    break;
    case 14 : take = lecturecomi2bis4(go);
    break;
    case 15 : take = lecturecomi3(go);
    break;
    case 16 : take = lecturehopitalgauche(go);
    break;
    case 17 : take = lecturehopitaldroit1(go);
    break;
    case 18 : take = lecturehopitaldroit2(go);
    break;
    case 19 : take = lecturehopitaldroit2bis(go);
    break;
    case 20 : take = lecturehopitaldroit3bis(go);
    break;
    case 21 : take = lecturehopital3(go);
    break;
    case 22 : take = lecturecamp2(go);
    break;
    case 23 : take = lecturecamp3(go);
    break;
    case 24 : take = lecturemort();
    break;
    case 25 : take = lectureville(go);
    break;
    default : puts("Vous êtes hors des limites ! Mauvaise nouvelles, votre aventure s'arrête ici !");
    }
  return(take);
}


Heros Initialise(){
  //Lis le nom et les stats du héro dans son fichier.
  Heros A;
  int i;
  FILE *test = NULL;
  test = fopen("Hero.txt", "r+");
  if (test == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  fscanf(test, "%s", A.nom);
  fscanf(test, "%d", &A.str);
  fscanf(test, "%d", &A.agi);
  fscanf(test, "%d", &A.aim);
  fscanf(test, "%d", &A.luck);
  fclose(test);
  return(A);
}


int main(void) {
  int go = MainPage();
  while (go != -1){
    go = list(go);
  }
  return(2);
}
