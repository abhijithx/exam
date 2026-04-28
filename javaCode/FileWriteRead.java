import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class FileWriteRead {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter file name: ");
        String fileName = sc.nextLine();

        try {
            FileWriter fw = new FileWriter(fileName);
            System.out.println("Enter text (type END to stop):");
            while (true) {
                String line = sc.nextLine();
                if (line.equals("END")) break;
                fw.write(line + "\n");
            }
            fw.close();

            System.out.println("\nFile Content:");
            BufferedReader br = new BufferedReader(new FileReader(fileName));
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            br.close();

        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}