#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3;
vector<int> edges [MAX_NODES];
int visit [MAX_NODES];//0: unvisited node; 1: visited node; 2: completed node

void dfs(int cur){
    visit[cur] = 1;
    for(int neigh: edges[cur]){
        if(!visit[neigh])//visit[neigh] == 0 
            dfs(neigh);
    }
    visit[cur] = 2;
}

int main(){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    for(int i = 0; i < num_edges; i++){
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int acompcomplex = 0;
    for(int i = 0; i < num_nodes; i++){
        if(!visit[i]){
            acompcomplex++;
            dfs(i);//O(N + M)
        }
    }

    return 0;
}