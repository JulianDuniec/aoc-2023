#include "../utils.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

enum ParseState {
  Card,
  Winning,
  Hand,
};

#define CARD_COPIES_LEN 193

int main() {
  char winning[100] = {0};
  char c;
  int digit = 0;
  enum ParseState state = Card;
  int card_copies[CARD_COPIES_LEN] = {0};
  int num_matching = 0;
  int card_copies_index = 0;
  while ((c = getc_unlocked(stdin)) != EOF) {
    switch (state) {
    case Card: {
      if (c == ':') {
        state = Winning;
      }
    } break;
    case Winning: {
      if (c == '|') {
        state = Hand;
      } else if (isnumber(c)) {
        digit = (digit * 10) + c - '0';
        if (!next_is_number()) {
          winning[digit] = 1;
          digit = 0;
        }
      }
    } break;
    case Hand: {
      if (isnumber(c)) {
        digit = (digit * 10) + c - '0';
        if (!next_is_number()) {
          if (winning[digit]) {
            num_matching++;
          }
          digit = 0;
        }
      } else {
        if (c == '\n') {
          state = Card;
          for (int i = 0; i < num_matching; i++) {
            for (int j = 0; j < card_copies[card_copies_index] + 1 &&
                            card_copies_index + 1 + i < CARD_COPIES_LEN;
                 j++) {
              card_copies[card_copies_index + 1 + i]++;
            }
          }
          num_matching = 0;
          memset(winning, 0, sizeof(winning));
          card_copies_index++;
        }
      }
    } break;
    }
  }
  int sum = 0;
  for (int i = 0; i <= card_copies_index; i++) {
    sum += 1 + card_copies[i];
  }
  printf("%d\n", sum);
}