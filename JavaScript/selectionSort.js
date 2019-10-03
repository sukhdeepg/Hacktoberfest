// Selection sort function in JS
function selection_sort(arr_lis, i) {
  if (i === 0) return arr_lis;
  const val_min = Math.min(...arr_lis.filter((x, j) => j < i));
  const index = arr_lis.findIndex(x => x === val_min);
  arr_lis.splice(index, 1);
  arr_lis.push(val_min);
  return selection_sort(arr_lis, --i);
}

// Driver Code
const unsortedArr = [52, 1920, 8871, 647, 910, 7712, 01, 90];
document.write('The sorted array is: ', selection_sort(unsortedArr , unsortedArr.length))
