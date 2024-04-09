#include <bits/stdc++.h>
using namespace std;
int n, ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  n--, ret++;
  int m = 6, cnt = 1;
  while (n > 0)
  {
    ret++;
    n -= m;
    m += 6;
  }

  cout << ret << "\n";
  return 0;
}