//NAME: Two Teams
//O(N)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
typedef pair<int,int> elem;
vector<elem> skill_index(MAXN);
 
int main (){
    int n, k ;
    cin >> n >> k ;
    
    //Reading
    for (int i = 0; i < n; i++){
        cin >> skill_index[i].first;
        skill_index[i].second = i;
    }
    //Sorting with skill being the key
    //Could use a priority_key, but there aren't necessary in sorting many times
    sort(skill_index.rbegin(), skill_index.rend());
    queue<int> remaining;//Controls the indexes that are bigger (queue is necessary?)
    set <int> available;//Controls the indexes that were used or not
    for (int i = 0; i < n; i++){
        remaining.push(skill_index[i].second);//store index with skill as key
        available.insert(i);//store 0, 1, 2, ..., n-2, n-1
    }
    
    int ans[MAXN];//Controls the answer. Could be a array int, but this way is simpler
    int cur_team = 1;//Controls the current team in the iteration
   
    while(!available.empty()){//while there are indexes to use
        //Remove indexes from queue that have already been used
        while(!available.count(remaining.front()))
            remaining.pop();

        //Get the next indice valid from queue
        int cur_index = remaining.front();
        remaining.pop();

        //Store selected students
        vector <int> selected (1, cur_index);
        //Find the students to the LEFT of the cur_index in the queue
        auto it = available.find(cur_index);
        for (int i = 0; i < k && it != available.begin(); i++){
            //It's important to see that the available.begin() points to the FIRST element, different of available.end() that points to NULL
            it--;
            selected.push_back(*it);
        }

        //Find the students to the RIGHT of the cur_index in the queue
        it = next(available.find(cur_index));
        for (int i = 0; i < k && it != end(available); i++){
            selected.push_back(*it);
            it++;
        }
        //OBS: could join the two for, but this way is simpler

        //Insert the selected students in the answer and update the indexes valids
        for (auto i : selected){
            ans[i] = cur_team;
            available.erase(i) ;
        }
        cur_team == 1 ? cur_team = 2 : cur_team = 1;

        /*
        Other way to code
        XOR operation: 1 if the two number is different and 0 isn't
        In this case, ans is a string
        for (auto i : selected){
            ans[i] = '1' + cur_team;
            cout << "Valor do i: " << i << endl;
            available.erase(i);
        }
        cur_team ^= 1 ;
        */      
    }

    for(int i = 0; i < n; i ++)
        cout << ans[i];

    return 0;
}
