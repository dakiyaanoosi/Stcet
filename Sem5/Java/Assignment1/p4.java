class p4 {
	public static void main(String args[]) {
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int c = Integer.parseInt(args[2]);

		if( a+b<=c || b+c<=a || a+c<=b ) {
			System.out.println("Invalid Triangle!");
			return;
		}

		System.out.println("Perimeter of the Triangle: "+(a+b+c));

		double S = (a+b+c)/2.0;	

		double A = Math.sqrt((S*(S-a)*(S-b)*(S-c)));

		System.out.printf("Area of the Triangle: %f\n", A);
	}
}