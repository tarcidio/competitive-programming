//NAME: B - Do you can see that?
//VERSION: O(N^2)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5; //double(10^3)
char input[MAXN][MAXN];//input
bool enemy[MAXN][MAXN];//true = vision of enemy
int n, m;//height and width

void fill_right(){
    for (int i = 0; i < n; i++){
        bool enemy_vision = false;//true = vision of enemy
        for(int j = 0; j < m; j ++){
            if(input[i][j] == '#'){
                enemy_vision = false;
            }else if(input[i][j] == 'R'){
                enemy_vision = true;
            }
            enemy[i][j] |= enemy_vision;  
        }
    }
}

void fill_left(){
    for (int i = 0; i < n; i++){
        bool enemy_vision = false;//true = vision of enemy
        for(int j = m - 1; j >= 0; j --){
            if(input[i][j] == '#'){
                enemy_vision = false;
            }else if(input[i][j] == 'L'){
                enemy_vision = true;
            }
            enemy[i][j] |= enemy_vision;  
        }
    }
}

void fill_down(){
    for (int j = 0; j < m; j++){
        bool enemy_vision = false;//true = vision of enemy
        for(int i = 0; i < n; i ++){
            if(input[i][j] == '#'){
                enemy_vision = false;
            }else if(input[i][j] == 'D'){
                enemy_vision = true;
            }
            enemy[i][j] |= enemy_vision;  
        }
    }
}

void fill_up(){
    for (int j = 0; j < m; j++){
        bool enemy_vision = false;//true = vision of enemy
        for(int i = n - 1; i >= 0; i --){
            if(input[i][j] == '#'){
                enemy_vision = false;
            }else if(input[i][j] == 'U'){
                enemy_vision = true;
            }
            enemy[i][j] |= enemy_vision;  
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++){
            cin >> input[i][j];
        }
    
    fill_right();
    fill_left();
    fill_down();
    fill_up();

    int nsol = 0;//number of solutions
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++)
            if(input[i][j] == '.' && !enemy[i][j])
                nsol++;

    if(nsol == 0)
        cout << "NO SOLUTION";
    else if(nsol == 1)
        cout << "ONLY ONE SOLUTION";
    else
        cout << "MULTIPLE SOLUTIONS";

    return 0;
}