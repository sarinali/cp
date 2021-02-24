import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class coin10 {
	static int n; 
	static int ar[];
	static int v;
	static int denom[];
	public static void main(String args[]) throws Exception{
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 n = Integer.parseInt(br.readLine());
		 v = Integer.parseInt(br.readLine());
		 ar = new int[v];
		 denom = new int[n+1]; Arrays.fill(denom, n+1);
		 denom[0] = 0;
		 for (int i = 0; i < v; i++) {
			 ar[i] = Integer.parseInt(br.readLine());
		 }
		 for (int i = 1; i <= n; i++) {
			 for (int j = 0; j < v; j++) {
				 if (ar[j] <= i) {
					 denom[i] = Math.min(denom[i], denom[i - ar[j]] + 1);
				 }
			 }
		 }
		 int x = denom[n];
		 if (x == n+1) {
			 System.out.println("Roberta acknowledges defeat.");
		 }else {
			 System.out.println("Roberta wins in " + x + " strokes.");
		 }
	 }
}
