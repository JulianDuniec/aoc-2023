#include <ctype.h>
#include <stdio.h>
#include <string.h>

int next_is_number() {
  char peek = getc_unlocked(stdin);
  ungetc(peek, stdin);
  return isnumber(peek);
}

char *ltrim(char *s) {
  while (isspace(*s)) {
    s++;
  }
  return s;
}

char *rtrim(char *s) {
  char *back = s + strlen(s);
  while (isspace(*--back)) {
  }
  *(back + 1) = '\0';
  return s;
}

char *trim(char *s) { return rtrim(ltrim(s)); }
