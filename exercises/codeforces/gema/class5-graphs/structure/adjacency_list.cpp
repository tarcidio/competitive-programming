#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 1e3;
vector<int> adjacency_list[MAX_NODE];

int main(){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    for(int i = 0; i < num_edges; i++){
        int source_nodes, dest_nodes;
        cin >> source_nodes >> dest_nodes;

        adjacency_list[source_nodes].push_back(dest_nodes);
    }

    for(int i = 0; i < num_nodes; i++){
        cout << "Nó " << i << ": ";
        for(auto it = adjacency_list[i].begin(); it != adjacency_list[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;
}