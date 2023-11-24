#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> s;
    mp[s] = i;
    mp2[i] = s;
  }

  for (int i = 0; i < m; i++)
  {
    cin >> s;
    if (atoi(s.c_str()))
    {
      cout << mp2[atoi(s.c_str())] << "\n";
    }
    else
    {
      cout << mp[s] << "\n";
    }
  }
  return 0;
}