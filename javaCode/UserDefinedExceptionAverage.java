import java.util.Scanner;

class NegativeNumberException extends Exception {
    NegativeNumberException(String msg) {
        super(msg);
    }
}

public class UserDefinedExceptionAverage {
    static int validate(int n) throws NegativeNumberException {
        if (n < 0) {
            throw new NegativeNumberException("Negative number: " + n);
        }
        return n;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int sum = 0;
        int count = 0;

        System.out.println("Enter " + n + " numbers:");

        for (int i = 0; i < n; i++) {
            try {
                int num = validate(sc.nextInt());
                sum += num;
                count++;
            } catch (NegativeNumberException e) {
                System.out.println(e.getMessage());
            }
        }

        if (count > 0) {
            double avg = (double) sum / count;
            System.out.println("Average = " + avg);
        } else {
            System.out.println("No valid numbers");
        }
    }
}