class BinarySearch {

  // Adding Binary Search because this is the first algorithm I learned!
  public static void binarySearch (int list[], int firstN, int lastN, int key ){

    int midN = (firstN + lastN) / 2;

    while(firstN <= lastN) {

      if (list[midN] < key) {
        firstN = midN + 1;
      }

      else if ( list[midN] == key ) {
        System.out.println("Element is found at index: " + midN); break;
      }

      else {
        lastN = midN -1;
      }

      if (firstN > lastN) {
        System.out.println("element not found");
      }

    } // end while

} // end binarySearch

  public static void main(String [] args){

    int[] searchArray = { 10,20,30,40,50,60,70,80,90,100 };
    int key = 50;
    int min = 0;
    int max = searchArray.length-1;
    binarySearch(searchArray, min, max, key);

} // end Main

} // end class
