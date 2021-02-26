import java.util.*;
public class vmss7wc16c2p2java {
    static int n;
    static int gc;
    static int psa[];
    static String g;
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        g = sc.nextLine();
        gc = 0; psa = new int[g.length()];
        for (int i = 0; i < g.length(); i++) {
            psa[i] = 0; 
            if (g.charAt(i) == 'G'){
                gc++;
            }
            psa[i] = gc;
        }
        n = sc.nextInt();
        for (int i = 0 ; i < n; i++) {
            int x = sc.nextInt(); int y = sc.nextInt();
            int ans = 0;
            if (x == 0) {
                System.out.println(psa[y]);
            }else {
                System.out.println(psa[y] - psa[x-1]);
            }
        }
    }
}
