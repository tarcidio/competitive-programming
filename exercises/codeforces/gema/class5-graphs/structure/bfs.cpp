#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3 + 2;
vector<int> edges[MAX_NODES];
int dist[MAX_NODES];//dist between x that dist[x] = 0 and others nodes

void bfs(int source){
    //set the dist
    memset(dist, -1, sizeof(dist));
    dist[source] = 0;
    //set the queue
    queue<int> will;
    will.push(source);

    while(!will.empty()){
        int node = will.front();
        will.pop();
        for(int neigh: edges[node]){
            if(dist[neigh] == -1){
                dist[neigh] = dist[node] + 1;
                will.push(neigh);
            }
        }
    }
}

int main(){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    for(int i = 0; i < num_edges; i++){
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        //edges[to].push_back(from);
    }

    //Print the graph
    for(int i = 0; i < num_nodes; i++){
        cout << "Nó " << i << " |";
        for(auto it = edges[i].begin(); it != edges[i].end(); it++)
            cout << " --> "<< *it;
        cout << " --> NULL" << endl;
    }

    bfs(1);

    //Print the dist array
    cout << "The vector dist with source 1 is: ";
    for(int i = 0; i < num_nodes; i++){
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}

//exemple:
/*
5 7
0 1
0 2
0 3
1 4
2 1
3 4
4 3
*/