#include <bits/stdc++.h>
using namespace std;
string str;
int b;
long long ret;
map<char, int> mp;

void init()
{
  for (int i = 0; i < 10; i++)
  {
    mp[(char)('0' + i)] = i;
  }

  for (int i = 0; i <= 'Z' - 'A'; i++)
  {
    mp[(i + 'A')] = i + 10;
  }
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();

  cin >> str >> b;
  int now = 1;
  for (int i = str.size() - 1; i >= 0; i--)
  {
    ret += 1LL * mp[str[i]] * now;
    now *= b;
  }

  cout << ret << "\n";
  return 0;
}