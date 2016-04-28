function Partition(arr, left, right){
	var pivot = left;
	var value = arr[pivot];

	do{		
		do{ }while( arr[++left] < value )
		do{ }while( arr[--right] > value )
		if( left < right ){
			var temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}else{	break;	}
	}while(true)

	arr[pivot] = arr[right];
	arr[right] = value;

	return right;
}

function QuickSort(arr, left, right){
	var mid;
	if( left < right ){
		mid = Partition(arr,left, right+1);
		QuickSort(arr, left, mid-1);
		QuickSort(arr, mid+1, right);
	}
}

var arr = [1,5,3,5,2,3,5,2,3,5,3];

QuickSort(arr, 0, arr.length-1);

console.log(arr);