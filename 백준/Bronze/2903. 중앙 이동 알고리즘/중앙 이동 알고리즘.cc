#include <bits/stdc++.h>
using namespace std;
int n, ret;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  int m = (1 << (n)) + 1;

  // cout << m << "\n";
  cout << m * m << "\n";

  // cout << sqrt(1089) << "\n";
  return 0;
}