#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (vector<int> a, vector<int> b){
    if(a[0] != b[0]) return a[0] > b[0]; 
    return a[1] > b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int now = 30001; 
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