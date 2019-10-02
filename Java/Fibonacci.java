public class Fibonacci {

	public static int fibonacci(int n) {
		if (n <= 0) {
			return 0;
		} else if (n == 1) {
			return 1;
		} else {
			return fibonacci(n-1) + fibonacci(n-2);
		}
	}
	public static void main(String[] args) {
		// test
		System.out.println(fibonacci(4));
		System.out.println(fibonacci(12));
	}
}
