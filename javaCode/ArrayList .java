import java.util.ArrayList;
import java.util.Scanner;

public class ArrayList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> list = new ArrayList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        sc.nextLine();

        System.out.println("Enter strings:");
        for (int i = 0; i < n; i++) {
            list.add(sc.nextLine());
        }

        System.out.println("List: " + list);

        System.out.print("Enter element to search: ");
        String search = sc.nextLine();
        System.out.println("Contains: " + list.contains(search));

        System.out.print("Enter element to remove: ");
        String remove = sc.nextLine();
        list.remove(remove);
        System.out.println("After removal: " + list);

        System.out.print("Enter index to update: ");
        int index = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter new value: ");
        String value = sc.nextLine();
        if (index >= 0 && index < list.size()) {
            list.set(index, value);
        }

        System.out.println("Updated List: " + list);

        System.out.println("Iterating using for-each:");
        for (String s : list) {
            System.out.println(s);
        }
    }
}