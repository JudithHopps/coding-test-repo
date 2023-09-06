#include <bits/stdc++.h>
using namespace std;
int T, n, x;
string order, p;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--)
  {
    deque<int> D;
    cin >> p >> n >> order;
    x = 0;
    for (char c : order)
    {
      if (c == '[' || c == ']')
        continue;
      if (c >= '0' && c <= '9')
      {
        x = x * 10 + c - '0';
      }
      else
      {
        if (x > 0)
          D.push_back(x);
        x = 0;
      }
    }
    if (x > 0)
      D.push_back(x);

    bool error = false, rev = false;
    for (char a : p)
    {
      if (a == 'R')
        rev = !rev;
      else
      {
        if (D.empty())
        {
          error = true;
          break;
        }
        if (rev)
          D.pop_back();
        else
          D.pop_front();
      }
    }

    if (error)
      cout << "error"
           << "\n";
    else
    {
      if (rev)
        reverse(D.begin(), D.end());

      cout << "[";
      for (int i = 0; i < D.size(); i++)
      {
        cout << D[i];
        if (i < D.size() - 1)
          cout << ",";
      }
      cout << "]\n";
    }
  }

  return 0;
}