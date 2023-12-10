#include <bits/stdc++.h>

using namespace std;

/*
First:  id
Second: time
Third:  fine
*/
// OBS:  with struct is more clean (ops)
typedef tuple<int, int, int> tiii;

// j1 < j2
bool cmp(tiii j1, tiii j2) {
  if (get<1>(j1) * get<2>(j2) != get<1>(j2) * get<2>(j1))
    // j1.time * j2.fine > j2.time * j1.fine
    return get<1>(j1) * get<2>(j2) > get<1>(j2) * get<2>(j1);
  else
    return get<0>(j1) > get<0>(j2);
}

priority_queue<tiii, vector<tiii>, decltype(&cmp)> jobs(&cmp);

int main() {
  int num_cases;
  cin >> num_cases;
  int first = true;
  while (num_cases--) {
    if (!first)
      cout << endl << endl;
    first = false;

    int num_jobs;
    cin >> num_jobs;
    for (int i = 1; i <= num_jobs; i++) {
      int time, fine;
      cin >> time >> fine;
      jobs.push(make_tuple(i, time, fine));
    }

    while (!jobs.empty()) {
      cout << get<0>(jobs.top()) << " ";
      jobs.pop();
    }
  }
  return 0;
}