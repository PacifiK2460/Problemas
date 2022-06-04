#include <iostream>
using namespace std;

int main() {
  unsigned long n, current = 0, i = 0, total = 0;
  cin >> n;
  double *x = (double *)malloc(n * sizeof(double));
  double *y = (double *)malloc(n * sizeof(double));

  for (; i < n; i++) {
    cin >> x[i] >> y[i];
    if (current != i) {
      total += abs(x[current] - x[i]) + abs(y[current] - y[i]);
    }
  }
  current++;
  for (; current < n - 1; current++) {
    total +=
        abs(x[current] - x[current + 1]) + abs(y[current] - y[current + 1]);
  }
  printf("%lu", total%1000000007);
}