#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int i, n;
  char buf[0xff];
  if (argc >= 2) {
    while (*++argv != NULL) {
      for (i = 0; i < (int)strlen(*argv); i++)
        printf("\xcc\xb6%c", (*argv)[i]);
      printf(" ");
    }
  }
  fcntl(0, F_SETFL, O_NONBLOCK);
  while ((n = read(0, buf, 0xfd)) > 0)
    for (i = 0; i < n; i++)
      printf("\xcc\xb6%c", buf[i]);
  printf("\n");
  return 0;
}
