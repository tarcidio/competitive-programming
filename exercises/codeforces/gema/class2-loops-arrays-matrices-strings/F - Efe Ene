#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, k, aparicao = 0;
    cin >> n >> k;
    
    int ciclos = (n - 1)/4;
    int ultimo = (n - 1)%4;
    
    /*
    Fórmula pode ser escrita como f_n = 2^(n-1): descubra fazendo caso a caso
    A casa da unidade dos f_n se repetem em {2,4,8,6}
    */
    
    if(k == 1)
        aparicao = 1;
    else if(k == 2){
        aparicao = ciclos;
        aparicao += ultimo >= 1 ? 1 :0;
    } else if(k == 4){
        aparicao = ciclos;
        aparicao += ultimo >= 2 ? 1 :0;
    } else if(k == 8){
        aparicao = ciclos;
        aparicao += ultimo == 3 ? 1 :0;
    } else if(k == 6){
        aparicao = ciclos;
    }
     
    cout << aparicao;   
    
    return 0;
}
