#include <bits/stdc++.h>
using namespace std;
int n;
string ok = "YES";
string no = "NO";
string str;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while (n)
  {
    string ret = "";
    int l = 0, r = 0;
    cin >> str;
    for (char c : str)
    {
      c == '(' ? l++ : r++;
      if (l < r)
      {
        ret = no;
        break;
      }
    }

    ret = l == r ? ok : no;
    cout << ret << "\n";
    n--;
  }

  return 0;
}