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

int read1(int go){
  //Ouvre et lit un fichier puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("ferme1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  char phrase[400];
  for (i = 0; i < 3; i++) {
    fgets(phrase, 399, fichier);
    printf("%s \n", phrase);
  }
  fclose(fichier);
  while (go != 2 || go != 3){
    scanf("%d", &go);
  }
  return(go);
}


int list(int go){
  //Permet d'accéder à la liste des fichiers. 
  int take = -1;    
  switch(go){
    case 0 : take = read0(go);
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
