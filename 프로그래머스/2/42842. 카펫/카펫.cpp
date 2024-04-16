#include <string>
#include <vector>

using namespace std;
int n, m;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int,int>> v;
    // 가로 >= 세로
    
    // brown = 가로 * 세로 - ((가로-2) * (세로 -2)); 
    // yellow = ((가로-2) * (세로 -2)); 
    
    // 너비 = brown + yellow; 
    int square = brown + yellow;
    
    for(int i=1;i<=brown;i++){
        for(int j=1;j<=i;j++){
            if(i*j==square){
                v.push_back({i,j});
            }
        }
    }
    
    
    for(auto it : v){
        if (yellow && it.first <= 2) continue;
        if(yellow != (it.first -2)*(it.second-2)) continue;
        if(brown != (it.first*it.second) - yellow) continue;
        n = it.first, m=it.second;
        break;
    }
    return answer = {n,m};
}