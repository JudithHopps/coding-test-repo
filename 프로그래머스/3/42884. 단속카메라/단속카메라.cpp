#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0]; 
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int now = 30001; 
    //시작점 정렬은 차가 나가는 지점을 한번 더 확인해 주어야하는데 끝점 정렬로 하면 조건이 하나 줄어드네요
    sort(routes.begin(),routes.end(),cmp);
    
    for(auto it : routes){
        cout << it[0] <<" " << it[1] <<"\n";
        int s = it[0];
        int e = it[1];
        
        if(now <= e) continue;
        answer++;
        now = s; 
    }
    return answer;
}