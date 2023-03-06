/*
Dado um tabuleiro de Xadrez com N de largura e M de comprimento, imprima o número de casas pretas no tabuleiro.

Considere que a casa no canto superior esquerdo sempre é preta.

Input
O input terá dois números inteiros N e M (1 ≤ N ≤ 105, M ≤ 104), as dimensões do tabuleiro.

Output
Imprima o número de casas pretas.
*/

#include <iostream>
 
using namespace std;
 
int main(){
    
    int n, m, qnt;
    cin >> n >> m;
    
    if(n%2 == 0){
        cout << m*n/2;
    } else { 
        cout << (n*m + 1)/2;
    }
    
    return 0;
}
