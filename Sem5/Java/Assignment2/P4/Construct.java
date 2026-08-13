class Construct {
	int a, b, c;
	Construct() {
		a=0;
		b=0;
		c=0;
	}
	
	Construct(int a, int b, int c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	void display() {
		System.out.printf("a = %d\nb = %d\nc = %d\n", a, b, c);
	}
}