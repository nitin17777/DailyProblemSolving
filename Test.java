import java.util.Scanner;

// Parent class
class Vehicle {
    int maxSpeed;
    String fuelType;

    // Constructor for Vehicle
    Vehicle(int maxSpeed, String fuelType) {
        this.maxSpeed = maxSpeed;
        this.fuelType = fuelType;
    }

    // Method to display vehicle details
    void displayVehicleDetails() {
        System.out.println("Vehicle Maximum Speed: " + maxSpeed);
        System.out.println("Fuel Type: " + fuelType);
    }
}

// Child class extending Vehicle
class Car extends Vehicle {
    String brand;
    int carMaxSpeed;

    // Constructor for Car using super to call Vehicle's constructor
    Car(String brand, int carMaxSpeed, int maxSpeed, String fuelType) {
        super(maxSpeed, fuelType);
        this.brand = brand;
        this.carMaxSpeed = carMaxSpeed;
    }

    // Method to display car details
    void displayCarDetails() {
        System.out.println("Car Details:");
        System.out.println("Brand: " + brand);
        System.out.println("Car Maximum Speed: " + carMaxSpeed);
        System.out.println("Inherited Vehicle Maximum Speed: " + super.maxSpeed);
        super.displayVehicleDetails();
    }
}

// Main class
public class Test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input for Car
        System.out.print("Enter car brand: ");
        String brand = sc.nextLine();

        System.out.print("Enter car maximum speed: ");
        int carMaxSpeed = sc.nextInt();
        sc.nextLine(); // Consume leftover newline

        System.out.print("Enter fuel type: ");
        String fuelType = sc.nextLine();

        // Creating Car object with maxSpeed of Vehicle set to 120
        Car car = new Car(brand, carMaxSpeed, 120, fuelType);

        // Displaying Car details
        car.displayCarDetails();

        sc.close();
    }
}
