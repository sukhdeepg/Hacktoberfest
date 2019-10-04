const randomHexColorCode = () => {
  const n = (Math.random() * 0xfffff * 1000000).toString(16);
  return '#' + n.slice(0, 6);
};

console.log('Your hex color code is:', randomHexColorCode());
