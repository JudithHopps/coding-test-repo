function solution(s){
    const stack = []
    for (let i = 0 ; i < s.length; i++) {
        const r = s[i]
        if (r ==="(") stack.push(r)
        else if (r===")" && stack.length) {
            stack.pop()
        }
        else {
            return false
        }
    }
    return stack.length ? false : true
}