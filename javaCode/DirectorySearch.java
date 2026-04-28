import java.io.File;
import java.util.Scanner;

public class DirectorySearch {
    static void listFiles(File dir) {
        File[] files = dir.listFiles();
        if (files != null) {
            for (File f : files) {
                if (f.isDirectory()) {
                    System.out.println("Directory: " + f.getName());
                    listFiles(f);
                } else {
                    System.out.println("File: " + f.getName());
                }
            }
        }
    }

    static boolean searchFile(File dir, String name) {
        File[] files = dir.listFiles();
        if (files != null) {
            for (File f : files) {
                if (f.isDirectory()) {
                    if (searchFile(f, name)) return true;
                } else {
                    if (f.getName().equals(name)) {
                        System.out.println("Found at: " + f.getAbsolutePath());
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter directory path: ");
        String path = sc.nextLine();

        File dir = new File(path);

        if (!dir.exists() || !dir.isDirectory()) {
            System.out.println("Invalid directory");
            return;
        }

        System.out.println("Listing files and directories:");
        listFiles(dir);

        System.out.print("Enter file name to search: ");
        String name = sc.nextLine();

        if (!searchFile(dir, name)) {
            System.out.println("File not found");
        }
    }
}