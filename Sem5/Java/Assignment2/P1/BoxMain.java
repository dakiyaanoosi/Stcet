class BoxMain {
    public static void main(String[] args) {
        Box rectangle = new Box();
        rectangle.setData(4, 5, 6);

        Box cube = new Box();
        cube.setData(3, 4, 5);

        double rectVol = rectangle.volume();
        double cubeVol = cube.volume();

        System.out.println("Volume of Rectangle = "+rectVol);
        System.out.println("Volume of Cube = "+cubeVol);

        if(rectVol > cubeVol)
            System.out.println("(Volume of Rectangle) > (Volume of Cube)");
        else if(cubeVol > rectVol)
            System.out.println("(Volume of Cube) > (Volume of Rectangle)");
        else
            System.out.println("(Volume of Rectangle) = (Volume of Cube)");
    }
}
