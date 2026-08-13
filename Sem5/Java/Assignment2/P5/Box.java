class Box {
	double length, width, height;
	Box(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}
	Box(double l) {
		length = l;
		width = l;
		height = l;
	}
	double volume() {
		return length*width*height;
	}
}