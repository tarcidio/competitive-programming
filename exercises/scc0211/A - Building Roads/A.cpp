#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
vector<int> edges[MAX];
int visited[MAX];

void dfs(int source) {
  visited[source] = 1;
  for (int neigh : edges[source])
    if (!visited[neigh])
      dfs(neigh);
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int nd1, nd2;
    cin >> nd1 >> nd2;
    edges[nd1].push_back(nd2);
    edges[nd2].push_back(nd1);
  }

  vector<int> roads;
  int count_roads = 0;
  for (int i = 1; i <= n; i++)
    if (!visited[i]) {
      dfs(i);
      count_roads++;
      roads.push_back(i);
    }

  if(count_roads < 2)
    cout << 0 << endl;
  else{
    cout << count_roads - 1 << endl;
    for (int i = 0; i < count_roads - 1; i++)
    cout << roads[i] << " " << roads[i + 1] << endl;
  }
    
  //cout << endl;

  return 0;
}
