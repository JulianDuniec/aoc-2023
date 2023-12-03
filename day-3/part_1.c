#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

struct part_number {
  int value;
  int line;
  int start_col, end_col;
};

struct symbol {
  int line;
  int col;
};

int main(int argc, char **arv) {
  char c;
  int line_counter = 0;
  int column_counter = 0;
  int part_numbers_index = 0;
  struct part_number part_numbers[2048] = {0};
  int symbols_index;
  struct symbol symbols[2048] = {0};

  while ((c = getc(stdin)) != EOF) {
    if (c == '\n') {
      line_counter++;
      column_counter = 0;
      continue;
    } else if (isnumber(c)) {
      if (part_numbers[part_numbers_index].value == 0) {
        part_numbers[part_numbers_index].start_col = column_counter;
        part_numbers[part_numbers_index].line = line_counter;
      }
      part_numbers[part_numbers_index].value =
          (part_numbers[part_numbers_index].value * 10) + c - '0';
      char peek = getc_unlocked(stdin);
      if (!isnumber(peek)) {
        part_numbers[part_numbers_index].end_col = column_counter + 1;
        part_numbers_index++;
      }
      ungetc(peek, stdin);
    } else {
      if (c != '.') {
        symbols[symbols_index].col = column_counter;
        symbols[symbols_index].line = line_counter;
        symbols_index++;
      }
    }
    column_counter++;
  }

  int sum = 0;
  for (int i = 0; i < part_numbers_index; i++) {
    struct part_number pn = part_numbers[i];
    int is_neighbor_to_symbol = 0;
    for (int pncol = pn.start_col; pncol < pn.end_col && !is_neighbor_to_symbol;
         pncol++) {
      for (int j = 0; j < symbols_index; j++) {
        struct symbol s = symbols[j];
        if (abs(pn.line - s.line) <= 1 && abs(pncol - s.col) <= 1) {
          is_neighbor_to_symbol = 1;
        }
      }
    }
    if (is_neighbor_to_symbol) {
      sum += pn.value;
    }
  }
  printf("%d\n", sum);
}