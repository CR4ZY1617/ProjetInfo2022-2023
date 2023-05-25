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


int read0(){
  //Ouvre et lit un fichier puis demande de rentrer un nombre entier.
  int go,i;
  FILE *fichier = NULL;
  fichier = fopen("1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  char phrase[200];
  for (i = 0; i < 3; i++) {
    fgets(phrase, 199, fichier);
    printf("%s \n", phrase);
  }
  fclose(fichier);
  scanf("%d", &go);
  return(go);
}


int list(int go){
  //Permet d'accéder à la liste des fichiers. 
  int take = -1;    
  switch(go){
    case 0 : take = read0();
    break;
    case 1 : take = read1();
    break;
    case 2 : take = read2();
    break;
    case 3 : take = read3();
    break;
    case 4 : take = read4();
    break;
    case 5 : take = read5();
    break;
    case 6 : take = read6();
    break;
    case 7 : take = read7();
    break;
    case 8 : take = read8();
    break;
    case 9 : take = read9();
    break;
    case 10 : take = read10();
    break;
    case 11 : take = read11();
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
