#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3;
vector<int> edges [MAX_NODES];
int visit [MAX_NODES];

void dfs(int source){
    for(){
        dfs();
    }
}

int main(){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    for(int i = 0; i < num_edges; i++){
        int source_node, dest_node;
        cin >> source_node >> dest_node;
        edges[source_node].push_back(dest_node);
    }

    return 0;
}