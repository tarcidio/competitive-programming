#include <bits/stdc++.h>

using namespace std;

int main() {

  int bac, spi;
  cin >> bac >> spi;
  int cont = 1;
  while (bac || spi) {
    vector<int> bacAge;
    for (int i = 0; i < bac; i++) {
      int input;
      cin >> input;
      bacAge.push_back(input);
    }
    sort(bacAge.begin(), bacAge.end());

    for (int i = 0; i < spi; i++) {
      int input;
      cin >> input;
    }

    if (bac <= spi)
      cout << "Case " << cont << ": 0" << endl;
    else {
      cout << "Case " << cont << ": " << bac - spi << " " << bacAge[0] << endl;
    }
    cont++;
    cin >> bac >> spi;
  }
  return 0;
}