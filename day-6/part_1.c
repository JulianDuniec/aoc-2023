#include <stdio.h>

int main() {
  int records[4] = {0};
  int distances[4] = {0};
  scanf("Time: %d %d %d %d\n", &records[0], &records[1], &records[2],
        &records[3]);
  scanf("Distance: %d %d %d %d", &distances[0], &distances[1], &distances[2],
        &distances[3]);
  int sum = 0;
  for (int i = 0; i < 4; i++) {
    int r = records[i], d = distances[i];
    if (r == 0) {
      break;
    }
    int combos = 0;
    for (int j = 1; j < r; j++) {
      int rem = r - j;
      int dt = rem * j;
      if (dt > d) {
        ++combos;
      }
    }
    if (sum == 0) {
      sum = combos;
    } else {
      sum *= combos;
    }
  }
  printf("%d\n", sum);
}