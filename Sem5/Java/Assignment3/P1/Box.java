class Box {
	int perimeter(int s) {
		return 4*s;
	}

	int perimeter(int l, int b) {
		return 2*(l+b);
	}

	int perimeter(int s1, int s2, int s3) {
		return (s1+s2+s3);
	}
}