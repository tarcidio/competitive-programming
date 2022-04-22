/*
Creber e seu amigo Ediosvaldo caminhavam alegremente pela praia, nesse dia ensolarado. Ao caminharem na areia, notaram que haviam três números desenhados nela. 
Todos os dias a dupla de amigos ia na praia no mesmo horário e sempre avistavam três números desenhados no mesmo local. Eles começaram a se perguntar se havia 
alguma mensagem secreta por trás desses números misteriosos. Creber convenceu seu amigo de que apenas quando eles ordenassem os valores é que descobririam a verdade. 
Como Ediosvaldo e Creber não são muito bons com ordenação, eles decidiram pedir a você que resolva esse problema!

Dado três valores na entrada, imprima na saída os três valores ordenados de maneira decrescente (Para melhor entendimento do problema, olhem os casos de teste)

Input
Na entrada serão dados 3 valores inteiros, um por linha, indicando os números vistos por Creber e Ediosvaldo. Cada valor irá de -1000 até 1000

Output
A saída deve ser composta por 3 números inteiros, um por linha, os números dados na entrada ordenados decrescentemente.
*/

#include <iostream>
 
using namespace std;
 
int main (){
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a >= b && b >= c)
        cout << a << '\n' << b << '\n' << c;
    else if(a >= c && c >= b)
        cout << a << '\n' << c << '\n' << b;
    else if(b >= a && a >= c)
        cout << b << '\n' << a << '\n' << c;
    else if(b >= c && c >= a)
        cout << b << '\n' << c << '\n' << a;
    else if(c >= a && a >= b)
        cout << c << '\n' << a << '\n' << b;
    else if(c >= b && b >= a)
        cout << c << '\n' << b << '\n' << a;
    
    return 0;
}
