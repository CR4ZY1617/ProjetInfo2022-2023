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

int MainPage();
int use_weapon(Chara a ,Ennemy b, int choice);
int combat(Chara a, Ennemy b);
int list(int go);
void write_Heros(Heros a);
Heros Initialise();
int lecturefuite(int go);
int lecturemort();
int lecturecarte(int go);
int lectureferme1(int go);
int lectureferme2(int go);
int lectureferme3(int go);
int lecturecomi1(int go);
int lecturecomi2(int go);
int lecturecomi2bis(int go);
int lecturecomi2bis2(int go);
int lecturecomi2bis3(int go);
int lecturecomi2bis4();
int lecturecomi3(int go);
int lecturecamp1(int go);
int lecturecamp2(int go);
int lecturecamp3(int go);
int lecturehopital1(int go);
int lecturehopitalgauche(int go);
int lecturehopitaldroit1(int go);
int lecturehopitaldroit2(int go);
int lecturehopitaldroit2bis(int go);
int lecturehopitaldroit3(int go);
int lectureville();
void lecturehéros();
Ennemi ratb();
Ennemi rat();
Ennemi bandit();
Ennemi goule();

#endIf
