#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> friends;

bool bfs(int source){
  friends[source] = 1;
  
  queue<int> will;
  will.push(source);

  while(!will.empty()){
    int cur = will.front();
    will.pop();
    int flag_amizade = 3 - friends[cur];
    for(auto neigh : edges[cur])  {
      if(friends[neigh] == -1){
        friends[neigh] = flag_amizade;
        will.push(neigh);
      }else if(friends[neigh] != flag_amizade){
        return false;
      }
    }
  }
  
  return true;
}

int main() { 
  int n, m;
  cin >> n >> m;

  edges.resize(n + 1);
  friends.resize(n + 1, -1);
  for(int i = 0; i < m; i++){
    int nd1, nd2;
    cin >> nd1 >> nd2;
    edges[nd1].push_back(nd2);
    edges[nd2].push_back(nd1);
  }

  int possible = true;
  for(int i = 1; i <= n && possible; i++){
    if(friends[i] == -1)
      possible = bfs(i);
  }
  
  if(possible)
    for(int i = 1; i <= n; i++)
      cout << friends[i] << " ";
  else
    cout << "IMPOSSIBLE" << endl;
  
}