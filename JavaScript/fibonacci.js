const fibonacci = num => {
  const answer = [0, 1];
  for (let i = 2; i < num; i++) {
    answer.push(answer[i - 2] + answer[i - 1]);
  }
  return answer;
};
console.log(fibonacci(10));
console.log(fibonacci(20));
console.log(fibonacci(50));
