//NAME: Cyclic Components
//O(N + M)

#include <bits/stdc++.h>

using namespace std;

//Creat graph
const int MAX_NODES = 2e5 + 5;
vector<int> edges[MAX_NODES];
int visit[MAX_NODES];
//Frag to control if exist cycle
bool exist_cycle = true;
//Flag to amount of cycle
int cont_cycle = 0;

//This dfs returned 1 if find a cycle and 0 if not
int dfs(int cur){
    visit[cur] = 1;
    if(edges[cur].size() != 2) exist_cycle = false;

    for(int neigh : edges[cur]){
        //cout << "cur: " << cur << " source: " << source << " neigh: " << neigh << endl;
        if(!visit[neigh]){
            dfs(neigh);
        }
    }
    return 0;
}

int main (){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    //Reading
    for(int i = 0; i < num_edges; i++){
        int from, to;
        cin >> from >> to;

        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    //Algorithm
    for(int node = 1; node <= num_nodes; node++){
        if(!visit[node]){
            dfs(node);
            exist_cycle ? cont_cycle++ : exist_cycle = true;
        }
    }

    cout << cont_cycle << endl;

    return 0;
}