#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int vet[1000];
int n,k;

/*
Função limite: determina se o valor mid_value é um bom valor
para considerar como sendo o limite máximo de distância a ser
percorrido em um único dia.
Entrada:
  @mid_value: candidato a limite
Retorno:
  @False: se faltar tempo para completar ou se algum elemento
  for maior que o próprio limite
  @True: quando sobrar tempo e todos os valores forem menor ou
  igual ao limite
*/
bool limite(int mid_value){
	int ac = 0;//Acumulator
	int k_aux = k;//K-aux
	for (int i = 0; i <= n; ++i){
		ac += vet[i];
		if (ac > mid_value){
			k_aux--;
			if (k_aux < 0 || vet[i] > mid_value)
				return false;
			ac = vet[i];
		}
	 } 
	return true;
}

/*

*/
int passeio(int zero, int total){
	int mid_value;
	bool result;
	while(total - zero >= 0) {
		mid_value = (zero+total)/2;
		result  = limite (mid_value);
		if (result) // andei demais.... sobraram noteis..
			total = mid_value-1;
		else 
      zero = mid_value+1;
	}
	return limite(zero) ? zero : total;
}

int main(int argc, char const *argv[]){
	
  while(cin >> n >> k){
    int sum = 0;
    for (int i = 0; i <= n; ++i){
  		cin >> vet[i];
  		sum += vet[i];
    }
    cout << passeio(0,sum) << endl;
  }
	
	return 0;
}