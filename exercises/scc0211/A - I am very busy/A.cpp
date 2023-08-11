#include <bits/stdc++.h>

using namespace std;

typedef vector< pair<int,int> > vpii;

//When act1 < act2?
bool cmp(pair<int,int> act1, pair<int,int> act2){
  return act1.second < act2.second;
}

int num_act_done(vpii act, int num_act){
  int end_time = act[0].second;
  int num = 1;
  for(int i = 1; i < num_act; i++){
    if(act[i].first >= end_time){
      num++;
      end_time = act[i].second;
    }
  }
  return num;
}

int main() {
  int num_test;
  cin >> num_test;

  while(num_test--){
    int num_act;
    cin >> num_act;
    vpii act(num_act);
    for(int i = 0; i < num_act; i++){
      int start, end;
      cin >> start >> end;
      act[i] = make_pair(start,end);
    }
    sort(act.begin(), act.end(), cmp);
    cout << num_act_done(act, num_act) << endl;
  }

  return 0;
}