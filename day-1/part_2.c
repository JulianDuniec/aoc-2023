#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 128

int look_back(const char buf[BUF_SIZE], const int i) {
  if (i < 2) {
    return -1;
  }
  if (strncmp(&buf[i - 2], "one", 3) == 0) {
    return 1;
  }
  if (strncmp(&buf[i - 2], "two", 3) == 0) {
    return 2;
  }
  if (strncmp(&buf[i - 2], "six", 3) == 0) {
    return 6;
  }
  if (i < 3) {
    return -1;
  }
  if (strncmp(&buf[i - 3], "four", 4) == 0) {
    return 4;
  }
  if (strncmp(&buf[i - 3], "five", 4) == 0) {
    return 5;
  }
  if (strncmp(&buf[i - 3], "nine", 4) == 0) {
    return 9;
  }
  if (i < 4) {
    return -1;
  }
  if (strncmp(&buf[i - 4], "eight", 5) == 0) {
    return 8;
  }
  if (strncmp(&buf[i - 4], "three", 5) == 0) {
    return 3;
  }
  if (strncmp(&buf[i - 4], "seven", 5) == 0) {
    return 7;
  }
  return -1;
}

int main(int argc, char **arv) {
  char c;
  int sum = 0;
  int f = 0, l = 0, ri = 0;
  char row[BUF_SIZE] = {0};
  while ((c = getc_unlocked(stdin)) != EOF) {
    row[ri] = c;
    int digit = isnumber(c) ? c - '0' : look_back(row, ri);
    ri++;
    if (digit != -1) {
      if (f == 0) {
        f = digit;
      }
      l = digit;
    } else if (c == '\n') {
      sum += (f * 10) + l;
      f = 0;
      l = 0;
      ri = 0;
    }
  }
  printf("%d\n", sum);
}