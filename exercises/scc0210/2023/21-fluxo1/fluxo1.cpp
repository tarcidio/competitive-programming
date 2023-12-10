#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> edges[501];
//Vector to help to identify path
int paren[501];

int num_nodes;

ll bfs(int source, vector< vector<ll> > capacity){
  memset(paren, -1, sizeof(paren));
  paren[source] = -2;
  queue<pair<int, ll>> q;
  q.push(make_pair(source, LLONG_MAX));

  while(!q.empty()){
    int node = q.front().first;
    ll flow_capacity = q.front().second;
    q.pop();

    for(auto neigh: edges[node]){
      if(paren[neigh] == -1 && capacity[node][neigh]){
        paren[neigh] = node;
        ll new_flow = min(flow_capacity, capacity[node][neigh]);
        if(neigh == num_nodes)
          return new_flow;
        q.push(make_pair(neigh,new_flow));
      }
    }
  }
  
  return 0;
}

ll maxSpeed(vector< vector<ll> >capacity){
  ll flow = 0, new_flow = 0;
  
  while(true){
    new_flow = bfs(1, capacity);
    if(!new_flow)
      break;
    
    int current = num_nodes;
    flow += new_flow;

    while(current != 1){
      int prev = paren[current];
      capacity[prev][current] -= new_flow;
      capacity[current][prev] += new_flow;
      current = prev;
    }
  }
  
  return flow;
}

int main() {
  int num_edges;
  cin >> num_nodes >> num_edges;

  vector< vector<ll> > capacity(num_nodes + 1, vector<ll>(num_nodes + 1,0));
  
  for(int i = 0; i < num_edges; i++){
    int n1, n2, weight;
    cin >> n1 >> n2 >> weight;
    edges[n1].push_back(n2);
    //Não entendo o motivo dessa próxima linha direito
    edges[n2].push_back(n1);
    capacity[n1][n2] += weight;
  }

  cout << maxSpeed(capacity) << endl;

  return 0;
}