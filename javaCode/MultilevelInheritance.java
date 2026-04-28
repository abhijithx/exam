package javaCode;

import java.util.Scanner;

// Base class
class Person {
    String name, gender, address;
    int age;

    Person(String name, String gender, String address, int age) {
        this.name = name;
        this.gender = gender;
        this.address = address;
        this.age = age;
    }
}

// Intermediate class
class Employee extends Person {
    int empid;
    String company_name, qualification;
    double salary;

    Employee(String name, String gender, String address, int age,
             int empid, String company_name, String qualification, double salary) {

        super(name, gender, address, age); // call Person constructor
        this.empid = empid;
        this.company_name = company_name;
        this.qualification = qualification;
        this.salary = salary;
    }
}

// Derived class
class Teacher extends Employee {
    String subject, department;
    int teacherid;

    Teacher(String name, String gender, String address, int age,
            int empid, String company_name, String qualification, double salary,
            String subject, String department, int teacherid) {

        super(name, gender, address, age, empid, company_name, qualification, salary);
        this.subject = subject;
        this.department = department;
        this.teacherid = teacherid;
    }

    // Display method
    void display() {
        System.out.println("\n--- Teacher Details ---");
        System.out.println("Name: " + name);
        System.out.println("Gender: " + gender);
        System.out.println("Address: " + address);
        System.out.println("Age: " + age);
        System.out.println("Emp ID: " + empid);
        System.out.println("Company Name: " + company_name);
        System.out.println("Qualification: " + qualification);
        System.out.println("Salary: " + salary);
        System.out.println("Teacher ID: " + teacherid);
        System.out.println("Department: " + department);
        System.out.println("Subject: " + subject);
    }
}

// Main class
public class MultilevelInheritance {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of teachers: ");
        int n = sc.nextInt();
        sc.nextLine();

        Teacher[] t = new Teacher[n]; // array of objects

        // Input
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details of Teacher " + (i + 1));

            System.out.print("Name: ");
            String name = sc.nextLine();

            System.out.print("Gender: ");
            String gender = sc.nextLine();

            System.out.print("Address: ");
            String address = sc.nextLine();

            System.out.print("Age: ");
            int age = sc.nextInt();

            System.out.print("Emp ID: ");
            int empid = sc.nextInt();
            sc.nextLine();

            System.out.print("Company Name: ");
            String company = sc.nextLine();

            System.out.print("Qualification: ");
            String qual = sc.nextLine();

            System.out.print("Salary: ");
            double salary = sc.nextDouble();
            sc.nextLine();

            System.out.print("Subject: ");
            String subject = sc.nextLine();

            System.out.print("Department: ");
            String dept = sc.nextLine();

            System.out.print("Teacher ID: ");
            int tid = sc.nextInt();
            sc.nextLine();

            t[i] = new Teacher(name, gender, address, age,
                               empid, company, qual, salary,
                               subject, dept, tid);
        }

        // Output
        System.out.println("\n===== ALL TEACHER DETAILS =====");
        for (int i = 0; i < n; i++) {
            t[i].display();
        }

        sc.close();
    }
}
