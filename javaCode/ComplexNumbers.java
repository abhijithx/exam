package javaCode;

class Complex {
	double real, imag;

	Complex(double real, double imag) {
		this.real = real;
		this.imag = imag;
	}

	Complex add(Complex other) {
		return new Complex(this.real + other.real, this.imag + other.imag);
	}

	@Override
	public String toString() {
		return real + (imag >= 0 ? "+" : "") + imag + "i";
	}
}

public class ComplexNumbers {
	public static void main(String[] args) {
		Complex c1 = new Complex(2.5, 3.5);
		Complex c2 = new Complex(1.5, -2.0);
		Complex sum = c1.add(c2);
		System.out.println("First complex number: " + c1);
		System.out.println("Second complex number: " + c2);
		System.out.println("Sum: " + sum);
	}
}
