#include <bits/stdc++.h>

using namespace std;

const int tamMax = 20;
int v[tamMax];
int n, x;

int soma_conjuntos(int pos, int soma){
    if(pos == n){
        return soma == x ? 1 : 0;
    }
    
    return soma_conjuntos(pos + 1, soma + v[pos]) + soma_conjuntos(pos + 1, soma);
}

int main (){
    cin >> n >> x;
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    cout << soma_conjuntos(0, 0);
    
    return 0;
}

/*
const int tamMax = 20;
int v[tamMax];
int n, x, qntConj = 0;

void soma_conjuntos(int pos, int soma){
    if(pos == n){
        qntConj += soma == x ? 1 : 0;
        return;
    }
    
    soma_conjuntos(pos + 1, soma + v[pos]);
    soma_conjuntos(pos + 1, soma);
}

int main (){
    cin >> n >> x;
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
        
    soma_conjuntos(0, 0);
    
    cout << qntConj;
    
    return 0;
}
*/
