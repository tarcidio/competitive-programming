#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3;
vector<int> edges[MAX_NODES];
int dist[MAX_NODES];
int ant[MAX_NODES];

void bfs(int source){
    queue<int> q;
    q.push(source);
    memset(dist, -1, sizeof(dist));
    dist[source] = 0;
    memset(ant, -1, sizeof(ant));

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neigh: edges[node]){
            if(dist[neigh] != -1){
                q.push(negih);
                dist[neigh] = dist[node] + 1;
                ant[neight] = node;
            }
        }
    }
}

int main(){

    return 0;
}