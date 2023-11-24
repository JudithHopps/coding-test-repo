#include <bits/stdc++.h>
using namespace std;
int a, n, k, psum[100004], ret = -987654321;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    cin >> a;
    psum[i + 1] = psum[i] + a;
  }

  for (int i = k; i <= n; i++)
  {
    ret = max(ret, psum[i] - psum[i - k]);
  }
  cout << ret << "\n";
  return 0;
}