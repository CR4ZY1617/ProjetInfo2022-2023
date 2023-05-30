#include "allfonction.h"

int main(void) {
  int go = MainPage();
  while (go != -1){
    go = list(go);
  }
  return(2);
}
