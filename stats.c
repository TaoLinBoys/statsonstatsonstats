#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
  struct stat buf;
  stat("stats.c", &buf);

  printf("file size: %d\n", buf.st_size);
  printf("file permissions: %o\n", buf.st_mode);
  printf("file date of access: %d\n", buf.st_atime);
  return 0;
}
