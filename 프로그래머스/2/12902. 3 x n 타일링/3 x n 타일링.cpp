#include <string>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int solution(int n) {
    if(n%2 == 1) return 0; 
    
    ll dp [5004];
    dp[0] = 1; 
    dp[2] = 3; 
    
    for(int i=4;i<=n;i+=2){
        dp[i] = dp[i-2]*3;
        for(int j=0;j<=i-4;j+=2){
            dp[i] += dp[j]*2;
        }
        dp[i] = dp[i] % MOD;
    }
    
    return (int) dp[n];
}