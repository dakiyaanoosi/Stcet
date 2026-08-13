class BoxMain {
    public static void main(String[] args) {
        Box b1 = new Box(4, 5, 6);
	System.out.println("Volume 1 = "+b1.volume());

        Box b2 = new Box(3);
	System.out.println("Volume 2 = "+b2.volume());

    }
}
