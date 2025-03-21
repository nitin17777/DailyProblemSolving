import java.util.*;

class FirstProblem {
    public static void main(String args[]) {
        int i, j;
        Scanner sc = new Scanner(System.in);

        // For loop with embedded input and condition checking
        for (System.out.print("Enter values of i and j: "),
             i = sc.nextInt(), j = sc.nextInt();  // Initialization

             (i + j) < 10 && (i + j) > 0;  // Condition: Loop continues if 0 < i + j < 10

             System.out.print("Enter values of i and j: "), 
             i = sc.nextInt(), j = sc.nextInt()) {  // Update (new input)
            
            // Empty loop body
        }

        sc.close();
    }
}
