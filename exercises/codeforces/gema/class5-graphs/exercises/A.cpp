//NAME:its possible to arrive?
//O(N + M)

#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e5 + 3;
vector<int> edges [MAX_NODES];
int visit[MAX_NODES];

void dfs(int cur){
    visit[cur] = 1;
    for(int neigh : edges[cur]){
        if(!visit[neigh]) dfs(neigh);
    }
}

int main (){
    int num_nodes, num_edges, nodeA, nodeB;
    cin >> num_nodes >> num_edges >> nodeA >> nodeB;
    
    for(int i = 0; i < num_edges; i ++){
        int from, to;
        cin >> from >> to;
        
        edges[from].push_back(to);
    }

    dfs(nodeA);
    cout << (visit[nodeB] ? "SIM" : "NAO");

    return 0;
}