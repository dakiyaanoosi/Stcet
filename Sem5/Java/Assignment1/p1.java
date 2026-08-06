import java.util.*;

class p1 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter 1st number: ");
		int a = sc.nextInt();
		System.out.print("Enter 2nd number: ");
		int b = sc.nextInt();
		
		System.out.printf("Sum: %d\nDifference: %d\nProduct: %d\n", a+b, a-b, a*b);
		sc.close();
	}
} 