#include <bits/stdc++.h>

using namespace std;

vector<int> weights;
// num obj vs peso total
bool canSplitEqually(int size, int index, int sum1, int sum2) {
  if (index == size) {
    return sum1 == sum2;
  }

  // Try adding the current weight to either sum1 or sum2
  return canSplitEqually(size, index + 1, sum1 + weights[index], sum2) ||
         canSplitEqually(size, index + 1, sum1, sum2 + weights[index]);
}

int main() {
  int m;
  cin >> m;
  cin.ignore();

  while (m--) {
    string weiths_string;
    getline(cin, weiths_string);

    istringstream iss(
        weiths_string); // Crie um fluxo de string a partir da linha.

    int num;
    int sum = 0;
    while (iss >> num) {
      weights.push_back(num);
      sum += num;
    }

    if (canSplitEqually(weights.size(), 0, 0, 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

    weights.clear();
  }

  return 0;
}
