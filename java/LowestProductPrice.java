import java.util.Scanner;
class Product {
    String pcode, pname;
    int price;

    void details(int n) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the product code for item " + n + ":");
        pcode = sc.next();
        System.out.println("Enter the product name for item " + n + ":");
        pname = sc.next();
        System.out.println("Enter the price for item " + n + ":");
        price = sc.nextInt();
    }
}

public class LowestProductPrice {
    public static void main(String[] args) {
        Product p1 = new Product();
        Product p2 = new Product();
        Product p3 = new Product();

        p1.details(1);
        p2.details(2);
        p3.details(3);

        Product lowest = p1;
        if (p2.price < lowest.price) lowest = p2;
        if (p3.price < lowest.price) lowest = p3;

        System.out.println("\nProduct with the lowest price:");
        System.out.println("Code: " + lowest.pcode);
        System.out.println("Name: " + lowest.pname);
        System.out.println("Price: " + lowest.price);
    }
}