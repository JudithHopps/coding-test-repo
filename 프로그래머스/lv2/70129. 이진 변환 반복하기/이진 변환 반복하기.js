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