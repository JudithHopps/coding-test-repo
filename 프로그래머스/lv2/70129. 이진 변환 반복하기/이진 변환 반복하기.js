function solution(s) {
    let count = 0;
    let deleteCnt = 0;
    let str = s.slice()
    while (str.length !== 1) {
       let temp =  str.split('0').join('')
       count += 1
        deleteCnt +=  str.length - temp.length 
    
        str = (temp.length).toString(2)
    }
    return [count, deleteCnt]
}


// 베스트 답변
// function solution(s) {
//     var answer = [0,0];
//     while(s.length > 1) {
//         answer[0]++;
//         answer[1] += (s.match(/0/g)||[]).length;
//         s = s.replace(/0/g, '').length.toString(2);
//     }
//     return answer;
// }
