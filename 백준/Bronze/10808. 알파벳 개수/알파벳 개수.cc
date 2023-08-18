#include <bits/stdc++.h>
using namespace std;

int a[26];
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    
    for (char c : s) {
        a[c - 'a']++;
    }
    
    for(int i : a) cout << i << " ";
    return 0;
}