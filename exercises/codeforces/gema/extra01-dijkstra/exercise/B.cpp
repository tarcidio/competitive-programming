#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
const int INF = 0x3f3f3f3f;

vector< pair<int,int> > edges[MAX];
int dist[MAX];
vector<int> par [MAX];
set < pair<int,int> > path;
vector< pair<int,int> > stores;

void dijkstra(int num, int ori){
    for(int i = 1; i <= num; i++)
        dist[i] = INF;
    dist[ori] = 0;
    //par[ori] = -1;

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(dist[ori],ori));

    while( !pq.empty() ){
        int nCur = pq.top().second;
        int min = pq.top().first;
        pq.pop();

        if(min <= dist[nCur]){
            for(int i = 0; i < edges[nCur].size(); i++){
                int neigh, weight;
                tie(neigh,weight) = edges[nCur][i];

                if(dist[neigh] >= dist[nCur] + weight){
                    //par[neigh] = nCur;
                    if(dist[neigh] > dist[nCur] + weight)
                        par[neigh].clear();
                    par[neigh].emplace_back(nCur);
                    dist[neigh] = dist[nCur] + weight;
                    pq.push(make_pair(dist[neigh], neigh));
                }
            }
        }
    }
}

void makePath(int dest){
    queue<int> qu_par;
    qu_par.push(dest);
    while( !qu_par.empty() ){
        int child = qu_par.front();
        qu_par.pop();
        for(int i = 0; i < par[child].size(); i++){
            int Par = par[child][i];
            if( path.find(make_pair(child, Par)) == path.end() ) 
                path.emplace(make_pair(child, Par));
            qu_par.push(Par);
        }
    }
}

void verifyEdges(int num, int nA, int nB){
    dijkstra(num, nA);
    makePath(nB);
    for(auto [nd1,nd2]: stores){
        pair<int, int> pA(nd1, nd2);
        pair<int, int> pB(nd2, nd1);
        if( path.find(pA) != path.end() || path.find(pB) != path.end() )
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
    }
}

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for(int i = 0; i < m; i++){
        int nd1, nd2, w;
        cin >> nd1 >> nd2 >> w;
        edges[nd1].emplace_back(nd2, w);
        edges[nd2].emplace_back(nd1, w);
        stores.emplace_back(nd1, nd2);
    }
    verifyEdges(n, a, b);

    return 0;
}

/*
4 4 1 4
1 2 1
2 4 1
1 3 1
3 4 1
*/

/*
5 6 1 5
1 2 2
2 3 1
3 5 1
1 4 2
4 3 2
1 3 10
*/