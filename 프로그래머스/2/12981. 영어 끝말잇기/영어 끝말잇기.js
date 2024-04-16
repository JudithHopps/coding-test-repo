function solution(n, words) {
    let idx =0, cnt=0;
    const mp = new Map();
    let pre = "";
    
    for(let i=0;i<words.length;i++){
        if (words[i].length==1){
            idx = (i % n) + 1;
            cnt = parseInt(i / n) + 1;
            break;
        } 
        
        if(i > 0 && pre[pre.length-1] != words[i][0]){
            idx = (i % n) + 1;
            cnt = parseInt(i / n)+1;
            break;
        }
        if (i > 0 && mp[words[i]]){
            idx = (i % n) + 1;
            cnt = parseInt(i / n)+1;
            break;
        }
        
        pre = words[i];
        mp[pre] = (mp[pre] ? mp[pre] + 1 : 1) ;
    }
    return [idx,cnt];
}