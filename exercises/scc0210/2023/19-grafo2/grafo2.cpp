#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 1;
vector<int> edges_dfs[MAXN];

struct union_find {
  vector<int> par;
  vector<int> sz;

  union_find(int num_nodes) {
    par.resize(num_nodes + 1);
    sz.resize(num_nodes + 1);
    for (int i = 1; i <= num_nodes; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }

  int find(int node) {
    return par[node] == node ? node : par[node] = find(par[node]);
  }

  void unite(int nd1, int nd2) {
    int p_nd1 = find(nd1);
    int p_nd2 = find(nd2);

    if (sz[p_nd2] > sz[p_nd1])
      swap(p_nd1, p_nd2);

    par[p_nd2] = p_nd1;
    sz[p_nd1] += sz[p_nd2];
  }
};

bool cmp(tuple<int, int, int> e1, tuple<int, int, int> e2) {
  return get<2>(e1) < get<2>(e2);
}

ll kruskal(vector<tuple<int, int, int>> edges, int num_nodes) {
  sort(edges.begin(), edges.end(), cmp);
  struct union_find uf(num_nodes);
  ll cost_total = 0;
  for (auto [nd1, nd2, cost] : edges) {
    if (uf.find(nd1) != uf.find(nd2)) {
      uf.unite(nd1, nd2);
      cost_total += cost;
    }
  }
  return cost_total;
}

void dfs(vector<int> *visit, int nCur) {
  (*visit)[nCur] = 1;
  for (auto neigh : edges_dfs[nCur]) {
    if (!(*visit)[neigh])
      dfs(visit, neigh);
  }
  (*visit)[nCur] = 2;
}

bool verify_conex(int num_nodes) {
  vector<int> visit(num_nodes + 1, 0);
  dfs(&visit, 1);
  for (int i = 1; i <= num_nodes; i++)
    if (!visit[i]) {
      return false;
    }
  return true;
}

int main() {

  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges;

  for (int i = 0; i < m; i++) {
    int nd1, nd2;
    int cost;
    cin >> nd1 >> nd2 >> cost;
    edges.push_back(make_tuple(nd1, nd2, cost));
    edges_dfs[nd1].push_back(nd2);
    edges_dfs[nd2].push_back(nd1);
  }

  if (verify_conex(n))
    cout << kruskal(edges, n) << endl;
  else
    cout << "IMPOSSIBLE";

  return 0;
}