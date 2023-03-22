#include <bits/stdc++.h>

using namespace std;

//Explanation: she wants the biggest streak
const int MAX = 1e9 + 1;
int snowflakes_id[MAX];

int main() {
  int num_cases, num_snowflakes, count, ans;
  cin >> num_cases;
  while (num_cases--) {
    cin >> num_snowflakes;
    map<int, int> ocurr_snowflake; // what is your name?
    count = ans = 0;
    for (int i = 0; i < num_snowflakes; i++)
      cin >> snowflakes_id[i];
    for (int j = 0; j < num_snowflakes; j++) {
      if (ocurr_snowflake.find(snowflakes_id[j]) ==
          ocurr_snowflake.end()) { // If
        ocurr_snowflake[snowflakes_id[j]] = j;
        count++;
      } else {
        if (count > ans)
          ans = count;
        j = ocurr_snowflake[snowflakes_id[j]];
        ocurr_snowflake.clear();
        count = 0;
      }
    }
    if (count > ans)
      ans = count;
    cout << ans << endl;
  }

  return 0;
}
