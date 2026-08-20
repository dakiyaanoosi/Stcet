class ConstructMain {
	public static void main(String[] args) {
		Construct obj1 = new Construct();
		System.out.println("Default Constructor\n");
		obj1.display();
		
		Construct obj2 = new Construct(1, 2, 3);
		System.out.println("Parameterized Constructor\n");
		obj2.display();
	}
}