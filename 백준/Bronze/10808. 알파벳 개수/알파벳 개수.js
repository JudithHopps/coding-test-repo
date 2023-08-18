const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('')

let answer = new Array(26).fill(0)
for (const s of input) {
    const index = s.charCodeAt(0) - 'a'.charCodeAt(0)
    answer[index]++;
}

console.log(answer.join(' '))