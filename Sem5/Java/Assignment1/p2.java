import java.util.*;

class p2 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int m = sc.nextInt();
		System.out.print("Enter a string: ");
		sc.nextLine();
		String s = sc.nextLine();
		
		for(int i=0; i<m; i++) {
			System.out.println(s);
		}
		sc.close();
	}
}