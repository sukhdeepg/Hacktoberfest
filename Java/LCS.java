
import java.util.Scanner;

class lcs {

    static char D = 'D', L = 'L', U = 'U';
    static String final_str = "";

    public static void main(String args[]) {
        Scanner read = new Scanner(System.in);
        String a, b;
        System.out.println("Enter String 1: ");
        a = read.next();
        System.out.println("Enter String 2: ");
        b = read.next();
        lcs(a, b);
        System.out.println(final_str);
    }

    static void lcs(String a, String b) {
        int m, n, i, j;
        m = a.length();
        n = b.length();
        int c[][] = new int[m + 1][n + 1];
        char z[][] = new char[m + 1][n + 1];
        c[0][0] = 0;
        for (i = 1; i <= m; i++) {
            c[i][0] = 0;
        }
        for (j = 1; j <= n; j++) {
            c[0][j] = 0;
        }
        char[] x = new char[a.length() + 1];
        x[0] = ' ';
        for (int q = 0; q < a.length(); q++) {
            x[q + 1] = a.charAt(q);
        }
        char[] y = new char[b.length() + 1];
        y[0] = ' ';
        for (int q = 0; q < b.length(); q++) {
            y[q + 1] = b.charAt(q);
        }

        for (i = 1; i <= m; i++) {
            for (j = 1; j <= n; j++) {
                if (x[i] == y[j]) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    z[i][j] = D;

                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    z[i][j] = U;
                } else {
                    c[i][j] = c[i][j - 1];
                    z[i][j] = L;
                }

            }

        }
        printLCS(z, x, x.length - 1, y.length - 1);

    }

    static void printLCS(char b[][], char[] x, int i, int j) {
    	
        if (i == 0 || j == 0) {
            return;
        }
        if (b[i][j] == D) {
            printLCS(b, x, i - 1, j - 1);
            final_str += x[i];
        } else if (b[i][j] == U) {
            printLCS(b, x, i - 1, j);
        } else {
            printLCS(b, x, i, j - 1);
        }
        
    }
}
