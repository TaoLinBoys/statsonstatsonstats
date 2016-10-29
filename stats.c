#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>

int main(){
  struct stat buf;
  int error = stat("stats.c", &buf);
  if(error < 0){
    printf("an error has occurred: %s\n", strerror(error));
    return 0;
  }

  printf("file size: %ld bytes\n", buf.st_size);
  
  //i looked at my friends work for this but i have no idea how this works
  printf("permissions: %o\n", buf.st_mode & 0777);

  //gmtime takes in the pointer to time which is st_atime and returns a struct
  //asctime takes the struct and returns the values into human readable stuff
  printf("time of access: %s", asctime(gmtime(&buf.st_atime)));
  return 0;
}
