#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allfonction.h"

typedef struct {
  char nom[20];
  int pv;
  int luck;
  int agi;
  int aim;
  int str;
  int invent[20]; 
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
    }
    else{
      FILE * file = NULL;
      file = fopen("save","rb+");
      fread(&go,sizeof(int),1,file);
      printf("%d \n",go);
      fclose(file);
    }
  }
  return (go);
} 

int combat(Heros a, Ennemy b){
  int end,answer,choice_w;
  while (a.hp > 0 && b.hp > 0){
    puts("Que voulez vous faire ? \n 1.Attaque au poing \n 2.Prendre une arme \n 3.Utiliser une trousse de soin");
    scanf("%d",&answer);
    if (answer == 1){
      printf("Vous attaquez %s, vous lui infligez %d dégâts ! \n", b.name , a.str );
      b.hp = b.hp - a.str;
    }
    else if (answer == 2){
      if (a.invent[1] > 0 && a.invent[2] > 0){
        printf("1.Revolver (%d balles) \n", a.invent[2]);
      }
      if (a.invent[3] > 0){
        puts("2.Couteau");
      }
      if (a.invent[4] > 0 && a.invent[5] > 0){
        printf("3.Fusil à pompe(%d balles)", a.invent[5]);  
      }
      do{
        scanf("%d", &choice_w);
      }while(choice_w <= 0 || choice_w > 3);
      b.hp = b.hp - use_weapon(a,b,choice_w);
    }
    else if(answer == 3){
      if (a.invent[0] != 1){
        puts("Vous soignez 10 points de vie !");
        a.hp += 10;
      }
      else{
        puts("Vous cherchez une trousse de soin mais vous n'en avez pas, vous passez votre tour !");
      }
    }
    if (b.hp != 0){
      a.hp = a.hp - b.str;
      printf("Vous subissez %d dégâts, il vous en reste %d \n", b.str, a.hp);
    }
  }
  if (a.hp > 0){
    end = 1;
  }
  else{
    end = 0;
  }
  return(end);
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
    case 0 : save(go);
      take = lectureheroes(go);
    break;
    case 1 : save(go);
      take = lectureferme1(go);
    break;
    case 2 : save(go);
      take = lecturecomi1(go);
    break;
    case 3 : save(go);
      take = lecturehopital1(go);
    break;
    case 4 : save(go);
      take = lecturecamp1(go);
    break;
    case 5 : save(go);
      take = lecturefuite(go);
    break;
    case 6 : save(go);
      take = lectureferme2(go);
    break;
    case 7 : save(go);
      take = lectureferme2bis(go);
    break;
    case 8 : save(go);
      take = lecturefermebis2(go);
    break;
    case 9 : save(go);
      take = lectureferme3(go);
    break;
    case 10 : save(go);
      take = lecturecomi2(go);
    break;
    case 11 : save(go);
      take = lecturecomi2bis(go);
    break;
    case 12 : save(go);
      take = lecturecomi2bis2(go);
    break;
    case 13 : save(go);
      take = lecturecomi2bis3(go);
    break;
    case 14 : save(go);
      take = lecturecomi2bis4(go);
    break;
    case 15 : save(go);
      take = lecturecomi3(go);
    break;
    case 16 : save(go);
      take = lecturehopitalgauche(go);
    break;
    case 17 : save(go);
      take = lecturehopitaldroit1(go);
    break;
    case 18 : save(go);
      take = lecturehopitaldroit2(go);
    break;
    case 19 : save(go);
      take = lecturehopitaldroit2bis(go);
    break;
    case 20 : save(go);
      take = lecturehopitaldroit3(go);
    break;
    case 21 : save(go);
      take = lecturehopital3(go);
    break;
    case 22 : save(go);
      take = lecturecamp2(go);
    break;
    case 23 : save(go);
      take = lecturecamp3(go);
    break;
    case 24 : save(go);
      take = lecturemort();
    break;
    case 25 : save(go);
      take = lectureville(go);
    break;
    default : puts("Vous êtes hors des limites ! Mauvaise nouvelles, votre aventure s'arrête ici !");
    }
  return(take);
}

int main(void) {
  int go = MainPage();
  while (go != -1){
    go = list(go);
  }
  return(2);
}
