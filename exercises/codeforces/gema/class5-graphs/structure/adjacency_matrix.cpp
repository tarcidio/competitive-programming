#include <bits/stdc++.h>

using namespace std;

const int MAX_NODES = 1e3;

int adjacency_matrix[MAX_NODES][MAX_NODES];

int main(){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    fill(*adjacency_matrix, *adjacency_matrix + num_nodes*num_nodes, 0);

    for(int i = 0; i < num_edges; i ++){
        int source_node, dest_node;
        cin >> source_node >> dest_node;
        adjacency_matrix[source_node][dest_node] = 1;
    }
    
    for(int i = 0; i < num_nodes; i++){
        for(int j = 0; j < num_nodes; j++){
            cout << "Nó " << i << " --> " << j << ":" << adjacency_matrix[i][j] << endl;
        }
    }

    return 0;
}