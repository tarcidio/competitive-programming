//NAME: Two Teams
//O(N)

//This code was made with a line in mind that is not constantly updated
#include <bits/stdc++.h>

using namespace std;

//Element that will compose the priority_queue
struct elem{
    int skill;
    int index;
    elem(int skill, int index){
        this->skill = skill;
        this->index = index;
    }
    bool operator<(const elem& comparative) const{
        return this->skill < comparative.skill;
    }
    //>>>why of the two const and one &?<<<
};

const int MAXN = 2e5 + 7;
int skills[MAXN];
priority_queue<elem> greater_skill;
int team[MAXN];

int main (){
    int n, k;
    cin >> n >> k;

    //Reading
    for(int i = 0; i < n; i++){
        cin >> skills[i];
        elem input(skills[i], i);
        greater_skill.push(input);
    }

    int chooser = 1;
    while(!greater_skill.empty()){
        //Get the index of the top of priority_queue
        int cur_index = greater_skill.top().index;
        greater_skill.pop();

        if(!team[cur_index]){//if the student wasn't chosen
            team[cur_index] = chooser;//to choose
            for(int i = 1; i <= k; i++){//and choose k neighbors
                if(!team[cur_index - i]) 
                    team[cur_index - i] = chooser;
                if(!team[cur_index + i]) 
                    team[cur_index + i] = chooser;
            }
            chooser == 1 ? chooser = 2 : chooser = 1;
        }
    }

    for(int i = 0; i < n; i++)
        cout << team[i];

    return 0;
}
