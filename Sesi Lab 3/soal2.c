/*
  Buatlah sebuah program untuk menampilkan file pada urutan ketiga dari sebuah direktori, dengan menggunakan pipe dan command ls, head, tail.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define FILE_NAME_SIZE 64

int main() {
  DIR *dp;
  struct dirent *ep;
  
  char path[100];
  printf("Enter directory path: ");
  scanf("%s", path);

  dp = opendir(path);

  if (dp == NULL) {
    // Fail to open directory
    exit(EXIT_FAILURE);
  }

  int p[2];
  if (pipe(p) < 0) {
    // Fail to make pipe
    exit(EXIT_FAILURE);
  }

  unsigned int total_item = 0;

  while (ep = readdir(dp)) {
    // Skip . and ..
    if (strcmp(ep->d_name, ".") == 0 || strcmp(ep->d_name, "..") == 0) continue;
    write(p[1], ep->d_name, FILE_NAME_SIZE);
    total_item++;
  }

  // Close directory
  closedir(dp);

  // Get 3rd file name
  char buff[FILE_NAME_SIZE];
  bool isFinished = false;
  unsigned int index = 1;
  while (!isFinished) {
    read(p[0], buff, FILE_NAME_SIZE);
    printf("%d. %s\n", index, buff);
    if (index++ == 3) {
      isFinished = true;
    }
  }
  // Print 3rd file name
  printf("%s\n", buff);
  // By using ls, head, and tail, print 3rd file name
  system("ls | head -n 3 | tail -n 1");
  return 0;
}
