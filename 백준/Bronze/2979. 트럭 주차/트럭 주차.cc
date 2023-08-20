#include <bits/stdc++.h>
using namespace std;
int A,B,C,s,e,sum, a[104];

int main() {
    cin >> A>>B>>C;
    for(int i=0;i<3;i++){
        cin >> s >> e;
        for (int j=s;j<e;j++) a[j]++;
    }
    
    for (int i : a){
        sum += A * (i==1) + B*2*(i==2) + C*3*(i==3);
    }
    cout << sum << "";
    return 0;
}