#include <bits/stdc++.h>
using namespace std;
int n, ret;
string str;
stack<int> st;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  st.push(-1);

  cin >> n >> str;
  for (int i = 0; i < n; i++)
  {
    if (str[i] == '(')
    {
      st.push(i);
    }
    else
    {
      st.pop();
      if (!st.empty())
      {
        ret = max(ret, i - st.top());
      }
      else
      {
        st.push(i);
      }
    }
  }

  cout << ret << "\n";

  return 0;
}