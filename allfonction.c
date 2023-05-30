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
