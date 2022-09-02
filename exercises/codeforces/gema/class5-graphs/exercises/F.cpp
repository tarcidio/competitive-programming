//NAME: Cyclic Componentes
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 2e5 + 5;
vector<int> edges[MAX_NODES];
int visit[MAX_NODES];

//This dfs returned 1 if find a cycle and 0 if not
int dfs(int cur, int source, int depth){
    visit[cur] = 1;
    for(int neigh : edges[cur]){
        //cout << "cur: " << cur << " source: " << source << " neigh: " << neigh << endl;
        if(neigh == source && depth > 1){
            return 1;
        }else if(!visit[neigh]){
            if(dfs(neigh, source, depth + 1))
                return 1;
        }
    }
    return 0;
}

int main (){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    for(int i = 0; i < num_edges; i++){
        int from, to;
        cin >> from >> to;

        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    int cycles = 0;
    for(int node = 1; node <= num_nodes; node++){
        if(!visit[node]){
            cycles+= dfs(node, node, 0);   
        }
    }

    cout << cycles << endl;

    return 0;
}