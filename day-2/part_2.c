#include "../utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **arv) {
  char *line = NULL;
  size_t len = 0;
  int sum = 0;
  while (getline(&line, &len, stdin) != EOF) {
    strtok(line, " ");
    int game_id = atoi(strtok(NULL, ":"));
    int max_r = 0, max_g = 0, max_b = 0;
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
        if (strcmp(color, "blue") == 0) {
          max_b = max_b > n ? max_b : n;
        } else if (strcmp(color, "red") == 0) {
          max_r = max_r > n ? max_r : n;
        } else if (strcmp(color, "green") == 0) {
          max_g = max_g > n ? max_g : n;
        }
        pair = strtok_r(NULL, ",", &save_hand);
        if (pair == NULL) {
          break;
        }
      }
    }
    sum += max_r * max_b * max_g;
  }
  printf("%d\n", sum);
}