#include <bits/stdc++.h>
using namespace std;
string str,temp;

int main() {
    
    cin >> str;
    temp = str;
    reverse(temp.begin(),temp.end());
    cout << (str==temp) << "";
   
    return 0;
}