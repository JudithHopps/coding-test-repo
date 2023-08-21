#include <bits/stdc++.h>
using namespace std;

string s, ret;
char mid;
int odd, cnt[100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  for (char c : s)
    cnt[(int)c]++;

  for (int i = 'Z'; i >= 'A'; i--)
  {
    if (cnt[i])
    {
      if (cnt[i] % 2)
      {
        mid = char(i);
        odd++;
        cnt[i]--;
        if (odd == 2)
        {
          cout << "I'm Sorry Hansoo\n";
          exit(0);
        }
      }

      for (int j = cnt[i]; j > 0; j -= 2)
      {
        ret = char(i) + ret + char(i);
      }
    }
  }

  if (mid)
  {

    ret.insert(ret.begin() + ret.size() / 2, mid);
  }
  cout << ret << "\n";
}
