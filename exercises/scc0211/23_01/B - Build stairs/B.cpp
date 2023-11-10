#include <bits/stdc++.h>

using namespace std;

int main() {
  int num_square;
  cin >> num_square;

  int height, last_height;
  cin >> height;
  last_height = height - 1;
  num_square--;

  bool flag = true;
  // vector<int> squares;
  while (num_square-- && flag) {
    int height;
    cin >> height;
    if (height - 1 >= last_height) {
      last_height = height - 1;
    } else if (height >= last_height) {
      last_height = height;
    } else {
      flag = false;
    }
  }

  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}