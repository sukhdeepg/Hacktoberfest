import java.util.Scanner;

public class Pyramid {
	public static void main(String[] args) {
		Scanner scanner = new Scanner (System.in);
	  System.out.printf("Enter height of the pyramid: ");
		int number = Integer.parseInt(scanner.next());
		int decr = 1;
		while (decr <= number){
			int cols = number*2;
			int n= 0;
			while (n != ((cols/2)-(decr*2)) + decr){
				System.out.printf(" ");
				n++;
			}
			n = 0;
			System.out.printf(new String(new char[decr]).replace("\0", "[]"));
			while (n != ((cols/2)-(decr*2)) + decr){
				System.out.printf(" ");
				n++;
			}
			decr++;
			System.out.printf("\n");
		}
	}
}
