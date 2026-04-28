import java.util.Scanner;

class TableThread extends Thread {
    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println("5 x " + i + " = " + (5 * i));
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
            }
        }
    }
}

class PrimeThread extends Thread {
    int n;

    PrimeThread(int n) {
        this.n = n;
    }

    boolean isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    public void run() {
        int count = 0, num = 2;
        while (count < n) {
            if (isPrime(num)) {
                System.out.println("Prime: " + num);
                count++;
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                }
            }
            num++;
        }
    }
}

public class Threads {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter N for prime numbers: ");
        int n = sc.nextInt();

        TableThread t1 = new TableThread();
        PrimeThread t2 = new PrimeThread(n);

        t1.start();
        t2.start();
    }
}