//NAME: Teleport
//O(N + M)

#include <bits/stdc++.h>

using namespace std;

//Create graph
const int MAX_NODES = 1e5 + 2;
vector<int> edges [MAX_NODES];
int visit[MAX_NODES];

//Delph first search
void dfs(int cur){
    visit[cur] = 1;
    for(int neigh: edges[cur]){
        if(!visit[neigh]) 
            dfs(neigh);
    }
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

    //Count how many connect components have
    int count_dfs = 0;
    for(int i = 1; i <= num_nodes; i++){
        if(!visit[i]){
            dfs(i);
            count_dfs++;
        }
    }

    cout << count_dfs << endl;

    return 0;
}