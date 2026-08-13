class Box {
	double length, width, height;
	Box() {
		length = 4;
		width = 5;
		height = 6;
	}
	Box(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}
	double volume() {
		return length*width*height;
	}
}