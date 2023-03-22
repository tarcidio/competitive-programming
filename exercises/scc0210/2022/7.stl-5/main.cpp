#include <bits/stdc++.h>

using namespace std;

int main() {
  int num_values;
  cin >> num_values;
  while (num_values) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < num_values; i++) {
      int value;
      cin >> value;
      pq.push(value);
    }
    int cost = 0;
    while (pq.size() > 1) {
      int sum = pq.top();
      pq.pop();
      sum += pq.top();
      pq.pop();

      pq.push(sum);
      cost += sum;
    }

    cout << cost << endl;

    cin >> num_values;
  }

  return 0;
}
