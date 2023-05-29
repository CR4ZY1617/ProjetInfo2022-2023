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

int use_weapon(Chara a ,Ennemy b, int choice){
  int damage;
  if (choice == 1){
    if (a.invent[1] <= 0 || a.invent[2] <= 0){
      puts("Vous ne pouvez pas tirer avec cette arme !");
    }
    else{
      damage = a.str + 5;
    }
  else if(choice == 2){
    if (a.invent[3] <= 0){
      puts("Vous n'avez pas cette arme !");
    }
    else{
      damage = a.str + 2;
    }
  }
  else{
    if (a.invent[4] <= 0 || a.invent[5] <= 0){
      puts("Vous ne pouvez pas tirer avec cette arme !");
    }
    else{
      damage = a.str + 7;
    }
  }
  return(damage);
}
  
int combat(Chara a, Ennemy b){
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
    case 7 : take = lectureferme2bis(go);
    break;
    case 8 : take = lecturefermebis2(go);
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
    case 20 : take = lecturehopitaldroit3(go);
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
