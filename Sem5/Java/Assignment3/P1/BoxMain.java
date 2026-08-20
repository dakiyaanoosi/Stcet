import java.util.Scanner;
class BoxMain {
	public static void main(String[] args) {
		Box ob = new Box();
		Scanner sc = new Scanner(System.in);

		int s, l, b, s1, s2, s3;

		while(true) {
			System.out.print("Find perimeter of\n1. Square\n2. Rectangle\n3. Triangle\n4. Exit\nEnter your choice: ");
			int ch = sc.nextInt();

			switch(ch) {
				case 1: System.out.print("Enter the side: ");
					s=sc.nextInt();
					System.out.println("Perimeter: "+ob.perimeter(s)+"\n");
					break;

				case 2: System.out.print("Enter the length & breadth: ");
					l = sc.nextInt();
					b = sc.nextInt();
					System.out.println("Perimeter: "+ob.perimeter(l, b)+"\n");
					break;

				case 3: System.out.print("Enter the 3 sides: ");
					s1 = sc.nextInt();
					s2 = sc.nextInt();
					s3 = sc.nextInt();
					System.out.println("Perimeter: "+ob.perimeter(s1, s2, s3)+"\n");
					break;

				case 4: return;
			
				default: System.out.println("Invalid Input!\n");
			}
		}

	}
}

