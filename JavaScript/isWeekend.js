const isWeekend = (date = new Date()) => {
  return date.getDay() % 6 === 0;
};

console.log(isWeekend());
