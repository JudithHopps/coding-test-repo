const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number)

const sum = input.reduce((a,b)=>a+b,0)
const set = new Set()

const fn = () => {
    for (let i = 0; i<input.length;i++){
        for (let j = i+1;j<input.length;j++){
            if(sum - input[i] - input[j] == 100) {
                set.add(input[i]); 
                set.add(input[j]);
                return 0
            }
        }
}
}
fn()

const answer = input.filter(v=>!set.has(v)).sort((a,b)=>a-b)
console.log(answer.join('\n'));
