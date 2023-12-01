#include <ctype.h>
#include <stdio.h>

int main(int argc, char **arv) {
  char c;
  int sum = 0;
  int f = 0, l = 0;
  while ((c = getc_unlocked(stdin)) != EOF) {
    if (isnumber(c)) {
      if (f == 0) {
        f = c - '0';
      }
      l = c - '0';
    } else if (c == '\n') {
      sum += (f * 10) + l;
      f = 0;
      l = 0;
    }
  }
  printf("%d\n", sum);
}