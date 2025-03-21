import java.util.Scanner;

abstract class Shape {
    private double width;
    private double height;

    public final void setWidth(double width) {
        this.width = width;
    }

    public final void setHeight(double height) {
        this.height = height;
    }

    public final double getWidth() {
        return width;
    }

    public final double getHeight() {
        return height;
    }

    public abstract double area();
}

class Rectangle extends Shape {
    @Override
    public double area() {
        return getWidth() * getHeight();
    }

    public void displayDetails() {
        System.out.println("Rectangle Details:");
        System.out.println("Width of rectangle: " + getWidth());
        System.out.println("Height of rectangle: " + getHeight());
        System.out.println("Area of rectangle: " + area());
    }
}

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Rectangle rectangle = new Rectangle();

        System.out.print("Enter width of the rectangle: ");
        double width = scanner.nextDouble();
        rectangle.setWidth(width);

        System.out.print("Enter height of the rectangle: ");
        double height = scanner.nextDouble();
        rectangle.setHeight(height);

        rectangle.displayDetails();

        scanner.close();
    }
}