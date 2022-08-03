//NAME: B - Do you can see that?
//VERSION: O(N^3)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5; //double(10^3)
char input[MAXN][MAXN];//input
bool enemy[MAXN][MAXN];//true = vision of enemy
int n, m;//height and width

void fill_line(int i, int j, int dx){
    while(j >= 0 && j < m && input[i][j] != '#'){
        enemy[i][j] = true;
        j += dx;
    }
}

void fill_column(int i, int j, int dy){
    while(i >= 0 && i < n && input[i][j] != '#'){
        enemy[i][j] = true;
        i += dy;
    }
}

int main(){  
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++)
            cin >> input[i][j];
    
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++){
            if(input[i][j] == 'R')//right
                fill_line(i, j, 1);
            else if(input[i][j] == 'L')//left
                fill_line(i, j, -1);
            else if(input[i][j] == 'U')//up
                fill_column(i, j, -1);
            else if(input[i][j] == 'D')//down
                fill_column(i, j, 1);
        }
    
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