//NAME:Little Maria
//O(N + M)

#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3 + 3;
set<int> edges[MAX_NODES];
int visit[MAX_NODES];

void dfs(int cur){
    visit[cur] = 1;
    for(int neigh:edges[cur])
        if(!visit[neigh]) dfs(neigh);
}

int main (){
    int num_nodes, num_edges, node_i, node_maria;
    cin >> num_nodes >> num_edges >> node_i >> node_maria;

    queue<pair<int,int>> tests;
    for(int i = 0; i < num_edges; i++){
        int from, to;
        cin >> from >> to;
        edges[from].insert(to);
        edges[to].insert(from);

        tests.push({from,to});
    }

    bool exist = true;

    for(int i = 0; i < num_edges; i++){
        int from = tests.front().first;
        int to = tests.front().second;
        tests.pop();
        memset(visit, 0, sizeof(visit));

        edges[from].erase(to);
        edges[to].erase(from);

        dfs(node_i);
        if(!visit[node_maria]) exist = false;

        edges[from].insert(to);
        edges[to].insert(from);
    }

    if(!num_edges)
        exist = false;

    cout << (exist ? "SIM" : "NAO") << endl;

    return 0;
}

//Erase a edges that is represented by adjacency list is hard because is necessary pointer everytime
//But the vector of the list will be updated always so mantain the pointer correct isn't efficient
//These way, we must use set

/*
Deleting and inserting an edge that is represented by an adjacency list is difficult because it is necessary to keep the pointer always. Note that the list vector will be constantly updated making saving the pointer a difficult task. In this way, we should use set.
*/