package javaCode;
class CPU {
    int price;

    // Inner class (non-static)
    class Processor {
        int cores;
        String manufacturer;

        void displayProcessor() {
            System.out.println("Processor Cores: " + cores);
            System.out.println("Processor Manufacturer: " + manufacturer);
        }
    }

    // Static nested class
    static class RAM {
        int memory;
        String manufacturer;

        void displayRAM() {
            System.out.println("RAM Memory: " + memory + " GB");
            System.out.println("RAM Manufacturer: " + manufacturer);
        }
    }
}

public class InnerClass{
    public static void main(String[] args) {

        // Create CPU object
        CPU cpu = new CPU();
        cpu.price = 50000;

        // Create Processor object (needs CPU object)
        CPU.Processor processor = cpu.new Processor();
        processor.cores = 8;
        processor.manufacturer = "Intel";

        // Create RAM object (no CPU object needed)
        CPU.RAM ram = new CPU.RAM();
        ram.memory = 16;
        ram.manufacturer = "Corsair";

        // Display details
        System.out.println("CPU Price: " + cpu.price);
        processor.displayProcessor();
        ram.displayRAM();
    }
}
