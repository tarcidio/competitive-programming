//NOME: A - CISC Elevator

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, h;//numero de andares percorridos e qnt de andares no predio
    cin >> n >> h;

    int rel[100001];//relatorio de andares
    for(int i = 0; i < n; i++)
        cin >> rel[i];

    int tandares = 0;//total de andares
    for(int i = 1; i < n; i++)
        tandares += abs(rel[i] - rel[i-1]);

    cout << tandares * 4 << endl;

    return 0;
}
