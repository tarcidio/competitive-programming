//Algorithm: from node A to B, we want to find the shortest path. Let's go through the node with shortest
//distance beetwen it and A. (Dynamic Programming and Greedy)

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 1;

//Array that stores the minumum DISTance between node and origin
int dist[MAXN];
//Vctor that stores the graph
vector<pair<int,int>> edges[MAXN];

//Calculate the shortest distance between ORIgin and DESTiny
int dijkstra(int num, int ori, int dest){
    //Set the array distance with infinity
    //It's needed start to 1 because the first node is 1
    for(int i = 1; i <= num; i++)
        dist[i] = INF;
    
    //Set the origin with  distance to him equal zero
    dist[ori] = 0;

    //Create a priority queue: after visit a node, through the yours neighbors
    //Default: priority_queue< int, vector<int>, less<int> > pq;
    priority_queue< pair <int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    //Start with the origin
    pq.push(make_pair(dist[ori], ori));

    while(!pq.empty()){
        //Capture the top of pq
        int nCur = pq.top().second;
        int min = pq.top().first;
        pq.pop();

        if(min <= dist[nCur]){//Verify if the element is valid

            //Through the your neighboor and push them in the priority queue with
            //the upgrade distance to origin
            for(int i = 0; i < edges[nCur].size(); i++){
                //Receive the neighboor and the weigh of link nCur - neighboor
                int neigh, weight;
                tie(neigh, weight) = edges[nCur][i];

                //Upgrade the distance
                if(dist[neigh] > dist[nCur] + weight){
                    dist[neigh] = dist[nCur] + weight;
                    pq.push(make_pair(dist[neigh], neigh));
                    //pq.emplace(dist[neigh], neigh);  
                }   
            }
        }
    }

    return dist[dest] != INF ? dist[dest] : -1;
}

int main (){
    //Reading the graph
    int num_nodes, num_edges;
    int ori, dest;
    cin >> num_nodes >> num_edges;
    cin >> ori >> dest;
    for(int i = 0; i < num_edges; i++){
        int nd1, nd2, w;
        cin >> nd1 >> nd2 >> w;
        edges[nd1].emplace_back(nd2, w);
        edges[nd2].emplace_back(nd1, w);
    }

    //Call dijkstra
    cout << dijkstra(num_nodes, ori, dest) << endl;

    return 0;
}

/*
12 15
1 12
1 2 1
1 3 1
2 4 1
3 4 1
4 5 1
4 6 1
5 7 1
6 7 1
7 8 1
7 9 1
9 10 1
8 10 1
10 12 1000
1 11 100
12 11 100
*/
//R: 200
//R: 1 11 12

/*
7 7
1 7
1 2 3
1 4 1
2 5 8
4 6 2
5 6 5
5 7 4
6 7 10
*/
//R: 12
//R: 1 4 6 5 7
