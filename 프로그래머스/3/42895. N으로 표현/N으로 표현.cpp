#include <string>
#include <vector>
#include <iostream>
#include <unordered_set> 
using namespace std;
unordered_set<int> us[10];
int n;

int solution(int N, int number) {
    n = number;
    int now = 0;
    
    for(int i=1;i<=8;i++){
        now = now*10 + 5;
        us[i].insert(now);


        for(int j=1;j < i;j++){
                for(int a : us[j]){
                    for(int b : us[i-j]){
                        vector<int> temp = {a+b,a-b,a*b};
                        if(b!= 0) temp.push_back(a/b); 


                        for(int t : temp){
                            us[i].insert(t);
                        }
                    }
                }
            }

        if(us[i].find(number) != us[i].end()) return i;
    }


    return -1;

}