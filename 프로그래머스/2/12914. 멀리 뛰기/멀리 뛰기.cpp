#include <string>
#include <vector>

using namespace std;
const int MOD = 1234567;
long long dp[2004];

long long solution(int n) {
//     dp[0] = 1;
    
//     for(int i=1;i<=2;i++){
//         for(int j=i;j<=n;j++){
//             dp[j] += dp[j-i];
//             dp[j] %= MOD;
//         }
//     }
    
//     return dp[n];
    
    dp[1] = 1;
    dp[2] = 2; 
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}