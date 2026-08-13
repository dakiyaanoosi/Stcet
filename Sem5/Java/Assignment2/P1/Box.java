class Box {
	double length, width, height;
	void setData(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}
	double volume() {
		return length*width*height;
	}
}