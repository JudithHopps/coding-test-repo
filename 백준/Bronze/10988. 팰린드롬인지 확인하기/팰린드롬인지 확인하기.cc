#include <bits/stdc++.h>
using namespace std;
string str,temp;

int main() {
    
    cin >> str;
    temp = str;
    reverse(temp.begin(),temp.end());
    
    if(temp == str) cout << 1 << "\n";
    else cout << 0 << "\n";
        
    return 0;
}