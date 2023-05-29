#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

 void lectureheros(){
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


int main(){
  int go = 0;
  lecturehéros();
  return(1);
}
  
int lecturecombat(int go){
  //Ouvre et lit un fichier puis demande de rentrer un nombre entier.
  FILE *fichier = NULL;
  int CaracterActuel = EOF+1;
  fichier = fopen("combat.txt", "r+");
  if (fichier == NULL) {
    printf("Ouverture du fichier impossible");
    exit(1);
  }
  while ( CaracterActuel != EOF ){
    CaracterActuel = fgetc(fichier);
    printf("%c", CaracterActuel);
  }
  fclose(fichier);
  while (go<=0 && go>3 ){
   scanf("%d", &go);
  }
  return(go);
}
