#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){

  struct stat fileStat;
  stat("test", &fileStat);

  printf("File Permissions: \t");
      printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
      printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
      printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
      printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
      printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
      printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
      printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
      printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
      printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
      printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
      printf("\n\n");

}
