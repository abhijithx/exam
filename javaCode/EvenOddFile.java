import java.io.*;
import java.util.Scanner;

public class EvenOddFile {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter input file: ");
        String inputFile = sc.nextLine();

        System.out.print("Enter even output file: ");
        String evenFile = sc.nextLine();

        System.out.print("Enter odd output file: ");
        String oddFile = sc.nextLine();

        try {
            BufferedReader br = new BufferedReader(new FileReader(inputFile));
            BufferedWriter evenWriter = new BufferedWriter(new FileWriter(evenFile));
            BufferedWriter oddWriter = new BufferedWriter(new FileWriter(oddFile));

            String line;
            while ((line = br.readLine()) != null) {
                String[] numbers = line.split("\\s+");
                for (String numStr : numbers) {
                    if (!numStr.isEmpty()) {
                        int num = Integer.parseInt(numStr);
                        if (num % 2 == 0) {
                            evenWriter.write(num + " ");
                        } else {
                            oddWriter.write(num + " ");
                        }
                    }
                }
            }

            br.close();
            evenWriter.close();
            oddWriter.close();

            System.out.println("Even and Odd numbers separated successfully");
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}