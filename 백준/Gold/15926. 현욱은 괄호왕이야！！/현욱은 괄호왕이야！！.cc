#include <bits/stdc++.h>
using namespace std;
int n, ret, a[200004];

string str;
stack<int> st;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> str;
  for (int i = 0; i < n; i++)
  {
    if (str[i] == '(')
    {
      st.push(i);
    }
    else
    {
      if (st.size() > 0)
      {
        int j = st.top();
        st.pop();
        a[i] = a[j] = 1;
      }
    }
  }

  int cur = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1)
    {
      cur++;
    }
    else
    {
      ret = max(ret, cur);
      cur = 0;
    }
  }
  ret = max(ret, cur);

  cout << ret << "\n";

  return 0;
}