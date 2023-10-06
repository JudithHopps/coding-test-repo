#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    int start = 0;
    int end = query.size()-1;
    for(int i = 0; i < query.size(); i++){
        if(i%2 == 0){
            end = start + query[i]+1;
        }
        else{
            start += query[i];
        }
    }
    vector<int> answer(arr.begin()+start, arr.begin()+end);
    if(answer.empty())
        return {-1};
    return answer;
}
