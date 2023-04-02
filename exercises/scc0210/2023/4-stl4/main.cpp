// O(K*logN)
// If we use the pq time[3000], we have O(N^3*logN)
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> tiii;

// cmp true: r1 < r2
bool cmp(tiii r1, tiii r2) {
  if (get<2>(r1) != get<2>(r2))
    return get<2>(r1) > get<2>(r2);
  else
    return get<0>(r1) > get<0>(r2);
}

int main() {
  string input;
  cin >> input;
  priority_queue<tiii, vector<tiii>, decltype(&cmp)> pq(&cmp);
  while (input[0] != '#') {
    tiii reg;
    // First: id
    // Second: period
    // Third: time
    cin >> get<0>(reg) >> get<1>(reg);
    get<2>(reg) = get<1>(reg);
    pq.push(reg);
    cin >> input;
  }

  int K;
  cin >> K;

  while (K--) {
    auto reg = pq.top();
    pq.pop();
    get<2>(reg) += get<1>(reg);
    cout << get<0>(reg) << endl;
    pq.push(reg);
  }

  return 0;
}
