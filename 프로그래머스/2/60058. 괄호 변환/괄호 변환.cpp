#include <bits/stdc++.h> 
using namespace std;

bool check(string a){ 
    int cnt = 0; 
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '(') cnt++; 
        else cnt--; 
        if(cnt < 0) return false; 
    }
    return cnt == 0;
}
string go(string a){
    if(check(a)) return a;    
    int i, cnt1 = 0, cnt2 = 0; 
    for(i = 0; i < a.size(); i++){
        if(a[i] == '(') cnt1++; 
        else cnt2++; 
        if(cnt1 == cnt2) break;
    }
    string b = a.substr(0, i + 1); 
    string c = a.substr(i + 1, a.size() - (i + 1));   
    if(check(b)){ 
        return b + go(c); 
    }else{ 
        string ret = ""; 
        ret += '('; 
        ret += go(c); 
        ret += ')';  
        b = b.substr(1, b.size() - 2);  
        for(int i = 0; i < b.size(); i++){
            if(b[i] == ')') ret += '(';
            else ret += ')';
        }   
        return ret; 
    }  
}
string solution(string p) {
    string answer = go(p); 
    return answer;
}