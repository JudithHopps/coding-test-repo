#include <string>
#include <vector>

using namespace std;
void hanoi_step(int n, char a, char b, char c, bool start, vector<vector<int>>& answer) {
    if (start) answer.clear();
  if (n) {
    hanoi_step(n-1, a, c, b, false, answer);
    answer.push_back({a, c});
    hanoi_step(n-1, b, a, c, false, answer);
  }
}
    
vector<vector<int> > hanoi(int no) {
  vector<vector<int>> answer;
  hanoi_step(no, 1, 2, 3, true, answer);
    return answer;
}
    
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    return hanoi(n);


}


