#include <stdio.h>

int main(int argc, char const *argv[]) {
  int average;

  int grades[3];

  grades[0]=90;
  grades[2]=80;

  average = (grades[0] + grades[1] + grades[2])/3;
  printf("The average of the 3 grades is: %d  %d", average, grades[1]);
  return 0;
}
