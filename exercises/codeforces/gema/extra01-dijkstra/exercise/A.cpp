#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int dist[MAXN];

vector< pair<int,int> > edges [MAXN];

void dijkstra(int num, int ori, int dest){
    for(int i = 1; i <= num; i++)
        dist[i] = INF;
    dist[ori] = 0;

    priority_queue< pair<int,int> , vector< pair<int,int> >, greater<pair<int,int>>> pq;
    pq.push(make_pair(dist[ori], ori));

    while( !pq.empty() ){
        int nCur = pq.top().second;
        int dMin = pq.top().first;
        pq.pop();

        if(dMin <= dist[nCur]){
            for(int i = 0; i < edges[nCur].size(); i++){
                int neigh, weight;
                tie(neigh, weight) = edges[nCur][i];

                if(dist[nCur] + weight < dist[neigh]){
                    dist[neigh] = dist[nCur] + weight;
                    pq.emplace(dist[neigh],neigh);
                    //pq.push(make_pair(dist[neigh], neigh));
                }
            }
        }
    }
}

int main(){

    int n, m, a;
    cin >> n >> m >> a;

    for(int i = 0; i < m; i++){
        int nd1, nd2, w;
        cin >> nd1 >> nd2 >> w;
        edges[nd1].emplace_back(nd2, w);
        edges[nd2].emplace_back(nd1, w);
    }

    dijkstra(n, a, n);
    for(int node = 1; node <= n; node++){
        int Dist = dist[node];
        if(Dist != INF)
            cout << Dist << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}