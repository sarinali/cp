import java.util.*;
import java.io.*;
public class ds1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static long M = 100001;
    static int m, n;
    static long bit[], freq[], ar[];
    public static long sum(int start, int end) {
        long sum = 0; long sumstart = 0; long sumend = 0;
        while (start > 0) {
            sumstart += bit[start];
            start -= (start&-start);
        }
        while (end>0) {
            sumend += bit[end];
            end -= (end&-end);
        }
        sum = sumend - sumstart;
        return sum;
    }
    public static void freqc(long ind) {
        while (ind<=M) {
            freq[(int)ind]++;
            ind+=(ind&-ind);
        }
        return;
    }
    public static void change(int ind, long val) {
        long dif = val - ar[ind];
        long first = ar[ind];
        while (first <=M) {
            freq[(int)first]--;
            first+=first&-first;
        }
        ar[ind] = val;
        freqc(val);
        while (ind <= n) {
            bit[ind] +=dif;
            ind += ind&-ind;
        }
        return;
    }
    public static long freqcount(int ind) {
        long sum = 0;
        while (ind >0) {
            sum += freq[ind];
            ind-=ind&-ind;
        }
        return sum;
    }
    public static void main(String args[]) throws Exception{
        n = readInt(); m = readInt();
        bit = new long[n+1]; freq = new long[n+1];
        ar = new long[n+1];
        for (int i = 1; i <= n; i++) {
            ar[i] = readLong();
        }
        for (int i = 1; i <=n; i++) {
            int ind = i;
            while (ind <=n) {
                bit[ind] += ar[i];
            }
            long cur = ar[i];
            while (cur<=M){
            freq[(int)cur]++;
            cur += (cur&-cur);
            }
        }
        for (int i = 0; i < m; i++) {
            char cur; int x,y;
            cur = next().charAt(0);
            x = readInt();
            if (cur == 'S') {
                y = readInt();
                System.out.println(sum(x-1, y));
            } else if (cur == 'C') {
                y = readInt();
                change(x ,y);
            }else {
                System.out.println(freqcount(x));
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