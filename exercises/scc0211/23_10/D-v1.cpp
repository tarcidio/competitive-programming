#include <bits/stdc++.h>

using namespace std;

int findMaxGCD(int *arr, int n) {
  int bigger = 0;
  for (int i = 0; i < n; i++)
    bigger = max(bigger, arr[i]);

  int *count_divisors = (int *)calloc((bigger + 1), sizeof(int));

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= sqrt(arr[i]); j++) {
      if (arr[i] % j == 0) {
        count_divisors[j]++;

        if (j != arr[i] / j)
          count_divisors[arr[i] / j]++;
      }
    }
  }

  for (int i = bigger; i >= 1; i--)
    if (count_divisors[i] > 1)
      return i;
}

int main() {
  int n;
  cin >> n;
  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << findMaxGCD(arr, n);
  return 0;
}
