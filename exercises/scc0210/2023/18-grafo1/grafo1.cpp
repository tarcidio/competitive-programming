#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;

const int NO_VISIT = -1;
const int MAXN = 5e3 + 1;
vector<pii> edges[MAXN];

vector<ll> dijkstra(int num, int ori) {
  // It's needed start to 1 because the first node is 1
  vector<ll> dist(num + 1, NO_VISIT);

  dist[ori] = 0;
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  pq.push(make_pair(dist[ori], ori));

  while (!pq.empty()) {
    ll distance;
    int nCur;
    tie(distance, nCur) = pq.top();
    pq.pop();
    if (distance <= dist[nCur]) {
      int size_edges_nCur = edges[nCur].size();
      for (int i = 0; i < size_edges_nCur; i++) {
        int neigh, weight;
        tie(neigh, weight) = edges[nCur][i];
        if (dist[neigh] > dist[nCur] + weight || dist[neigh] == NO_VISIT) {
          dist[neigh] = dist[nCur] + weight;
          pq.push(make_pair(dist[neigh], neigh));
        }
      }
    }
  }
  return dist;
}

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int n1, n2, w;
    cin >> n1 >> n2 >> w;
    edges[n1].push_back(make_pair(n2, w));
    edges[n2].push_back(make_pair(n1, w));
  }

  vector<vector<ll>> distances(n + 1);

  while (q--) {
    int ori, dest;
    cin >> ori >> dest;
    if (distances[ori].empty())
      distances[ori] = dijkstra(n, ori);
    cout << distances[ori][dest] << endl;
  }
}