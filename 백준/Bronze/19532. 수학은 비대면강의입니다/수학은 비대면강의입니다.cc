#include <iostream>
using namespace std;
int a,b,c,d,e,f,x,y;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a>> b>> c>> d>> e>>f;

    int flag = 0;
    for(int i=-999;i<=999;i++){
        for(int j=-999;j<=999;j++){
            if( a * i + b * j != c) continue;
            if(d * i + e * j != f) continue;
            x= i, y=j;
            flag = 1;
            break;
        }
        if(flag) break;
    }
   cout << x << " "<< y <<"\n";
    return 0;
}