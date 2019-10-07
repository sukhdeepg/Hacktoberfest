import java.util.*;

public class SelectionSort {

    public SelectionSort() {
    }

    private int findSmallest(ArrayList<Integer> arr) {
        int smallest = arr.get(0);
        int smallest_index = 0;

        for (int i = 1; i < arr.size(); i++) {
         if (arr.get(i) < smallest) {
             smallest = arr.get(i);
             smallest_index = i;
         }
        }
        return smallest_index;
    }

    public ArrayList sort(ArrayList<Integer> arr) {
        ArrayList<Integer> newarr = new ArrayList<Integer>();
        int size = arr.size();
        int smallest = 0;

        for (int i = 0; i < size; i++) {
            smallest = this.findSmallest(arr);
            newarr.add(arr.get(smallest));
            arr.remove(smallest);
        }

        return newarr;
    }
}
