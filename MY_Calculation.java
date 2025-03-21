import java.util.Scanner;

// Parent class
class Calculation {
    // Method to add two numbers
    int addition(int a, int b) {
        return a + b;
    }

    // Method to subtract two numbers
    int subtraction(int a, int b) {
        return a - b;
    }
}

// Child class extending Calculation
class My_Calculation extends Calculation {
    // Method to multiply two numbers
    int multiplication(int a, int b) {
        return a * b;
    }

    // Main method inside My_Calculation class
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input for numbers
        System.out.print("Enter the first number: ");
        int num1 = sc.nextInt();

        System.out.print("Enter the second number: ");
        int num2 = sc.nextInt();
        sc.nextLine(); // Consume leftover newline

        // Taking input for the operation
        System.out.print("Enter operation (add/subtract/multiply): ");
        String operation = sc.nextLine().toLowerCase();

        // Creating an object of My_Calculation
        My_Calculation calc = new My_Calculation();

        // Performing the operation based on user input
        switch (operation) {
            case "add":
                System.out.println("The sum of the given numbers: " + calc.addition(num1, num2));
                break;
            case "subtract":
                System.out.println("The difference between the given numbers: " + calc.subtraction(num1, num2));
                break;
            case "multiply":
                System.out.println("The product of the given numbers: " + calc.multiplication(num1, num2));
                break;
            default:
                System.out.println("Invalid operation.");
                break;
        }

        sc.close();
    }
}
