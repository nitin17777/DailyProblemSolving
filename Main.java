import java.util.Scanner;

// Define the Shape interface
interface Shape {
    void draw();
    double calculateArea();
    void move(int x, int y);
}

// Implement the Circle class
class Circle implements Shape {
    private int radius;
    private int x;
    private int y;

    public Circle(int radius) {
        this.radius = radius;
        this.x = 0;
        this.y = 0;
    }

    @Override
    public void draw() {
        System.out.println("Circle has been drawn.");
    }

    @Override
    public double calculateArea() {
        return 3.14 * radius * radius;
    }

    @Override
    public void move(int x, int y) {
        this.x = x;
        this.y = y;
        System.out.println("Circle has been moved to x = " + x + " and y = " + y);
    }
}

// Main class to run the program
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the radius from the user
        System.out.print("Enter radius of the circle: ");
        int radius = scanner.nextInt();

        // Create a Circle object
        Circle circle = new Circle(radius);
        circle.draw();

        // Calculate and display the area
        double area = circle.calculateArea();
        System.out.printf("Area of circle: %.2f\n", area);

        // Get the new coordinates from the user
        System.out.print("Enter x and y coordinates to move the circle: ");
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        // Move the circle to the new coordinates
        circle.move(x, y);

        scanner.close();
    }
}