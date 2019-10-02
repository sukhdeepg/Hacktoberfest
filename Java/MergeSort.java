public class MergeSort{
    public void merge(int[] arr, int left, int mid, int right){
        int size1 = mid - left + 1;
        int size2 = right - mid;
        int tempLeft[] = new int[size1];
        int tempRight[] = new int[size2];

        for (int i=0; i<size1; ++i)
            tempLeft[i] = arr[left + i];
        for (int j=0; j<size2; ++j)
            tempRight[j] = arr[mid + j + 1];

        int leftIndex = 0;
        int rightIndex = 0;
        int mergedIndex = left;

        while (leftIndex < size1 && rightIndex < size2) {
            if (tempLeft[leftIndex] <= tempRight[rightIndex]) {
                arr[mergedIndex] = tempLeft[leftIndex];
                leftIndex++;
            } else {
                arr[mergedIndex] = tempRight[rightIndex];
                rightIndex++;
            }
            mergedIndex++;
        }

        while (leftIndex < size1) {
            arr[mergedIndex] = tempLeft[leftIndex];
            leftIndex++;
            mergedIndex++;
        }

        while (rightIndex < size2) {
            arr[mergedIndex] = tempRight[rightIndex];
            rightIndex++;
            mergedIndex++;
        }
    }
    public void mergeSort(int[] arr, int left, int right){
        if (left < right){
            int mid = (left + right)/2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);

            merge(arr, left, mid, right);
        }
    }
}
