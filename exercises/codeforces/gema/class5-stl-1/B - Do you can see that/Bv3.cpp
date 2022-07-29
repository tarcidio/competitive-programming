//NAME: B - Do you can see that?
//VERSION: O(N^2)
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;//height and width
    cin >> n >> m;

    char map[1001][1001];
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++){
            cin >> map[i][j];
        }
    
    bool aux_false = false;//aux_false = false: its not vision
    //right
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            if(map[i][j] == '#'){
                aux_false = false;
            }else if(map[i][j] == 'R' || aux_false){
                aux_false = true;
                map[i][j] = 'N';
            }
            
        }
        aux_false = false;
    }

    //left
    for (int i = 0; i < n; i++){
        for(int j = m - 1; j >= 0; j --){
            if(map[i][j] == '#'){
                aux_false = false;
            }else if(map[i][j] == 'L' || aux_false){
                aux_false = true;
                map[i][j] = 'N';
            }
        }
        aux_false = false;
    }

    //down
    for (int j = 0; j < m; j++){
        for(int i = 0; i < n; i ++){
            if(map[i][j] == '#'){
                aux_false = false;
            }else if(map[i][j] == 'D' || aux_false){
                aux_false = true;
                map[i][j] = 'N';
            }
        }
        aux_false = false;
    }

    //up
    for (int j = 0; j < m; j++){
        for(int i = n - 1; i >= 0; i --){
            if(map[i][j] == '#'){
                aux_false = false;
            }else if(map[i][j] == 'U' || aux_false){
                aux_false = true;
                map[i][j] = 'N';
            } 
        }
        aux_false = false;
    }

    int nsol = 0;//number of solutions
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++)
            if(map[i][j] == '.')
                nsol++;

    if(nsol == 0)
        cout << "NO SOLUTION";
    else if(nsol == 1)
        cout << "ONLY ONE SOLUTION";
    else
        cout << "MULTIPLE SOLUTIONS";

    return 0;
}