#include "../utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **arv) {
  const int R = 12, G = 13, B = 14;
  char *line = NULL;
  size_t len = 0;
  int sum = 0;
  while (getline(&line, &len, stdin) != EOF) {
    strtok(line, " ");
    int game_id = atoi(strtok(NULL, ":"));
    int valid = 1;
    for (;;) {
      char *hand = strtok(NULL, ";");
      if (hand == NULL) {
        break;
      }
      char *save_hand;
      char *pair = strtok_r(hand, ",", &save_hand);
      for (;;) {
        char *save_pair;
        int n = atoi(strtok_r(pair, " ", &save_pair));
        char *color = trim(strtok_r(NULL, " ", &save_pair));
        if (strcmp(color, "blue") == 0 && n > B) {
          valid = 0;
        } else if (strcmp(color, "red") == 0 && n > R) {
          valid = 0;
        } else if (strcmp(color, "green") == 0 && n > G) {
          valid = 0;
        }
        pair = strtok_r(NULL, ",", &save_hand);
        if (pair == NULL) {
          break;
        }
      }
    }
    if (valid) {
      sum += game_id;
    }
  }
  printf("%d\n", sum);
}