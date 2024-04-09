#include <bits/stdc++.h>
using namespace std;
string ret;
int b;
long long N;
map<int, char> mp;

void init()
{
  for (int i = 0; i < 10; i++)
  {
    mp[i] = (char)('0' + i);
  }

  for (int i = 0; i <= 'Z' - 'A'; i++)
  {
    mp[i + 10] = (i + 'A');
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  init();

  cin >> N >> b;

  while (N)
  {
    ret += mp[(N % (b * 1LL))];
    N /= (b * 1LL);
  }

  reverse(ret.begin(), ret.end());

  cout << ret << "\n";
  return 0;
}