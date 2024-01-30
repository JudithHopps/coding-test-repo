#include <bits/stdc++.h>
using namespace std;
int n, arr[104],m,a,b;


void goMan(int b){
    for(int i=1; i*b <= n; i++){
        arr[i*b] ^= 1;
    }
}

void goWo(int b){
    arr[b] ^= 1;
    for(int i=1; (b-i >= 1 && b+i <= n) ; i++ ){
        if(arr[b-i] != arr[b+i]) return;
        arr[b-i]  ^= 1;
        arr[b+i] ^= 1;
    }
}
int main() {

    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(a == 1) {
            goMan(b);
        }
        else {
            goWo(b);
        }
    }

    for(int i=1;i<=n;i++) {
        cout << arr[i] <<" ";
        if(i%(20) ==0) cout <<"\n";
    }
    return 0;
}

