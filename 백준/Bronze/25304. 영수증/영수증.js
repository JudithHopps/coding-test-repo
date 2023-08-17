const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n')
const total = Number(input[0])
let realTotal = 0
for (let i = 2;i<input.length;i++){
    const [price,count] = input[i].split(' ').map(Number)
    realTotal+=price*count
}

const answer = total===realTotal? "Yes" : "No"
console.log(answer)