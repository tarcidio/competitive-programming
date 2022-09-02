//NAME: The farthest
//O(N + M)

#include <bits/stdc++.h>

using namespace std;

//Create graph
const int MAX_NODES = 1e5 + 3;
vector<int> edges[MAX_NODES];
int dist[MAX_NODES];

//Breadth first search
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
    int num_nodes, num_edges, nodeA, nodeB;
    cin >> num_nodes >> num_edges >> nodeA >> nodeB;

    //Reading
    for(int i = 0; i < num_edges; i++){
        int from, to;
        cin >> from >> to;

        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    bfs(nodeA);
    cout << dist[nodeB] << endl;

    return 0;
}