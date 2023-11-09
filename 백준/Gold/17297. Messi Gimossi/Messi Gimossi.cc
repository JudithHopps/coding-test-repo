#include <bits/stdc++.h>
using namespace std;
const int n = 39;
vector<int> v = {0, 5, 13};
int m;
string s = "Messi Gimossi";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m;
  m--;

  for (int i = 3; i <= n; i++)
  {
    v.push_back(v[i - 1] + v[i - 2] + 1);
  }

  for (int i = n; i >= 2; i--)
  {
    if (m >= v[i])
      m -= (v[i] + 1);
  }

  if (m == -1 || m == 5)
  {
    cout << "Messi Messi Gimossi\n";
  }
  else
  {
    cout << s[m] << "\n";
  }

  return 0;
}