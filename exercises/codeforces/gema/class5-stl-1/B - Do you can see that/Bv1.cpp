//NAME: B - Do you can see that?
//VERSION: O(N^3)
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;//height and width
    cin >> n >> m;

    char map[1001][1001];
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++)
            cin >> map[i][j];
    
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j ++){
            if(map[i][j] == 'R')//right
                for(int k = j; k < m && map[i][k] != '#'; k++)
                    map[i][k] = 'N';
            else if(map[i][j] == 'L')//left
                for(int k = j; k >= 0 && map[i][k] != '#'; k--)
                    map[i][k] = 'N';
            else if(map[i][j] == 'U')//up
                for(int k = i; k >= 0 && map[k][j] != '#'; k--)
                    map[k][j] = 'N';
            else if(map[i][j] == 'D')//down
                for(int k = i; k < n && map[k][j] != '#'; k++)
                    map[k][j] = 'N';
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