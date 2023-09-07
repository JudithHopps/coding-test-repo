#include <bits/stdc++.h>
using namespace std;
string str, del, ret;
stack<char> st;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str >> del;

  for (char c : str)
  {
    st.push(c);
    if (st.size() >= del.size() && st.top() == del[del.size() - 1])
    {
      string ss = "";
      for (char d : del)
      {
        ss += st.top();
        st.pop();
      }
      reverse(ss.begin(), ss.end());
      if (ss != del)
      {
        for (char s : ss)
        {
          st.push(s);
        }
      }
    }
  }

  if (st.size() == 0)
  {
    cout << "FRULA"
         << "\n";
  }
  else
  {
    while (st.size())
    {
      ret += st.top();
      st.pop();
    }
    reverse(ret.begin(), ret.end());
    cout << ret << "\n";
  }
  return 0;
}