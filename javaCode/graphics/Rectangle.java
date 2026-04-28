
package javaCode.graphics;

public class Rectangle {
    double length, breadth;

    public Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    public double area() {
        return length * breadth;
    }
}
