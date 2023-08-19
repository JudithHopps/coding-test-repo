#include <bits/stdc++.h>
using namespace std;
int n;
string str, s,pre,suf;

int main()
{
  cin >> n;
  cin >> str;
  int pos = str.find('*');
  
    pre = str.substr(0,pos);
    suf = str.substr(pos+1);
    
  
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (pre.size()+suf.size() > s.size()) {
      cout << "NE\n";
    } else {
        if (pre== s.substr(0,pre.size()) && suf == s.substr(s.size()-suf.size())) cout << "DA\n";
        else cout << "NE\n";
    }
      
    
  }
  return 0;
}