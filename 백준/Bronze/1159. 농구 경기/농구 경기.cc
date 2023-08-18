#include <bits/stdc++.h>
#define fail "PREDAJA"

using namespace std;
int n, cnt[26];
string s,ret;


int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> s;
        cnt[s[0] - 'a']++;
    }
            
    for(int k=0;k<26;k++){
        if (cnt[k] >= 5) ret += (k + 'a');
    }
    if (ret.size()) cout << ret << endl;
    else cout << fail << endl;
    
        
    
    return 0;
}