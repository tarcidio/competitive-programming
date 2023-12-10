#include <bits/stdc++.h>

using namespace std;

//Always visualize the second term
bool cmp(pair<int,int> j1, pair<int,int> j2){
    if(j1.first != j2.first)
        return j1.first < j2.first;
    else
        return j1.second > j2.second;
}

int main(){
    int num_cases;
    cin >> num_cases;

    for(int i =  0; i < num_cases; i++){
        //n: Number of jobs in the queue
        //m: Position of job that interests us
        int n, m;
        cin >> n >> m;

        //First element: the priority of job
        //Seconde element: the number of job
        //decltype: is a feature of c++ that allows determine the expression type at compile time
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp) > pq (&cmp);
        
        //Fill the priority queue
        for(int j = 0; j < n; j++){
            int priority;
            cin >> priority;
            pq.push(make_pair(priority, j));
        }

        while(!pq.empty()){
            cout << "(" << pq.top().first << "," << pq.top().second << ")"<< endl;
            pq.pop();
        }

        /*
        
        //Discovery the order of job will execute
        pair<int, int> job;
        int order = 0;
        while(!pq.empty()){
            order++;
            job = pq.top();
            pq.pop();
            if(job.second == m){
                cout << order << endl;
                break;
            }
        }

        */
    }

    return 0;
}

/*
1
56 32
6 2 1 4 6 4 2 2 5 4 1 4 9 6 3 8 2 2 4 1 5 7 5 6 7 9 3 2 5 6 7 5 2 3 8 8 2 2 9 1 7 3 4 1 5 8 6 8 6 8 9 3 7 5 5 8
*/