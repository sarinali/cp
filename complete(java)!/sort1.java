import java.io.*;
import java.util.StringTokenizer;
public class sort1 {
    static int ar[];
    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        n = readInt();
        ar = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = readInt();
        }
        for (int g = 0; g < ar.length; g++) {
            System.out.print(ar[g] + " ");
        }
        System.out.println();
        for (int i = 0; i < ar.length; i++) {
            for (int j = 0; j < ar.length-1-i; j++) {
                if (ar[j] > ar[j+1]) {
                    int temp = ar[j+1];
                    ar[j+1] = ar[j];
                    ar[j] = temp;
                    for (int g = 0; g < ar.length; g++) {
                        System.out.print(ar[g] + " ");
                    }
                    System.out.println();
                }
//                System.out.print(ar[j] + " ");
            }
        }
    }
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}