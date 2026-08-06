import java.util.*;

class p5 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the Temperature in Fahrenheit: ");
		double f = sc.nextDouble();

		double c = (f-32)*(5/9.0);

		System.out.println("Temperature in C: "+c);
		sc.close();
	}
}