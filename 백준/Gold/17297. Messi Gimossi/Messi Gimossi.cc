#include <bits/stdc++.h>
using namespace std;
const int maxN = 39;
int f[maxN] = {0, 5, 13}, m;
string s = "Messi Gimossi";

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m;
  m--;

  for (int i = 3; i <= maxN; i++)
  {
    f[i] = f[i - 1] + f[i - 2] + 1;
  }

  for (int i = maxN; i >= 2; i--)
  {
    if (m >= f[i])
      m -= (f[i] + 1);
  }
  if (m == -1 || s[m] == ' ')
    cout << "Messi Messi Gimossi"
         << "\n";
  else
    cout << s[m] << "\n";

  return 0;
}