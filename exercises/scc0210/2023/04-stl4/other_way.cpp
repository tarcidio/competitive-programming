#include <bits/stdc++.h>

using namespace std;

struct Register {
  int id, period, time;

  // Operator true: this < another
  bool operator<(const Register another) const {
    if (another.time != time)
      return another.time < time;
    else
      return another.id < id;
  }
};

int main() {
  string input;
  cin >> input;
  priority_queue<Register> pq;

  while (input[0] != '#') {
    Register reg;
    // First: id
    // Second: period
    // Third: time
    cin >> reg.id >> reg.period;
    reg.time = reg.period;
    pq.push(reg);
    cin >> input;
  }

  int K;
  cin >> K;
  while (K--) {
    auto reg = pq.top();
    pq.pop();
    reg.time += reg.period;
    cout << reg.id << endl;
    pq.push(reg);
  }

  return 0;
}