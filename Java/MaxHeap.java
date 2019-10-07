public class MaxHeap{
    int[] arr;
    int size;
    MaxHeap(int[] items){
        arr = items;
        size = arr.length;
    }
    public void print(){
        for(int i=0;i<size;i++){
            System.out.println(arr[i]);
        }
        System.out.println();
    }
    public int get(int i){
        return arr[i];
    }
    public int parent(int i){
        return (i-1)/2;
    }
    public int left(int i){
        if((2*i+1)<size){
            return 2*i+1;
        }
        else{
            return -1;
        }
    }
    public int right(int i){
        if((2+i)+2<size){
            return 2*i+2;
        }
        else{
            return -1;
        }
    }
    public int checkAndReturn(int i){
        if(left(i)==-1){
            return i;
        }
        else if(right(i)==-1){
            if(arr[i]>arr[left(i)]){
                return i;
            }
            else{
                return left(i);
            }
        }
        else if(arr[i]>arr[right(i)]&&arr[i]>arr[left(i)]){
            return i;
        }
        else if(arr[i]>arr[right(i)] && arr[i]<arr[left(i)]){
            return left(i);
        }
        else if(arr[i]<arr[right(i)] && arr[i]>arr[left(i)]){
            return right(i);
        }    
        else if(arr[left(i)]>arr[right(i)]){
            return left(i);
        }
        else{
            return right(i);
        }
    }
    public void swap(int i, int k){
        int temp = arr[k];
        arr[k] = arr[i];
        arr[i] = temp;
    }
    public void fixHeap(int i){
       int k = checkAndReturn(i);
        if(i==k){
            return;
        }
        else{
            swap(i,k);
            fixHeap(k);
        }
    }
    public void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--){
            fixHeap(i); 
        }
    }
}