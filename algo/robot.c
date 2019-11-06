#include <stdio.h>

int parcoursGrille(int grille[100][100], int col, int line, int n);

int main(int argc, char const *argv[]) {

	int n;
	scanf("%d", &n);
	int arrGrid[100][100];
	char temp;
  //grille
	int nPosI;
	int nPosJ;
	for (nPosI = 0; nPosI < n; nPosI++) {
	   for (nPosJ = 0; nPosJ < n; nPosJ++) {
			scanf("%d", &arrGrid[nPosI][nPosJ]);
		}
  }
  int nbSortie = 0;
  nbSortie = parcoursGrille(arrGrid, 0, 0, n);
  printf("%d\r\n", nbSortie);
  return 0;
}


int parcoursGrille(int grille[100][100], int col, int line, int n){
  //printf("Lancement avec col = %d et ligne = %d\n", col, line);
  if(line == (n - 1)  && col == (n - 1)){
    return 1;
  }
  else if(grille[line][col] == -1){
    return 0;
  }
  else if(line == (n-1)){
    return parcoursGrille(grille, col + 1, line, n);
  }
  else if(col == (n-1)){
    return parcoursGrille(grille, col, line + 1, n);
  }
  else{
    return parcoursGrille(grille, col, line + 1, n) + parcoursGrille(grille, col + 1, line, n);
  }
}
