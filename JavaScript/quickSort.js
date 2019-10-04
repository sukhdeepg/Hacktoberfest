const oldArray = [23, -8, 3, 0, 14, -18, -5, 7, 16, 9];

const quickSort = (oldArray) => {
    if (oldArray.length <= 1) {
        return oldArray;
    } else {
        let left = [];
        let right = [];
        let sortedArray = [];
        let pivot = oldArray.pop();
        let length = oldArray.length;

        for (let i = 0; i < length; i++) {
            if (oldArray[i] <= pivot) {
                left.push(oldArray[i]);
            } else {
                right.push(oldArray[i]);
            }
        }
        return sortedArray.concat(quickSort(left), pivot, quickSort(right));
    }
};

console.log('Old Array: ' + oldArray);
const newArray = quickSort(oldArray);
console.log('Sorted Array: ' + newArray);
