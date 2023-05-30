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

int use_weapon(Heros a ,Ennemi b, int choice){
  int damage;
  if (choice == 1){
    if (a.invent[1] <= 0 || a.invent[2] <= 0){
      puts("Vous ne pouvez pas tirer avec cette arme !");
    }
    else{
      damage = a.str + 5;
    }
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
  fscanf(test, "%s", A.name );
  fscanf(test, "%d", &A.hp );
  fscanf(test, "%d", &A.str );
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
  fscanf(test, "%s", A.name );
  fscanf(test, "%d", &A.hp );
  fscanf(test, "%d", &A.str );
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
  fscanf(test, "%s", A.name );
  fscanf(test, "%d", &A.hp );
  fscanf(test, "%d", &A.str );
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
  fscanf(test, "%s", A.name );
  fscanf(test, "%d", &A.hp );
  fscanf(test, "%d", &A.str );
  fclose(test);
  return(A);
}

int MainPage(){
  int go, choice;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("MainPage.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  scanf("%d", &choice);
  while (choice != 1 && choice != 2){
    scanf("%d",&choice);
  } 
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
    fclose(file);
  }
  return (go);
} 

int combat(Heros a, Ennemi b){
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
  
int lecturefuite(int go){
  //Ouvre le fichier "fuite" puis demande de rentrer un nombre entier entre 1 et 5.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("fuite.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go!=1 && go!=2 && go!=3 && go!=4 && go!=25 ){
    scanf("%d", &go);
  }
  return(go);
}

int lecturemort(){
  //Ouvre et lit le fichier "mort" puis renvoie -1.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("mort.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  return(-1);
}

int lecturecarte(int go){
  //Ouvre et lit le fichier "carte" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("choix carte.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
   while (go != 1 && go != 2 && go != 3 && go != 4 && go!= 25){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme1(int go){
  //Ouvre et lit le fichier "ferme choix1"  puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("ferme choix1.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 5 && go != 6){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme2(int go){
  //Ouvre et lit un fichier "lecture ferme2" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("ferme choix2.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 7 && go != 8){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme2bis(int go){
  //Ouvre et lit un fichier "lecture ferme2" puis lance la fonction combat qui renvoie 24 si on perd et 9 si on gagne.
  int res;
  Heros a;
  Ennemi b;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("ferme choix 2bis.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  b = rat();
  a = Initialise();
  res = combat(a,b);
  if (res == 0){
    go = 24;
  }
  else if (res == 1){
    go = 9;
  }
  else {
    printf("Une erreur est arrivée");
    exit(50);
  }
  return(go);
}

int lectureferme2bis2(int go){
  //Ouvre et lit un fichier "lecture ferme2bis2" puis lance la fonction combat qui renvoie 24 si on perd et 9 si on gagne.
  int res;
  Heros a;
  Ennemi b;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("ferme choix 2bis2.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  b = ratb();
  a = Initialise();
  res = combat(a,b);
  if (res == 0){
    go = 24;
  }
  else if (res == 1){
    go = 9;
  }
  else {
    printf("Une erreur est arrivée");
    exit(50);
  }
  return(go);
}

int lectureferme3(int go){
  //Ouvre et lit un fichier "ferme choix 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("ferme choix3.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go!=2 && go!=3 && go!=4 && go!=25){    
    scanf("%d", &go);
  }
  return(go);
}

int lecturecomi1(int go){
  //Ouvre et lit un fichier "comi choix 1" puis demande de rentrer un nombre entier.
  Heros a;
  Ennemi b;
  int res;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 1.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 10 && go != 5){   
   scanf("%d", &go);
  }
  if (go == 10){
    a = Initialise();
    b = goule();
    res = combat(a,b);
    if (res == 0){
      go = 24;
    }
  }
  return(go);
}

int lecturecomi2(int go){
  //Ouvre et lit un fichier "comi choix 2" puis demande de rentrer un nombre entier.
  int rep = 0;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 2.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (rep<=0 || rep>5){    
    scanf("%d", &rep);
  }
  if ( rep == 3){
    go = 15;
  }
  else if ( rep == 5){
    go = 5;
  }
  else{
    go == 11;
  }
  return(go);
}

int lecturecomi2bis(int go){
  //Ouvre et lit un fichier "comi choix 2bis" puis demande de rentrer un nombre entier.
  int rep = 0;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 2bis.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (rep<=0 || rep>5){    
    scanf("%d", &rep);
  }
  if ( rep == 3){
    go = 15;
  }
  else if ( rep == 5){
    go = 5;
  }
  else{
    go == 11;
  }
  return(go);
}

int lecturecomi2bis2(int go){
  //Ouvre et lit un fichier "comi choix 2bis2" puis demande de rentrer un nombre entier.
  int rep = 0;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 2bis2.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (rep <= 0 || rep > 5){
    scanf("%d", &rep);
  }
  if ( rep == 2){
    go = 5;
  }
  else{
    printf(" Vous allez vous battre \n" );
  }
  return(go);
}

int lecturecomi2bis3(int go){
  //Ouvre et lit un fichier "comi choix 2bis3 " puis demande de rentrer un nombre entier.
  int rep = 0;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 2bis3.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
   while (rep<=0 || rep>5){    
    scanf("%d", &rep);
  }
  if ( rep == 3){
    go = 15;
  }
  else if ( rep == 5){
    go = 5;
  }
  else{
    go == 11;
  }
  return(go);
}

int lecturecomi2bis4(){
  //Ouvre et lit un fichier "choix comi choix 2bis4" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 2bis4.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  return(-1);
}

int lecturecomi3(int go){
  //Ouvre et lit un fichier "comi choix 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("comi choix 3.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go!=1 && go!=3 && go!=4 && go!=25 ){
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp1(int go){
  //Ouvre et lit un fichier "camp choix 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("camp choix 1.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 5 && go != 22){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp2(int go){
  //Ouvre et lit un fichier "camp choix 2" puis demande de rentrer un nombre entier.
  Heros a;
  Ennemi b;
  int res,i = 3;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("camp choix 2.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  a = Initialise();
  do{
    b = bandit();
    res = combat(a,b);
    i --;
  } while (i != 3 && res != 0);
  if (res == 1){
    go = 23;
  }
  else if(res == 0){
    go = 24;
  }
  else{
    exit(12);
  }
  return(go);
}

int lecturecamp3(int go){
  //Ouvre et lit le fichier "camp choix 3" puis demande de rentrer un nombre entier.
  Heros a;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("camp choix 3.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go!=1 && go!=2 && go!=3 && go!=25 ){    
    scanf("%d", &go);
  }
  a = Initialise();
  a.invent[0] += 1;
  a.invent[2] += 10;
  a.invent[5] += 3;
  write_Heros(a);
  return(go);
}

int lecturehopital1(int go){
  //Ouvre et lit le fichier "hopital choix 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix 1.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 16 && go != 17){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitalgauche(int go){
  //Ouvre et lit le fichier "hopital choix gauche" puis demande de rentrer un nombre entier.
  Heros a;
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix gauche.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 5 && go != 17){
    scanf("%d", &go);
  }
  a = Initialise();
  a.invent[0] += 1;
  write_Heros(a);
  return(go);
}

int lecturehopitaldroit1(int go){
  //Ouvre et lit le fichier "hopital choix droit 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix droit 1.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go!= 5 && go!=18 && go!=19 ){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2(int go){
  //Ouvre et lit le fichier "hopital choix droit 2" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix droit 2.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 19 && go != 20){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2bis(int go){
  //Ouvre et lit le fichier "hopital choix 2 bis" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix droit 2 bis.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 1 && go != 2 && go!=4 && go!=25){
    scanf("%d", &go);
  }
  return(0);
}

int lecturehopitaldroit3(int go){
  //Ouvre et lit le fichier "hopital choix droit 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix droit 3.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  while (go != 1 && go != 2 && go!=4 && go!=25){
    scanf("%d", &go);
  }
  return(0);
}

int lecturehopital3(int go){
  //Ouvre et lit le fichier "carte" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("hopital choix 3.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
   while (go != 1 && go != 2 && go != 4 && go != 25){
    scanf("%d", &go);
  }
  return(go);
}


int lectureville(){
  //Ouvre et lit le fichier "ville" puis renvoie -1.
  FILE *fichier = NULL;
  char chaine[SPACE] = "";
  fichier = fopen("ville.txt", "r");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while (fgets(chaine,SPACE,fichier)!= NULL){
    printf("%s",chaine);
  }
  fclose(fichier);
  printf(" \n");
  return(-1);
}

 int lectureheros(int go){
  //Ouvre et lit le fichier "Créa perso.txt" puis demande de rentrer un nombre entier.
  int i,j;
  int perso = 0;
  Heros a;
  FILE *fichier = NULL;
  fichier = fopen("Créa perso.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  char phrase[400];
  for (i = 0; i < 17; i++) {
    fgets(phrase, 399, fichier);
    printf("%s \n", phrase);
  }
  while (perso<=0 || perso>3 ){
  scanf("%d", &perso);
  }
  char phrase2[400];
  for ( j = 0; j<7; j++){
    fgets(phrase2, 399, fichier);
    printf("%s \n", phrase2);
  }
   fclose(fichier);
   if (perso == 1){
     a.nom[0] = 'J';
     a.nom[1] = 'a';
     a.nom[2] = 'c';
     a.nom[3] = 'o';
     a.nom[4] = 'b';
     a.hp = 15;
     a.str = 5;
     a.agi = 6;
     a.aim = 5;
     a.luck = 4;
     a.invent[0] = 1;
     a.invent[1] = 1;
     a.invent[2] = 6;
     a.invent[3] = 1;
     a.invent[4] = 0;
     a.invent[5] = 0;
  }
   if (perso == 2){
     a.nom[0] = 'C';
     a.nom[1] = 'l';
     a.nom[2] = 'a';
     a.nom[3] = 'i';
     a.nom[4] = 'r';
     a.nom[5] = 'e';  
     a.hp = 10;
     a.str = 3;
     a.agi = 8;
     a.aim = 8;
     a.luck = 5;
     a.invent[0] = 1;
     a.invent[1] = 1;
     a.invent[2] = 6;
     a.invent[3] = 1;
     a.invent[4] = 0;
     a.invent[5] = 0;
   }
   if (perso == 3){
     a.nom[0] = 'F';
     a.nom[1] = 'r';
     a.nom[2] = 'a';
     a.nom[3] = 'n';
     a.nom[4] = 'c';
     a.nom[5] = 'k';  
     a.hp = 20;
     a.str = 8;
     a.agi = 3;
     a.aim = 2;
     a.luck = 8;
     a.invent[0] = 1;
     a.invent[1] = 1;
     a.invent[2] = 6;
     a.invent[3] = 1;
     a.invent[4] = 0;
     a.invent[5] = 0;
   }
   write_Heros(a);
  go = lecturecarte(go);
  return (go);
}