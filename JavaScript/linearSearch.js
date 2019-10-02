function linearSearch(arrayList, toFind) {
    index = -1;
    arrayList.forEach((item, i) => {
        if (item === toFind) {
            index = i;
        };
    });
    return index;
}

// var arr = ['tuna', 'ham', 'turkey', 'pb&j'];
// var toFind = 'nun';

var arr = [1, 3, 5, 7, 8, 9];
var toFind = 5;

index = linearSearch(arr, toFind)

console.log("List: ", arr);
if (index == -1) {
    console.log("Item: ", toFind);
    console.log("Not Found");
} else {
    console.log("Item: ", toFind);
    console.log("Index: ", index);
}
