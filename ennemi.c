#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
  int pv;
  int dgts;
  char nom[50];
} Ennemi;

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
