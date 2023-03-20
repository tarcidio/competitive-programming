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
        //Second element: the number of job
        queue<pair<int,int>> qu;
        priority_queue<int> num_priority;
        
        //Fill the priority queue
        for(int j = 0; j < n; j++){
            int priority;
            cin >> priority;
            qu.push(make_pair(priority, j));
            num_priority.push(priority);
        }
    
        //Discovery the order of job will execute
        pair<int, int> job;
        int time = 0;
        while(!qu.empty()){
            pair<int,int> job = qu.front();
            qu.pop();
            
            if(job.first != num_priority.top()){
                qu.push(job);
            }else{
                time++;
                num_priority.pop();
                if(job.second == m){
                    cout << time << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
