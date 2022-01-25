#include <bits/stdc++.h>

using namespace std;
double f(double x, double a, double b, double c, double d) {
  return a * x * x * x + b * x * x + c * x + d;
}

double solve(double a, double b, double c, double d, double x0, double x1) {
  double xx[2] = {x0, x1};
  int flag = 0;
  while (abs(xx[0] - xx[1]) > 1e-4) {
    xx[flag] = xx[flag] -
               f(xx[flag], a, b, c, d) /
                   ((f(xx[flag], a, b, c, d) - f(xx[flag ^ 1], a, b, c, d))) *
                   (xx[flag] - xx[flag ^ 1]);
    flag ^= 1;
  }
  return xx[0];
}

double a, b, c, d, x[3] = {-1000, -1000, -1000};
int tot;

bool check(double xx) {
  bool flag = 0;
  for (int i = 0; i < 3; i++)
    flag |= abs(xx - x[i]) < 0.5;
  return !flag;
}

int main() {
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  for (double i = -100; i < 100; i += 0.5) {
    double xx = solve(a, b, c, d, i, i + 0.5);
    if (check(xx))
      x[tot++] = xx;
  }
  sort(x, x + 3);
  for (int i = 0; i < 3; i++)
    printf("%.2lf ", x[i]);
  return 0;
}