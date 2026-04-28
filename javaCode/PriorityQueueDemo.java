import java.util.PriorityQueue;
import java.util.Scanner;

public class PriorityQueueDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            pq.add(sc.nextInt());
        }

        System.out.println("PriorityQueue: " + pq);

        System.out.println("Head element (peek): " + pq.peek());

        System.out.println("Removed element (poll): " + pq.poll());
        System.out.println("After removal: " + pq);

        System.out.print("Enter element to search: ");
        int key = sc.nextInt();
        System.out.println("Contains " + key + ": " + pq.contains(key));

        System.out.println("Iterating elements:");
        for (int x : pq) {
            System.out.println(x);
        }
    }
}