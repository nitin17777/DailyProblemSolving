import java.util.Scanner;

abstract class Sunstar {
    public abstract void printInfo();
}

class Employee extends Sunstar {
    private String name;
    private int age;
    private double salary;

    public Employee(String name, int age, double salary) {
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    @Override
    public void printInfo() {
        System.out.println("Employee Details:");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Salary: " + salary);
    }
}

public class Base {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter Employee Name: ");
        String name = scanner.nextLine();

        System.out.print("Enter Employee Age: ");
        int age = scanner.nextInt();

        System.out.print("Enter Employee Salary: ");
        double salary = scanner.nextDouble();

        Sunstar employee = new Employee(name, age, salary);
        employee.printInfo();

        scanner.close();
    }
}