#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  int s1_size = (int)s1.size();
  int s2_size = (int)s2.size();

  vvi memo(s1_size, vi(s2_size, 0));

  // Memoization
  for (int i = 1; i < s1_size; i++)
    for (int j = 1; j < s2_size; j++) {
      if (s1[i] == s2[j])
        memo[i][j] = memo[i - 1][j - 1] + 1;
      else {
        int poss1 = memo[i - 1][j];
        int poss2 = memo[i][j - 1];
        //Never consider poss3. Why? The answer is in the end
        //int poss3 = memo[i - 1][j - 1];
        memo[i][j] = max(poss1, poss2);
        //memo[i][j] = max(memo[i][j], poss3);
      }
    }

  // Walking in tree
  int index_s1 = s1_size - 1, index_s2 = s2_size - 1;
  string ans = "";
  while (index_s1 && index_s2) {
    if (s1[index_s1] == s2[index_s2]) {
      ans = s1[index_s1] + ans;
      index_s1--;
      index_s2--;
    } else {
      if (memo[index_s1 - 1][index_s2] > memo[index_s1][index_s2 - 1])
        index_s1--;
      else
        index_s2--;
    }
  }

  cout << ans << endl;

  return 0;
}
//if (memo[index_s1][index_s2] - 1 == memo[index_s1 - 1][index_s2 - 1]) isn't right because, by lucky, may be the same

/*The folow code is right too, because never will be lucky
if (memo[index_s1][index_s2] == memo[index_s1 - 1][index_s2])
        index_s1--;
      else if (memo[index_s1][index_s2] == memo[index_s1][index_s2 - 1])
        index_s2--;
*/

/*
No trecho mencionado do código do algoritmo LCS, não consideramos o dp[i - 1][j - 1] no else porque estamos procurando o maior valor entre dp[i - 1][j] (correspondente à exclusão do caractere atual de str1) e dp[i][j - 1] (correspondente à exclusão do caractere atual de str2).

Quando str1[i - 1] é diferente de str2[j - 1], isso significa que o caractere atual não é comum às duas strings. Portanto, precisamos decidir qual das duas opções é melhor: excluir o caractere str1[i - 1] ou excluir o caractere str2[j - 1].

Se incluíssemos o dp[i - 1][j - 1] na comparação do else, estaríamos considerando uma terceira opção: excluir tanto o caractere str1[i - 1] quanto o caractere str2[j - 1]. No entanto, isso não faria sentido no contexto do algoritmo LCS, pois o objetivo é encontrar a sequência comum mais longa entre as duas strings, não considerando a exclusão de caracteres de ambas as strings ao mesmo tempo.
*/