package javaCode;
import java.util.Scanner;

// Interface
interface Shape {
    double area();
    double perimeter();
}

// Circle class
class Circle implements Shape {
    double radius;

    Circle(double radius) {
        this.radius = radius;
    }

    public double area() {
        return Math.PI * radius * radius;
    }

    public double perimeter() {
        return 2 * Math.PI * radius;
    }
}

// Rectangle class
class Rectangle implements Shape {
    double length, breadth;

    Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    public double area() {
        return length * breadth;
    }

    public double perimeter() {
        return 2 * (length + breadth);
    }
}

// Main class
public class InterFace {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Circle");
            System.out.println("2. Rectangle");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter radius: ");
                    double r = sc.nextDouble();

                    Circle c = new Circle(r);
                    System.out.println("Area of Circle: " + c.area());
                    System.out.println("Perimeter of Circle: " + c.perimeter());
                    break;

                case 2:
                    System.out.print("Enter length: ");
                    double l = sc.nextDouble();
                    System.out.print("Enter breadth: ");
                    double b = sc.nextDouble();

                    Rectangle rec = new Rectangle(l, b);
                    System.out.println("Area of Rectangle: " + rec.area());
                    System.out.println("Perimeter of Rectangle: " + rec.perimeter());
                    break;

                case 3:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 3);

        sc.close();
    }
}
