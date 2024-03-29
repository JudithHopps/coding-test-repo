#include <string>
#include <vector>
#include <cstring> 

using namespace std;
int dp[100004];

int f(int n){
    if(n<=1) return n;
    
    if(dp[n] != -1 ) return dp[n];
    
    dp[n] = (f(n-1) + f(n-2)) % 1234567;
    return dp[n];
}
int solution(int n) {
    memset(dp,-1,sizeof(dp));
    int answer = f(n);
    return answer;
}