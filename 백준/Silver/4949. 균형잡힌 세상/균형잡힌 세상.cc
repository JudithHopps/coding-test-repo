#include <bits/stdc++.h>
using namespace std;
string str, ret;
string ok = "yes";
string no = "no";

bool ch(string a)
{
  stack<char> st;
  for (char c : a)
  {
    if (c == '(')
      st.push(c);
    if (c == ')')
    {
      if (st.empty() || st.top() != '(')
        return false;
      st.pop();
    }

    if (c == '[')
      st.push(c);
    if (c == ']')
    {
      if (st.empty() || st.top() != '[')
        return false;
      st.pop();
    }
  }
  return st.empty();
}
int main()
{
  while (true)
  {
    getline(cin, str);
    if (str == ".")
      break;
    ret = ch(str) ? ok : no;
    cout << ret << "\n";
  }

  return 0;
}