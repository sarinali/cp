import java.util.*;

public class coin10 {
	static int n; 
	static int ar[];
	static int v;
	static int denom[];
	public static void main(String args[]) throws Exception{
		Scanner sc = new Scanner(System.in);
		v = sc.nextInt(); n = sc.nextInt();
		 ar = new int[v];
		 denom = new int[n+1]; Arrays.fill(denom, n+1);
		 denom[0] = 0;
		 for (int i = 0; i < v; i++) {
			 ar[i] = sc.nextInt();
		 }
		 for (int i = 1; i <= n; i++) {
			 for (int j = 0; j < v; j++) {
				 if (ar[j] <= i) {
					 denom[i] = Math.min(denom[i], denom[i - ar[j]] + 1);
				 }
			 }
		 }
		 int x = denom[n];
		 System.out.println(x);
		 sc.close();
	 }
}
