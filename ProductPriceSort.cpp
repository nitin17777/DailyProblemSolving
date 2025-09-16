import java.util.Arrays;
import java.util.Scanner;

public class ProductPriceSorter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input for number of products
        System.out.print("Enter the number of products: ");
        int numProducts = scanner.nextInt();
        
        // Array to store product prices
        double[] prices = new double[numProducts];
        
        // Taking input for product prices
        System.out.println("Enter the prices of the products:");
        for (int i = 0; i < numProducts; i++) {
            System.out.print("Price of product " + (i + 1) + ": ");
            prices[i] = scanner.nextDouble();
        }
        
        // Sorting the prices in ascending order
        Arrays.sort(prices);
        
        // Displaying the sorted prices
        System.out.println("Sorted product prices (low to high):");
        for (int i = 0; i < numProducts; i++) {
            System.out.printf("Product %d: $%.2f\n", (i + 1), prices[i]);
        }
        
        scanner.close();
    }
}
