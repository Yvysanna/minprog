#include <stdio.h>

int main(void){
  for(int year = 1799; year < 2020; year++){
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){
      printf("%i\n", year);
    }
  }
}
