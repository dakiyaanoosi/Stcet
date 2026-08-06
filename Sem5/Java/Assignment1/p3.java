import java.util.Scanner;

class p3 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a number: ");
		int n = sc.nextInt();

		boolean isPrime = true;

		if(n<=1) isPrime = false;

		for(int i=2; i<n; i++) {
			if(n%i == 0) {
				isPrime = false;
				break;
			}
		}

		if(isPrime) System.out.println(n+" is a Prime Number");
		else System.out.println(n+" is Not a Prime Number");

		sc.close();
	}
}