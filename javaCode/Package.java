package javaCode;

import  javaCode.graphics.*;

public class Package {
    public static void main(String[] args) {

        Rectangle r = new Rectangle(4, 5);
        Triangle t = new Triangle(3, 6);
        Square s = new Square(4);
        Circle c = new Circle(3);

        System.out.println("Area of Rectangle: " + r.area());
        System.out.println("Area of Triangle: " + t.area());
        System.out.println("Area of Square: " + s.area());
        System.out.println("Area of Circle: " + c.area());
    }
}