import java.util.Scanner;

class FibonacciRunnable implements Runnable {
    int n;

    FibonacciRunnable(int n) {
        this.n = n;
    }

    public void run() {
        int a = 0, b = 1;
        for (int i = 1; i <= n; i++) {
            System.out.println("Fibonacci: " + a);
            int c = a + b;
            a = b;
            b = c;
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
            }
        }
    }
}

class EvenRunnable implements Runnable {
    int start, end;

    EvenRunnable(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public void run() {
        for (int i = start; i <= end; i++) {
            if (i % 2 == 0) {
                System.out.println("Even: " + i);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                }
            }
        }
    }
}

public class RunnableInterface {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of Fibonacci terms: ");
        int n = sc.nextInt();

        System.out.print("Enter range (start end): ");
        int s = sc.nextInt();
        int e = sc.nextInt();

        Thread t1 = new Thread(new FibonacciRunnable(n));
        Thread t2 = new Thread(new EvenRunnable(s, e));

        t1.start();
        t2.start();
    }
}