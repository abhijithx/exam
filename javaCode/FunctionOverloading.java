package javaCode;

class Area {

    // Area of circle
    double calculateArea(double radius) {
        return Math.PI * radius * radius;
    }

    // Area of rectangle
    double calculateArea(double length, double breadth) {
        return length * breadth;
    }

    // Area of triangle
    double calculateArea(float base, float height) {
        return 0.5 * base * height;
    }
}

public class FunctionOverloading{
    public static void main(String[] args) {

        Area obj = new Area();

        double circle = obj.calculateArea(5); // radius
        double rectangle = obj.calculateArea(4, 6); // length, breadth
        double triangle = obj.calculateArea(3f, 4f); // base, height

        System.out.println("Area of Circle: " + circle);
        System.out.println("Area of Rectangle: " + rectangle);
        System.out.println("Area of Triangle: " + triangle);
    }
}