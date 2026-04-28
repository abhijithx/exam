import java.util.Scanner;

class InvalidCredentialsException extends Exception {
    InvalidCredentialsException(String message) {
        super(message);
    }
}

class Authenticator {
    private String username = "admin";
    private String password = "1234";

    void authenticate(String u, String p) throws InvalidCredentialsException {
        if (!u.equals(username) || !p.equals(password)) {
            throw new InvalidCredentialsException("Invalid username or password");
        }
        System.out.println("Authentication successful");
    }
}

public class User_defined_Exception {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Username and Password");
        String u = sc.nextLine();
        String p = sc.nextLine();
        Authenticator a = new Authenticator();
        try {
            a.authenticate(u, p);
        } catch (InvalidCredentialsException e) {
            System.out.println(e.getMessage());
        }
    }
}