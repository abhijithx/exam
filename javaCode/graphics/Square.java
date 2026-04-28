package javaCode.graphics;



public class Square {
    double side;

    public Square(double s) {
        side = s;
    }

    public double area() {
        return side * side;
    }
}