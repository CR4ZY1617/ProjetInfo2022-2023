#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int pv;
  int dgts;
  char nom[50];
} Ennemi;

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

int list(int go){
  //Permet d'accéder à la liste des fichiers. 
  int take = -1;    
  switch(go){
    case 0 : save(go);
      take = read0(go);
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


int lecturefuite(int go){
  //Ouvre le fichier "fuite" puis demande de rentrer un nombre entier entre 1 et 5.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("fuite.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go!=1 && go!=2 && go!=3 && go!=4 && go!=25 ){
    scanf("%d", &go);
  }
  return(go);
}

int lecturemort(){
  //Ouvre et lit le fichier "mort" puis renvoie -1.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1; 
  fichier = fopen("mort.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  return(-1);
}

int lecturecarte(int go){
  //Ouvre et lit le fichier "carte" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1; 
  fichier = fopen("choix carte.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
   while (go<= 0 || go>5 ){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme1(int go){
  //Ouvre et lit le fichier "ferme choix1"  puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("fermechoix1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 5 || go != 6){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme2(int go){
  //Ouvre et lit un fichier "lecture ferme2" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1; 
  fichier = fopen("ferme choix2.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 7 || go != 8){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme3(int go){
  //Ouvre et lit un fichier "ferme choix 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("ferme choix3.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go!=2 && go!=3 && go!=4 && go!=25){    
    scanf("%d", &go);
  }
  return(go);
}

int lecturecomi1(int go){
  //Ouvre et lit un fichier "comi choix 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("comi choix 1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 10 || go != 5){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecomi2(int go){
  //Ouvre et lit un fichier "comi choix 2" puis demande de rentrer un nombre entier.
  int rep = 0;
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("comi choix 2.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (rep<=0 || rep>5){    
    scanf("%d", &rep);
  }
  if ( rep == 3){
    go = 15;
  }
  elseif ( rep == 5){
    go = 5;
  }
  else{
    go == 11
  }
  return(go);
}

int lecturecomi2bis(int go){
  //Ouvre et lit un fichier "comi choix 2bis" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("comi choix 2bis.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
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
    go == 11
  }
  return(go);
}

int lecturecomi2bis2(int go){
  //Ouvre et lit un fichier "comi choix 2bis2" puis demande de rentrer un nombre entier.
  int rep;
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("comi choix 2bis2.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  scanf("%d", &rep);
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
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("comi choix 2bis3.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
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
    go == 11
  }
  return(go);
}

int lecturecomi2bis4(){
  //Ouvre et lit un fichier "choix comi choix 2bis4" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1; 
  fichier = fopen("comi choix 2bis4.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  return(-1);
}

int lecturecomi3(int go){
  //Ouvre et lit un fichier "comi choix 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("comi choix 3.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go!=1 && go!=3 && go!=4 && go!=25 ){
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp1(int go){
  //Ouvre et lit un fichier "camp choix 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("camp choix 1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 5 || go != 22){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp2(int go){
  //Ouvre et lit un fichier "camp choix 2" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("camp choix 2.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  go = 23;
  return(go);
}

int lecturecamp3(int go){
  //Ouvre et lit le fichier "camp choix 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("camp choix 3.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go!=1 && go!=2 && go!=3 && go!=25 ){    
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopital1(int go){
  //Ouvre et lit le fichier "hopital choix 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("hopital choix 1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 16 || go != 17){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitalgauche(int go){
  //Ouvre et lit le fichier "hopital choix gauche" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("hopital choix gauche.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 5 || go != 17){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit1(int go){
  //Ouvre et lit le fichier "hopital choix droit 1" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("hopital choix droit 1.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go!= 5 && go!=18 && go!=19 ){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2(int go){
  //Ouvre et lit le fichier "hopital choix droit 2" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("hopital choix droit 2.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 19 || go != 20){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2bis(int go){
  //Ouvre et lit le fichier "hopital choix 2 bis" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("hopital choix droit 2 bis.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 1 && go != 2 && go!=4 && go!=25){
    scanf("%d", &go);
  }
  return(0);
}

int lecturehopitaldroit3(int go){
  //Ouvre et lit le fichier "hopital choix droit 3" puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("hopital choix droit 3.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go != 1 && go != 2 && go!=4 && go!=25){
    scanf("%d", &go);
  }
  return(0);
}

int lectureville(){
  //Ouvre et lit le fichier "mort" puis renvoie -1.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("ville.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
 while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  return(-1);

 void lecturehéros(){
  //Ouvre et lit un fichier puis demande de rentrer un nombre entier.
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
  for ( j = 0; j<10; j++){
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
     a.pv = 15;
     a.str = 5;
     a.agi = 6;
     a.aim = 5;
     a.luck = 4;
     a.invent[0] = 1;
     a.invent[1] = 1;
     a.invent[2] = 6;
     a.invent[3] = 1;
  }
   if (perso == 2){
     a.nom[0] = 'C';
     a.nom[1] = 'l';
     a.nom[2] = 'a';
     a.nom[3] = 'i';
     a.nom[4] = 'r';
     a.nom[5] = 'e';  
     a.pv = 10;
     a.str = 3;
     a.agi = 8;
     a.aim = 8;
     a.luck = 5;
     a.invent[0] = 1;
     a.invent[1] = 1;
     a.invent[2] = 6;
     a.invent[3] = 1;
   }
   if (perso == 3){
     a.nom[0] = 'F';
     a.nom[1] = 'r';
     a.nom[2] = 'a';
     a.nom[3] = 'n';
     a.nom[4] = 'c';
     a.nom[5] = 'k';  
     a.pv = 20;
     a.str = 8;
     a.agi = 3;
     a.aim = 2;
     a.luck = 8;
     a.invent[0] = 1;
     a.invent[1] = 1;
     a.invent[2] = 6;
     a.invent[3] = 1;
   }
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
  
