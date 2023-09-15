#include <bits/stdc++.h>

using namespace std;

/*
Observation: this code isn't functional, because it don't consider the fact that everyone just can
get only one object of each kind. For each cell of vector, we're testing all possibilities of add
each object again or not. To solve this, we need consider already have used the object (second constraint). So, we need a second dimension in the memo vector to consider this information.
This new dimension will responsible for calculate the price considering each object and all of above.
vector<pair<int, int>> objs;
int max_value_person(int max_weight) {
  vector<int> memo(max_weight + 1, 0);

  for (int i = 1; i <= max_weight; i++) {
    memo[i] = 0;
    for (auto it : objs) {
      // cout << "Valor de it: " << it.first << endl;
      if (i - it.first >= 0)
        memo[i] = max(memo[i], memo[i - it.first] + it.second);
    }
  }

  return memo[max_weight];
}
*/

vector<pair<int, int>> objs;

int max_value_person(int num_obj ,int max_weight) {
  vector< vector<int> > memo(num_obj + 1, vector<int>(max_weight + 1,0));

  for(int i = 1; i <= num_obj; i++) {
    for (int j = 1; j <= max_weight; j++) {
      //The variable correct must be i, however, our matrix have one fake row 
      int correct = i - 1;
      if(j - objs[correct].first >= 0)
        memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - objs[correct].first] + objs[correct].second);
      else
        /* We need do that because we aren't more analising all objects by cell*/
        /*Each cell corresponding an object and a weight*/
        memo[i][j] = memo[i - 1][j];
    }
  }

  return memo[num_obj][max_weight];
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int num_obj;
    cin >> num_obj;

    for (int i = 0; i < num_obj; i++) {
      int price, weight;
      cin >> price >> weight;
      objs.push_back((make_pair(weight, price)));
    }

    int num_people;
    cin >> num_people;
    int ans = 0;
    for (int i = 0; i < num_people; i++) {
      int max_weight;
      cin >> max_weight;
      ans += max_value_person(num_obj, max_weight);
    }

    cout << ans << endl;
    objs.clear();
  }

  return 0;
}
