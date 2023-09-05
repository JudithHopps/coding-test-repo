#include <bits/stdc++.h>
using namespace std;
int n, m, words[51];
string s;
int count(int mask)
{
  int cnt = 0;
  for (int word : words)
  {
    if (word && (word & mask) == word)
      cnt++;
  }
  return cnt;
}
int go(int index, int cnt, int mask)
{
  if (cnt > m)
    return 0;
  if (index == 26)
    return count(mask);
  int ret = go(index + 1, cnt + 1, mask | (1 << index));
  if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
  {
    ret = max(ret, go(index + 1, cnt, mask));
  }
  return ret;
}
int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (char str : s)
    {
      words[i] |= (1 << (str - 'a'));
    }
  }
  cout << go(0, 0, 0) << '\n';
  return 0;
}