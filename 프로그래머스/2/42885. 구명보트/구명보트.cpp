#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int cnt = 0;
    int l=0,r=people.size()-1;
    
    while(l<=r){
        if(people[l] + people[r] <= limit){
            l++,r--;
            cnt++;
        } else {
            r--;cnt++;
        }
    }
    return cnt;
}