function solution(str)
{
    let stack = []
    
    for (let s of str) {
        if (stack[stack.length-1] === s) {
            stack.pop()
        }
        else {
            stack.push(s)
        }
    }
    return stack.length ? 0 : 1
}