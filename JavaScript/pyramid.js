function pyramid(level){
  for(let i=1;i<=level; i+=1){
    let emptySpace = ' '.repeat(level - i);
    let charcterSpace = '#'.repeat(i * 2 - 1);
    
    console.log(emptyspace + characterSpace + emptySpace);
  }
}
