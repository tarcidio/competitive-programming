//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

const int TAM = 1e3;
vector<int> edges[TAM];
vector<int> edges_trans[TAM];
stack<int> finished;
vector<int> visited;

void dfs_stack(int source) {
  visited[source] = 1;
  for (auto neigh : edges[source])
    if (!visited[neigh]) {
      dfs_stack(neigh);
    }
  finished.push(source);
}

void dfs(int source) {
  visited[source] = 1;
  for (auto neigh : edges_trans[source])
    if (!visited[neigh])
      dfs(neigh);
}

int kosaraju(int num_nodes) {
  visited = vector<int>(num_nodes, 0);

  // Fazer dfs em edges a partir de (1)
  for (int i = 0; i < num_nodes; i++)
    if (!visited[i])
      dfs_stack(i);

  // Fazer dfs em edges_trans a partir da pilha gerado em edges
  int ans = 0;
  visited = vector<int>(num_nodes, 0);
  while (!finished.empty()) {
    int node = finished.top();
    finished.pop();
    if (!visited[node]) {
      ans++;
      dfs(node);
    }
  }

  return ans;
}

int main() {
  int p, t;
  cin >> p >> t;
  cin.ignore();

  while (!(!p && !t)) {
    map<string, int> names;

    for (int i = 0; i < p; i++) {
      string name;
      getline(cin, name);
      names[name] = i;
    }

    for (int i = 0; i < t; i++) {
      string n1, n2;
      getline(cin, n1);
      getline(cin, n2);
      edges[names[n1]].push_back(names[n2]);
      edges_trans[names[n2]].push_back(names[n1]);
    }

    cout << kosaraju(p) << endl;

    for (int i = 0; i < p; i++) {
      edges[i].clear();
      edges_trans[i].clear();
    }

    cin >> p >> t;
    // Mesmo apos a leitura sem \n, é importante colocar cin.ignore()
    cin.ignore();
  }

  return 0;
}

/*Explicação: Kosaraju*/
/*
1. Faz DFS no grafo original armazenando em pilha aqueles que finalizaram.
2. Faz DFS no grafo transposto na ordem da pilha gerada
3. Cada DFS do passo 2 é uma componente fortemente conexa

Explicação: com o primeiro DFS, captur-se a relacao u->v (ordenação topológica).
Em outras palavras, o nó u será processado antes de v. Isso é importante porque,
quando fazemos o segundo DFS partindo de u no grafo transporsto, não chegaremos
em v (pois, no grafo, estará u<-v). Exceto, é claro, se u e ve pertencerem ao
mesmo grafo fortemente conexo e, neste caso, serão contabilizados no mesmo
grafo.

Explicando em outras palavras, o maior risco de fazer DFS no transposto sem um
ordem definida, podemos começar o DFS pelo grafo fortemente conexo da DAG (Grafo
Acíclico Direcionado) que aponta para outro grafo fortemente conexo.
*/
