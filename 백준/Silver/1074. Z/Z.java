

import java.util.Scanner;

public class Main {
	public static int solve(int N, int r, int c, int cnt) {
		if(N<=2) {
			if(r==0 && c==0) return cnt;
			if(r==0 && c==1) return cnt+1;
			if(r==1 && c==0) return cnt+2;
			if(r==1 && c==1) return cnt+3;
		}
		
		int mid = N/2; //2
		
		if(r<mid && c<mid) return solve(mid, r, c, cnt);
		if(r<mid && c>=mid) return solve(mid, r, c-mid, cnt+mid*mid);
		if(r>=mid && c<mid) return solve(mid, r-mid, c, cnt+2*mid*mid);
		//if(r>=mid && c>=mid)
		return solve(mid, r-mid, c-mid, cnt+3*mid*mid);
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N, r, c;
		N = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();
		
		System.out.println(solve(2<<N, r, c, 0));
		sc.close();
	}

}
