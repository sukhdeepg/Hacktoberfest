function findNonRepetativeNumber(arr){
    let res;
    for(let i=0; i<arr.length; i+=1) {
      res = arr[i] ^ arr[i+1];
    }
    return res;
   };

let arr = [-1, 2, 5, 6, 2, 9, -1, 6, 5, -1, 3];

console.log(findNonRepetativeNumber(arr));
