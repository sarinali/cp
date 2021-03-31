import java.io.*;
import java.util.*;

public class mwc15c2p2 {
	static ArrayList<Integer> ar;
	static int[] build;
	static Stack<Integer> s;
	static int nxt;
	static String out;
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String h = (br.readLine().replaceAll(" ", ""));
		ar = new ArrayList<Integer>(); build = new int[n];
		s = new Stack<Integer>();
		
		for (int i = n - 1; i >= 0; i--) {
			ar.add(Integer.parseInt(String.valueOf(h.charAt(i))));
			build[i] = 0;
		}
		s.push(ar.get(0));
		for (int i = 1; i < n; i++) {
			nxt = ar.get(i);
			if (!s.isEmpty()) {
				int elm = s.pop();
				while (elm <= nxt) {
					System.out.println(elm + " --> " + nxt);
					build[i] += 1;
					if (s.isEmpty()) {
						s.push(nxt);
						break;
					}
					elm = s.pop();
				}
				if (elm > nxt) {
					s.push(elm);
					build[i] += 1;
				}
			}
			s.push(nxt);
		}
		build[0] = 0;
		String out = "";
		//String test = Arrays.toString(build);
		for (int i = 0; i < n; i++) {
			out += String.valueOf(build[i]);
		}
		out = out.replaceAll("", " ");
		System.out.println(out.substring(1));
	}
}
