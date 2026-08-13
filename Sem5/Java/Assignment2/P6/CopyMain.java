class CopyMain {

	static boolean isSame(Copy obj1, Copy obj2) {
		return (obj1.length == obj2.length && obj1.breadth == obj2.breadth);
	}	

	public static void main(String[] args) {
		Copy obj1 = new Copy(1, 2);
		Copy obj2 = new Copy(3, 4);
		Copy obj3 = new Copy(1, 2);

		if(isSame(obj1, obj2))
			System.out.println("Obj1 & Obj2 have Equal Dimensions");
		if(isSame(obj1, obj3))
			System.out.println("Obj1 & Obj3 have Equal Dimensions");
		if(isSame(obj2, obj3))
			System.out.println("Obj2 & Obj3 have Equal Dimensions");
	}
}
		