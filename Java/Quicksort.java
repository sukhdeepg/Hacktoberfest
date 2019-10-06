import java.util.Arrays;
import java.util.Random;

/*
 * This is my favorite sorting algorithm because it was one of the first
 * I learned at College
 */
public class Quicksort {
	
	public static void main(String[] args) {
		Random rand = new Random();
		int[] array = new int[rand.nextInt(16)];
		//filling the random array
		for(int i = 0; i < array.length; i++) {
			array[i] = rand.nextInt(100);	
		}
		System.out.println("Before sorting: " + Arrays.toString(array) );
		Quicksort.sort(array);
		System.out.println("After sorting: " + Arrays.toString(array));
	}
	
	
	public static void sort(int[] array) {
		sort(array, 0, array.length-1);
	}
	
	private static void sort(int[] array, int left, int right) {
		if(left < right) {
			int pivotPos = partition(array,left,right);
			sort(array, pivotPos+1, right);
			sort(array,left,pivotPos-1);
		}
	}
	
	private static int partition(int[] array, int left, int right) {
		int pivotIndex = (left+right)/2;
		swap(array,right, pivotIndex);
		int pivot = array[right];
	
		int i = left-1;
		int j = left;
		while(j <= right) {
			if(array[j] < pivot) {
				i++;
				swap(array,i,j);
			}
			j++;
		}
		
		swap(array, i+1, right);
		return i+1;
	}
	
	private static void swap(int array[],int i,int j) {
		int aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
	
}
