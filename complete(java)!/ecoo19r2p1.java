import java.io.*;
import java.util.*;

public class ecoo19r2p1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int q, cnt;
    public static String check(String s) {
        String domain = ""; String pref = ""; int st = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '@') {
                st = i;
                break;
            }
        }
        for (int i = st; i < s.length(); i++) {
            domain += Character.toLowerCase(s.charAt(i));
        }
        for (int i = 0; i < st; i++) {
            if (s.charAt(i) == '.') {
                continue;
            } else if (s.charAt(i) == '+') {
                break;
            }
            pref += Character.toLowerCase(s.charAt(i));
        }
        // System.out.println(pref+domain);
        return pref+domain;
    }
    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 10; i++) {
            HashMap<String, Integer> m = new HashMap<String, Integer>();
            q = readInt();
            cnt =0;
            for (int j = 0; j < q; j++) {
                String s, k;
                s = readLine();
                k = check(s);
                // System.out.println(k);
                if (m.containsKey(k)) {
                    continue;
                } else {
                    // System.out.println(k);
                    cnt++;
                    m.put(k, 1);
                }
            }
            System.out.println(cnt);
        }
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}