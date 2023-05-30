#include "allfonction.h"

int list(int go){
  //Permet d'accéder à la liste des fichiers. 
  int take = -1;    
  switch(go){
    case 0 : save(go);
      take = lectureheros(go);
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
      take = lectureferme2bis2(go);
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

int main(void) {
  int go = MainPage();
  while (go != -1){
    go = list(go);
  }
  return(2);
}
