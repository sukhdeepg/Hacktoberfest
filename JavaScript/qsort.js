
function quick_sort(array, left, right)
{
	if(left < right)
	{
		var middle=left;
		for(var i = left+1; i <=right; ++i)
			if(array[i]<array[left])
			{
				var temp = array[++middle];
				array[middle]=array[i];
				array[i]=temp;
			}
		var temp = array[left];
		array[left]=array[middle];
		array[middle]=temp;
		quick_sort(array,left,middle-1);
		quick_sort(array,middle+1,right);
	}
}

var array=[1,5,2,7,9,2,3,4,5];

console.log("unsorted: ", array);
quick_sort(array,0,array.length-1);
console.log("sorted: ", array);
