#include "../utils.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

enum ParseState {
  Card,
  Winning,
  Hand,
};

int main() {
  char winning[100] = {0};
  char c;
  int digit = 0;
  enum ParseState state = Card;
  int sum = 0;
  int hand_sum = 0;
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
            if (hand_sum == 0) {
              hand_sum = 1;
            } else {
              hand_sum *= 2;
            }
          }
          digit = 0;
        }
      } else {
        if (c == '\n') {
          state = Card;
          sum += hand_sum;
          hand_sum = 0;
          memset(winning, 0, sizeof(winning));
        }
      }
    } break;
    }
  }
  printf("%d\n", sum);
}