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
  while (go<=0 && go>5 ){
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
  while (go != 1 || go != 2){
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
  while (go != 1 || go != 2){
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
  while (go<=0 && go>4 ){    
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
  while (go != 1 || go != 2){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecomi2(int go){
  //Ouvre et lit un fichier "comi choix 2" puis demande de rentrer un nombre entier.
  int i;
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
  while (go<=0 && go>5 ){    
    scanf("%d", &go);
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
  while (go<=0 && go>5 ){    
    scanf("%d", &go);
  }
  return(go);
}

int lecturecomi2bis2(int go){
  //Ouvre et lit un fichier "comi choix 2bis2" puis demande de rentrer un nombre entier.
  int i;
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
while (go != 1 || go != 2){
  scanf("%d", &go);
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
  while (go<=0 && go>5 ){   
    scanf("%d", &go);
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
  while (go<=0 && go>4 ){
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
  while (go != 1 || go != 2){   
   scanf("%d", &go);
  }
  return(go);
}

int lecturecamp2(){
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
  return(0);
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
  while (go<=0 && go>4 ){    
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
  while (go != 1 || go != 2){
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
  while (go != 1 || go != 2){
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
  while (go < 1 && go > 3){
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
  while (go != 1 || go != 2){
    scanf("%d", &go);
  }
  return(go);
}

int lecturehopitaldroit2bis(){
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
  return(0);
}

int lecturehopitaldroit3(){
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
  return(0);
}

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
