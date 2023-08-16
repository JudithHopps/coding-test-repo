const i = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number)
const [A,B,C] = i
const arr = [ (A+B)%C,  ((A%C) + (B%C))%C, (A*B)%C,  ((A%C) * (B%C))%C]

console.log(arr.join('\n'))