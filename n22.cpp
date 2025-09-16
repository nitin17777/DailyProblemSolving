import java.util.ArrayList;
import java.util.Scanner;

public class DynamicIntegerList {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for the number of elements
        System.out.print("Enter the number of elements you want to add: ");
        int size = scanner.nextInt();
        
        // Creating an ArrayList to store integers
        ArrayList<Integer> numbers = new ArrayList<>();
        
        // Taking input for list elements
        for (int i = 0; i < size; i++) {
            System.out.print("Enter element " + (i + 1) + ": ");
            numbers.add(scanner.nextInt());
        }
        
        // Displaying the list
        System.out.println("The elements of the list are: " + numbers);
        
        scanner.close();
    }
}
