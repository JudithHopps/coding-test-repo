const input = Number(require('fs').readFileSync('/dev/stdin').toString())
const answer = []

for (let i=1;i<=input;i++){
    answer.push(" ".repeat(input-i) + "*".repeat(i))
}
console.log(answer.join('\n'))