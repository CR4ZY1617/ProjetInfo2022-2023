#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lecturefuite(int go){
  //Ouvre le fichier "fuite" puis demande de rentrer un nombre entier entre 1 et 5.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("fuite.txt", "r+");
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
  while (go!=1 && go!=2 && go!=3 && go!=4 && go!=25 ){
    scanf("%d", &go);
  }
  return(go);
}

int lecturemort(){
  //Ouvre et lit le fichier "mort" puis renvoie -1.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("mort.txt", "r+");
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
  return(-1);
}

int lecturecarte(int go){
  //Ouvre et lit le fichier "carte" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("choix carte.txt", "r+");
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
   while (go<= 0 && go>5 ){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme1(int go){
  //Ouvre et lit le fichier "ferme choix1"  puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("fermechoix1.txt", "r+");
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
  while (go != 5 || go != 6){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme2(int go){
  //Ouvre et lit un fichier "lecture ferme2" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("ferme choix2.txt", "r+");
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
  while (go != 7 || go != 8){
    scanf("%d", &go);
  }
  return(go);
}

int lectureferme3(int go){
  //Ouvre et lit un fichier "ferme choix 3" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("ferme choix3.txt", "r+");
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
  while (go!=2 && go!=3 && go!=4 && go!=25){    
    scanf("%d", &go);
  }
  return(go);
}

int lecturecomi1(int go){
  //Ouvre et lit un fichier "comi choix 1" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 1.txt", "r+");
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
  while (go != 10 || go != 5){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecomi2(int go){
  //Ouvre et lit un fichier "comi choix 2" puis demande de rentrer un nombre entier.
  int i;
  int rep = 0;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 2.txt", "r+");
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
  int i;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 2bis.txt", "r+");
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
  int i;
  int rep;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 2bis2.txt", "r+");
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
  int i;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 2bis3.txt", "r+");
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
  int i;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 2bis4.txt", "r+");
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
  return(-1);
}

int lecturecomi3(int go){
  //Ouvre et lit un fichier "comi choix 3" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("comi choix 3.txt", "r+");
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
  while (go!=1 && go!=3 && go!=4 && go!=25 ){
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp1(int go){
  //Ouvre et lit un fichier "camp choix 1" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("camp choix 1.txt", "r+");
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
  while (go != 5 || go != 22){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp2(int go){
  //Ouvre et lit un fichier "camp choix 2" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("camp choix 2.txt", "r+");
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
  go = 23;
  return(go);
}

int lecturecamp3(int go){
  //Ouvre et lit le fichier "camp choix 3" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("camp choix 3.txt", "r+");
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
  while (go!=1 && go!=2 && go!=3 && go!=25 ){    
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopital1(int go){
  //Ouvre et lit le fichier "hopital choix 1" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("hopital choix 1.txt", "r+");
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
  while (go != 16 || go != 17){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitalgauche(int go){
  //Ouvre et lit le fichier "hopital choix gauche" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("hopital choix gauche.txt", "r+");
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
  while (go != 5 || go != 17){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit1(int go){
  //Ouvre et lit le fichier "hopital choix droit 1" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("hopital choix droit 1.txt", "r+");
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
  while (go!= 5 && go!=18 && go!=19 ){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2(int go){
  //Ouvre et lit le fichier "hopital choix droit 2" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("hopital choix droit 2.txt", "r+");
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
  while (go != 19 || go != 20){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2bis(int go){
  //Ouvre et lit le fichier "hopital choix 2 bis" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("hopital choix droit 2 bis.txt", "r+");
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
  while (go != 1 && go != 2 && go!=4 && go!=25){
    scanf("%d", &go);
  }
  return(0);
}

int lecturehopitaldroit3(int go){
  //Ouvre et lit le fichier "hopital choix droit 3" puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("hopital choix droit 3.txt", "r+");
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
  while (go != 1 && go != 2 && go!=4 && go!=25){
    scanf("%d", &go);
  }
  return(0);
}


int lectureville(){
  //Ouvre et lit le fichier "mort" puis renvoie -1.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("ville.txt", "r+");
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
  return(-1);




int lecturecombat(int go){
  //Ouvre et lit un fichier puis demande de rentrer un nombre entier.
  int i;
  FILE *fichier = NULL;
  fichier = fopen("combat.txt", "r+");
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
  while (go<=0 && go>3 ){
   scanf("%d", &go);
  }
  return(go);
}
