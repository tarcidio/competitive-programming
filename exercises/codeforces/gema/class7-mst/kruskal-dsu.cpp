//Tree that spans all nodes of graph
#include <bits/stdc++.h>

using namespace std;

struct union_find{

    vector<int> par;//Vector that stores the component parent
    vector<int> sz;//Size of component

    //Constructor: the nodes begin in digit 1
    union_find(int num_nodes){
        par.resize(num_nodes + 1);
        sz.resize(num_nodes + 1);
        for(int i = 1; i <= num_nodes; i ++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    //Find the component parent
    //Condition to be parent: par[node] == node
    int find(int node){
        return par[node] == node ? node : par[node] = find(par[node]);
    }

    //Join the components
    void unite(int nd1, int nd2){
        int p_nd1 = find(nd1);
        int p_nd2 = find(nd2);

        if(sz[p_nd2] > sz[p_nd1])
            swap(p_nd1, p_nd2);

        //if(nd1 != nd2){//The check will be happens in kruskal function
        par[p_nd2] = p_nd1;
        sz[p_nd1] += sz[p_nd2];
        //}
    }
};

int cmp(tuple<int,int,int> ed1, tuple<int,int,int> ed2){
    return get<2>(ed1) < get<2>(ed2);
}

//Algorithm
int kruskal(vector<tuple<int,int,int>> edges, int num_nodes){

    sort(edges.begin(), edges.end(), cmp);

    union_find uf(num_nodes);
    int weight_total = 0;

    //Loop through the edges
    for(auto [nd1, nd2, weight]: edges){
        //If the nodes don't belong same components
        if (uf.find(nd1) != uf.find(nd2)){
            //Join components
            uf.unite(nd1,nd2);
            weight_total += weight;
        }
    }

    return weight_total;
}

int main (){
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;
    vector<tuple<int,int,int>> edges;

    for(int i = 0; i < num_edges; i++){
        int nd1, nd2, w;
        cin >> nd1 >> nd2 >> w;
        //"Push" the tuple
        edges.emplace_back(nd1, nd2, w);
    }

    cout << kruskal(edges, num_nodes);

    return 0;
}

/*
10 14
1 4 4
1 2 1
2 3 5
2 5 100
2 7 1 
3 4 2
3 5 1
5 6 4
5 8 1
5 9 3
6 9 15
7 8 1
8 10 9
9 10 8
*/
