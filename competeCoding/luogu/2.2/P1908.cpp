#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ans;
int n;
int a[500005], c[500005];

void msort(int b, int e) {
  if (b == e)
    return;
  int mid = b + (e - b) / 2, i = b;
  int j = mid + 1, k = b;
  msort(b, mid), msort(mid + 1, e);
  while (i <= mid && j <= e) {
    if (a[i] <= a[j])
      c[k++] = a[i++];
    else
      c[k++] = a[j++], ans += mid - i + 1;
  }
  while (i <= mid)
    c[k++] = a[i++];
  while (j <= e)
    c[k++] = a[j++];
  for (int l = b; l <= e; l++)
    a[l] = c[l];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  msort(1, n);
  cout << ans;

  return 0;
}