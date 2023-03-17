#include <bits/stdc++.h>

using namespace std;

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
        queue<pair<int,int>> qu;
        int num_priority[10];
        
        //Fill the priority queue
        for(int j = 0; j < n; j++){
            int priority;
            cin >> priority;
            qu.push(make_pair(priority, j));
            num_priority[priority]++;
        }
    
        //Discovery the order of job will execute
        pair<int, int> job;
        int order = 0;
        while(!qu.empty()){
            pair<int,int> job = qu.front();
            qu.pop();
            
            bool flag_priority = false;
            //Verify if there are a priority
            for(int i = job.first + 1; i <= 9; i++){
                if(num_priority[i])
                    flag_priority = true;
            }
            
            if(flag_priority){
                qu.push(job);
            }else{
                order++;
                if(job.second == m){
                    cout << order << endl;
                    break;
                }
            }
        }
    }

    return 0;
}

/*
1
56 32
6 2 1 4 6 4 2 2 5 4 1 4 9 6 3 8 2 2 4 1 5 7 5 6 7 9 3 2 5 6 7 5 2 3 8 8 2 2 9 1 7 3 4 1 5 8 6 8 6 8 9 3 7 5 5 8
*/
