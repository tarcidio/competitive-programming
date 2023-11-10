#include <bits/stdc++.h>

using namespace std;

void binario_para_decimal(int numero, int TamNumero) {
  for (int pos_dig = TamNumero - 1; pos_dig >= 0; pos_dig--) {
    if (numero & (1 << pos_dig)) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
}

int conta_1s(int numero) {
  int cont = 0;
  while (numero > 0) {
    cont += numero & 1;
    numero >>= 1;
  }
  return cont;
}

void imprimirSolucao(int N, int H) {
  int num_max = 1 << N;
  for (int numero = 0; numero < num_max; numero++) {
    if (conta_1s(numero) == H) {
      binario_para_decimal(numero, N);
      cout << '\n';
    }
  }
}

int main() {
  int num_test;
  cin >> num_test;
  bool flag_impressao = false;
  while (num_test--) {
    int N, H;
    cin >> N >> H;
    if(flag_impressao){
      cout << endl;
    }
    flag_impressao = true;
    imprimirSolucao(N, H);
  }
  return 0;
}
