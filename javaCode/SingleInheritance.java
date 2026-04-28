package javaCode;

import java.util.Scanner;

// Base class
class Employee {
    int empid;
    String name;
    double salary;
    String address;

    // Constructor
    Employee(int empid, String name, double salary, String address) {
        this.empid = empid;
        this.name = name;
        this.salary = salary;
        this.address = address;
    }
}

// Derived class
class Teacher extends Employee {
    String department;
    String subject;

    // Constructor
    Teacher(int empid, String name, double salary, String address,
            String department, String subject) {

        super(empid, name, salary, address); // call base class constructor
        this.department = department;
        this.subject = subject;
    }

    // Display method
    void display() {
        System.out.println("\nEmployee ID: " + empid);
        System.out.println("Name: " + name);
        System.out.println("Salary: " + salary);
        System.out.println("Address: " + address);
        System.out.println("Department: " + department);
        System.out.println("Subject: " + subject);
    }
}

// Main class
public class SingleInheritance{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of teachers: ");
        int n = sc.nextInt();
        sc.nextLine(); // clear buffer

        Teacher[] t = new Teacher[n]; // array of objects

        // Input
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details of Teacher " + (i + 1));

            System.out.print("Emp ID: ");
            int id = sc.nextInt();
            sc.nextLine();

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Salary: ");
            double salary = sc.nextDouble();
            sc.nextLine();

            System.out.print("Address: ");
            String address = sc.nextLine();

            System.out.print("Department: ");
            String dept = sc.nextLine();

            System.out.print("Subject: ");
            String sub = sc.nextLine();

            t[i] = new Teacher(id, name, salary, address, dept, sub);
        }

        // Output
        System.out.println("\n--- Teacher Details ---");
        for (int i = 0; i < n; i++) {
            t[i].display();
        }

        sc.close();
    }
}
