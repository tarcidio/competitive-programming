#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int max_gcd(int *arr, int n) {
  int result = 0;

  // Itera sobre todos os pares de elementos no array
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      result = max(result, gcd(arr[i], arr[j]));
    }
  }

  return result;
}

int main() {
  int n;
  cin >> n;
  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << max_gcd(arr, n);

  return 0;
}
