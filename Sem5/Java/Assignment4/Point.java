class Point {
	double x, y;
	
	Point() {
		x=0.0;
		y=0.0;
	}
	
	Point(Double x, Double y) {
		this.x=x;
		this.y=y;
	}

	static void calculateDistance(Point p1, Point p2) {
		Double dist = Math.sqrt(Math.pow((p2.x - p1.x), 2) + Math.pow((p2.y - p1.y), 2));
		System.out.printf("Distance: %.2f\n", dist);
	}

	public static void main(String[] args) {
		Point obj1 = new Point(2.0, 4.0);
		Point obj2 = new Point(8.0, 2.0);
		calculateDistance(obj1, obj2);
	}
}