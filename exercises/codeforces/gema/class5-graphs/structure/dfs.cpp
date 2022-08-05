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
    }

    //Print the graph
    for(int i = 0; i < num_nodes; i++){
        cout << "Nó " << i << " |";
        for(int it : edges[i])
            cout << " --> "<< it;
        cout << " --> NULL" << endl;
    }

    //Print the visit array
    dfs(1);
    cout << "The vector visit with dfs(1) is: ";
    for(int i = 0; i < num_nodes; i++){
        cout << visit[i] << " ";
    }
    cout << endl;

    //Print the number of connected component
    int num_coneccted_component = 0;
    memset(visit, 0, sizeof(visit));
    for(int i = 0; i < num_nodes; i++){
        if(!visit[i]){
            num_coneccted_component++;
            dfs(i);//O(N + M)
        }
    }
    cout << "The number of connected component of this graphs is " << num_coneccted_component << endl;

    return 0;
}

//example:
/*
5 6
0 1
0 3
1 4
2 1
3 4
4 3
*/