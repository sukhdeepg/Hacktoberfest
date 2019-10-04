// Returns true if the distance between num1 and num2 is less than the difference argument

const approximatelyEqual = (num1, num2, difference = 0.5) => Math.abs(num1 - num2) < difference;

const result = approximatelyEqual(1, 1.1);

console.log('Approximatley equal is', result);
