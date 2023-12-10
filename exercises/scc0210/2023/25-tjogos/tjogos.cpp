#include <bits/stdc++.h>
using namespace std;

int solve() {
  int num_heaps;
  cin >> num_heaps;

  int nim_sum = 0;
  while (num_heaps--) {
    int num_sticks;
    cin >> num_sticks;
    nim_sum ^= num_sticks % 4;
  }

  return nim_sum;
}

int main() {
  int num_games;
  cin >> num_games;
  while (num_games--) {
    if (solve())
      cout << "first" << endl;
    else
      cout << "second" << endl;
  }
  return 0;
}