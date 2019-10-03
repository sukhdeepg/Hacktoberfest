import java.lang.*;
public class ArrayOutOfBound {

	public static void main(String[] args) {
		int []arr = new int[2];
		try {
			arr[0] = 0;
			arr[1] = 1;
			arr[2] = 2;
		}
		catch(ArrayIndexOutOfBoundsException ex) {
			System.out.println("Array Out of Bound");
		}
	}

}
