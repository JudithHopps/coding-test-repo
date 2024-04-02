const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (input) => {
  console.log(input); // 입력받은 내용을 그대로 출력
});

rl.on('close', () => {
  process.exit(0); // 프로그램 종료
});
