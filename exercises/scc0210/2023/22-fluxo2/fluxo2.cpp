#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 5e3 + 1;

// Stores the graph
vector< vector< int > > edges;
// Stores residual graph
vector<vector<ll>> residual_graph;
// Stores augmenting path
int aug_path[MAX];
//Answers:
vector<pair<int, int>> ans;

ll bfs(int source, int dest) {
  // Reset aug_pathts
  memset(aug_path, -1, sizeof(aug_path));
  aug_path[source] = -2;

  // 1º elem: node
  // 2º elem: bottleneck util there
  queue<pair<int, ll>> q;
  q.push(make_pair(source, LLONG_MAX));

  while (!q.empty()) {
    // Get the first element
    int node = q.front().first;
    ll bottleneck = q.front().second;
    q.pop();
    // Thougth out the neighboors
    for (auto neigh : edges[node]) {
      if (aug_path[neigh] == -1 && residual_graph[node][neigh]) {
        // Update aug_patht
        aug_path[neigh] = node;
        // Calculate the bottleneck util here
        ll new_bottleneck = min(bottleneck, residual_graph[node][neigh]);
        // If already achieve the destinate
        if (neigh == dest)
          return new_bottleneck;
        q.push(make_pair(neigh, new_bottleneck));
      }
    }
  }

  return 0;
}

// Calculutate maximum flow rate in graph
void ford_fulkerson(int source, int dest) {
  // While there are augmenting path, do:
  while (true) {
    // Find augmenting path and return the bottleneck size
    // bottleneck: current bottleneck of the residual graph
    ll bottleneck = bfs(1, dest);
    // If bottleneck == 0, there aren't augmenting path
    if (!bottleneck)
      break;

    // Update the residual graph
    int current = dest;
    //cout << "Grafo residual: " << endl;
    //cout << current << " ";
    while (current != source) {
      int prev = aug_path[current];
      // Free flow
      residual_graph[prev][current] -= bottleneck;
      // Flow that is possible to redirect
      residual_graph[current][prev] += bottleneck;
      current = prev;
      //cout << current << " ";
    }
  }
}

void print_cuts(int source, int num_nodes) {
  ans.clear();
  queue<int> q;
  q.push(source);

  //Como temos ida e volta, precisamos garantir que não vai haver loop
  vector<int> visited(num_nodes + 1, 0);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    
    visited[node] = 1;

    for (auto neigh : edges[node]) { 
      if(!visited[neigh]){
        //Guarentee that was used and full used
        if ( (!residual_graph[neigh][node] && residual_graph[node][neigh]) || (residual_graph[neigh][node] && !residual_graph[node][neigh]))
          ans.push_back(make_pair(node, neigh));
        else
          q.push(neigh);
      }
        
    }
  }
}

int main() {
  int num_nodes, num_edges;

  while (cin >> num_nodes >> num_edges) {
    if (!num_nodes && !num_edges)
      break;

    // Edit size of residual graph
    residual_graph = vector<vector<ll>> (num_nodes + 1, vector<ll>(num_nodes + 1, 0));
    edges = vector<vector<int>> (num_nodes + 1);

    for (int i = 0; i < num_edges; i++) {
      int n1, n2, max_capacity;
      cin >> n1 >> n2 >> max_capacity;
      edges[n1].push_back(n2);
      // To throught out the residual_graph
      edges[n2].push_back(n1);
      residual_graph[n1][n2] += max_capacity;
      residual_graph[n2][n1] += max_capacity;
    }
    
    ford_fulkerson(1, 2);
    print_cuts(2, num_nodes);

    long long total_cost = 0;
    for(auto it: ans){
      //cout << it.first << " " << it.second << endl;
      total_cost += (residual_graph[it.first][it.second] + residual_graph[it.second][it.first])/2;
    }
    cout << "Custo total: " << total_cost << endl;
    cout << endl;

  }

  return 0;
}