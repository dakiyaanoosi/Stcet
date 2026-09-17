class Complex {
	double a, b;
	static int count = 0;
	Complex() {
		a=0;
		b=0;
		count++;
	}

	Complex(double r, double i) {
		a=r;
		b=i;
		count++;
	}

	static void countComplex() {
		System.out.println("Total complex numbers created: "+count);
	}

	void sum(Complex c) {
		double fr = a + c.a;
		double fi = b + c.b;
		System.out.printf("Sum: %+.2f%+.2fi\n", fr, fi);
	}

	void subtract(Complex c) {
		double fr = a - c.a;
		double fi = b - c.b;
		System.out.printf("Sum: %+.2f%+.2fi\n", fr, fi);
	}

	void product(Complex c) {
		double fr = (a*(c.a) - b*(c.b));
		double fi = (a*(c.b) + b*(c.a));
		System.out.printf("Sum: %+.2f%+.2fi\n", fr, fi);
	}

	public static void main(String []args) {
		Complex obj1 = new Complex(3, 4);
		Complex obj2 = new Complex(4, 5);
		obj1.product(obj2);
		countComplex();
	}
}
		