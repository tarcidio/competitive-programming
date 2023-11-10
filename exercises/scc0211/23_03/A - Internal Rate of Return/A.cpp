#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double ERRO = 1e-3;
vector<int> cfs;
double f_npv(double arg) {
  int cfs_size = cfs.size();
  double res = cfs[cfs_size - 1];
  double x = arg;
  for (int i = cfs_size - 2; i >= 0; i--) {
    res += cfs[i] * x;
    x *= arg;
  }
  return res;
}

double bissection(double left, double right) {
  while (right - left > ERRO) {
    double center = (right + left) / 2;
    if (f_npv(left) * f_npv(center) <= 0) {
      right = center;
    } else {
      left = center;
    }
  }
  return (left + right) / 2;
}

void solve_find_irr() {
  double irr = bissection(0.0000001, 1000000) - 1;
  irr = round(irr * 100) / 100.0;

  cout << fixed << setprecision(2);
  cout << irr << endl;
}

int main() {
  int T;
  cin >> T;

  while (T) {
    // Reading
    T++;
    while (T--) {
      int cf;
      cin >> cf;
      cfs.push_back(cf);
    }
    // Algorithm
    solve_find_irr();

    // Next test
    cfs.clear();
    cin >> T;
  }

  return 0;
}
