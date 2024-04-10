#include <bits/stdc++.h>
using namespace std;
int a, b, v, ret;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> v;

  ret++;
  v -= a;
  ret += ceil((double)v / (double)(a - b));
  cout << ret << "\n";

  return 0;
}