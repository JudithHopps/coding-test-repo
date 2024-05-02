#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// h번 이상 인용된 논문이 h편 이상이고
// 나머지 논문이 h번 이하 인용되었다면 h의 최댓값
int solution(vector<int> citations) {
    int answer = 0;
    int mx = 0;
    int mn = 10004;
    
    for(int c : citations){
        mx = max(mx,c);
        mn = min(mn,c);
    }
    sort(citations.rbegin(),citations.rend());
    
    int big[1004];
    int small[1004];
    for(int c=mx;c>=0;c--){
        int sm = 0 ;
        int big = 0; 
        for(int now : citations){
            if(c>=now) sm++;
            if(c<=now)big++;
        }
        if(sm<=c && big>=c){
            answer = c; break;
        }
    }
    
    return answer;
}