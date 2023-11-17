function solution(s) {
    let ret = s.length;
    
    for(let len = 1;len<=s.length/2;len++){
        let str = "", next = "";
        let cnt = 1;
        let cur = s.substr(0,len);
        // console.log(cur);
        let i;
        for(i=len;i<s.length-len+1;){
            next = s.substr(i,len);
            // console.log(next);
            if(cur == next) {
                // console.log("TT");
                cnt++;
            }
            else {
                if(cnt>1)str += cnt;
                str += cur;
                // console.log(str);
                cnt = 1, cur =next;
            }
            i+=len;
        }
        if(cnt>1) str+=cnt;
        str+= next + s.substr(i);
        
        // console.log(str);
        if(ret > str.length){
            ret = str.length;
        }
    }
    return ret;
}