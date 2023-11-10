#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
vector<int> edges[MAX];
int visited[MAX];

bool bfs(int source, int team) {
  queue<pair<int, int>> qu;
  qu.push(make_pair(source, team));
  bool possible = true;

  while (!qu.empty() && possible) {
    int node = qu.front().first;
    int team_node = qu.front().second;
    qu.pop();
    visited[node] = team_node;
    int team_neigh = 3 - team_node;

    for (int neigh : edges[node])
      if (visited[neigh] == team_node){
        possible = false;
        break;
      }else if (!visited[neigh])
        qu.push(make_pair(neigh,team_neigh));
  }

  return possible;
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

  bool possible = true;
  for(int i = 1; i <= n && possible; i++)
    if(!visited[i])
      possible = bfs(i,1);

  if (possible) {
    for (int i = 1; i <= n; i++) 
      cout << visited[i] << " ";
  } else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
