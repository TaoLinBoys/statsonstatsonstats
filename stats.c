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

  printf("file size: %ldB\n", buf.st_size);
  printf("\t   %lfKB\n", buf.st_size/1000.0);
  printf("\t   %lfMB\n", buf.st_size/1000000.0);
  printf("\t   %lfGB\n", buf.st_size/1000000000.0);
  
  printf("permissions: %o\n", buf.st_mode & 0777);

  printf("permissions in ls -l format:\n");
  
  printf( (S_ISDIR(buf.st_mode)) ? "d" : "-");
  
  printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
  printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
  printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
  
  printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
  printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
  printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
  
  printf( (buf.st_mode & S_IROTH) ? "r" : "-");
  printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
  printf( (buf.st_mode & S_IXOTH) ? "x" : "-");

  printf("\n");

  //gmtime takes in the pointer to time which is st_atime and returns a struct
  //asctime takes the struct and returns the values into human readable stuff
  printf("time of access: %s", asctime(gmtime(&buf.st_atime)));
  return 0;
}
