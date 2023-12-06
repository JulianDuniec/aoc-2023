#include <ctype.h>
#include <stdio.h>

int main() {
  long r = 0, d = 0;
  char c;
  long *ptr = &r;
  while ((c = getc(stdin)) != EOF) {
    if (c == '\n') {
      ptr = &d;
    }
    if (isnumber(c)) {
      *ptr = (*ptr * 10) + c - '0';
    }
  }
  long combos = 0;
  for (int j = 1; j < r; j++) {
    long rem = r - j;
    long dt = rem * j;
    if (dt >= d) {
      ++combos;
    }
  }
  printf("%ld\n", combos);
}