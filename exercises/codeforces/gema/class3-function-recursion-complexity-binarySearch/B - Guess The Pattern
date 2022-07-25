#include <bits/stdc++.h>

using namespace std;

const int tamMax = 100;
long long arv[tamMax][tamMax];

int main(){
    int n, m;
    cin >> n >> m;
    
    //Leitura
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arv[i][j];
        }
    }
    
    //Lógica
    for(int j = 0; j < m; j++){
        bool p1, p2, p3;
        p1 = p2 = p3 = true;
        
        for(int i = 1; i < n; i++){
            p1 = p1 && arv[i][j] > arv[i-1][j];
            p2 = p2 && arv[i][j] < arv[i-1][j];
            p3 = p3 && arv[i][j] == arv[i-1][j];
        }
        
        if(p1 || p2 || p3)
            cout << 'S' << endl;
        else
            cout << 'N' << endl;
    }
    
    return 0;
}

/*
Só vamos usar vector<int> para quando for dinamico
*/
