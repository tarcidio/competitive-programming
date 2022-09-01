//NAME: Does this graph exist?
//O(N^2 + M)

#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3 + 1;
int path [MAX_NODES][MAX_NODES];
vector<int> edges[MAX_NODES];
int dist[MAX_NODES];

void bfs(int source){
    memset(dist, -1, sizeof(dist));
    dist[source] = 0;
    queue<int> will;
    will.push(source);

    while(!will.empty()){
        int node = will.front();
        will.pop();
        for(int neigh : edges[node]){
            if(dist[neigh] == -1){
                will.push(neigh);
                dist[neigh] = dist[node] + 1;
            }
        }
    }
}

int main (){
    int num_nodes;
    cin >> num_nodes;

    for(int i = 0; i < num_nodes; i++)
        for(int j = 0; j < num_nodes; j++){
            cin >> path[i][j];
            if(path[i][j] == 1){
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    
    bool exist = true;
    for(int node = 0; node < num_nodes; node++){
        bfs(node);
        for(int i = 0; i < num_nodes; i++){
            if(path[node][i] != dist[i]){
                exist = false;
                break;
            }
        }
    }

    cout << (exist ? "sim" : "nao");

    return 0;
}