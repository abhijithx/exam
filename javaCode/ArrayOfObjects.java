package javaCode;
import java.util.Scanner;

class Employee {
    int eNo;
    String eName;
    double eSalary;

    void readData(Scanner sc) {
        System.out.print("Enter Employee Number: ");
        eNo = sc.nextInt();
        sc.nextLine(); // clear buffer

        System.out.print("Enter Employee Name: ");
        eName = sc.nextLine();

        System.out.print("Enter Employee Salary: ");
        eSalary = sc.nextDouble();
    }

    void display() {
        System.out.println("Employee Number: " + eNo);
        System.out.println("Employee Name: " + eName);
        System.out.println("Employee Salary: " + eSalary);
    }
}

public class ArrayOfObjects {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of employees: ");
        int n = sc.nextInt();

        Employee[] emp = new Employee[n];  // array of objects

        // Input
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Employee " + (i + 1));
            emp[i] = new Employee();   // object creation
            emp[i].readData(sc);
        }

        // Search
        System.out.print("\nEnter Employee Number to search: ");
        int searchNo = sc.nextInt();

        boolean found = false;

        for (int i = 0; i < n; i++) {
            if (emp[i].eNo == searchNo) {
                System.out.println("\nEmployee Found:");
                emp[i].display();
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Employee not found!");
        }

        sc.close();
    }
}