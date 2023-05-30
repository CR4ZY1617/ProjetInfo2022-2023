#include "allfonction.h"

void write_Heros(Heros a){
  int val;
  FILE * fichier = NULL;
  fichier = fopen("Heros", "wb+");
  fwrite(&a, sizeof(Heros), 1, fichier);
  fclose(fichier);
}

Heros Initialise(){
  //Lis le nom et les stats du héro dans son fichier.
  Heros a;
  FILE * fichier = NULL;
  fichier = fopen("Heros", "rb+");
  fread (&a,sizeof(Heros),1,fichier);
  return(a);
}

void save(int go){
  FILE * file = NULL;
  file = fopen("save","wb+");
  scanf("%d",&go);
  fwrite(&go,sizeof(int),1,file);
  fclose(file);
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

Ennemi ratb(){
  //Lis le nom et les stats du rat dans son fichier.
  Ennemi A;
  FILE *test = NULL;
  test = fopen("rat bléssé.txt", "r+");
  if (test == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  fscanf(test, "%s", A.nom );
  fscanf(test, "%d", &A.pv );
  fscanf(test, "%d", &A.dgts );
  fclose(test);
  return(A);
}

Ennemi rat(){
  //Lis le nom et les stats du rat mutant dans son fichier.
  Ennemi A; 
  FILE *test = NULL;
  test = fopen("rat.txt", "r+");
  if (test == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  fscanf(test, "%s", A.nom );
  fscanf(test, "%d", &A.pv );
  fscanf(test, "%d", &A.dgts );
  fclose(test);
  return(A);
}

Ennemi bandit(){
  //Lis le nom et les stats du rat mutant dans son fichier.
  Ennemi A; 
  FILE *test = NULL;
  test = fopen("bandit.txt", "r+");
  if (test == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  fscanf(test, "%s", A.nom );
  fscanf(test, "%d", &A.pv );
  fscanf(test, "%d", &A.dgts );
  fclose(test);
  return(A);
}

Ennemi goule(){
  //Lis le nom et les stats du rat mutant dans son fichier.
  Ennemi A; 
  FILE *test = NULL;
  test = fopen("goule.txt", "r+");
  if (test == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  fscanf(test, "%s", A.nom );
  fscanf(test, "%d", &A.pv );
  fscanf(test, "%d", &A.dgts );
  fclose(test);
  return(A);
}

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
