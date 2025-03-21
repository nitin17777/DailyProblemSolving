import java.util.Scanner;

// Base class
class Animal {
    void eat() {
        System.out.println("eating...");
    }
}

// Intermediate class inheriting Animal
class Dog extends Animal {
    void bark() {
        System.out.println("barking...");
    }
}

// Final class inheriting Dog
class BabyDog extends Dog {
    void weep() {
        System.out.println("weeping...");
    }
}

// Main class
public class TestInheritance2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter animal type (BabyDog/Dog/Other): ");
        String animalType = sc.nextLine();

        // Handling actions
        if (animalType.equalsIgnoreCase("BabyDog")) {
            BabyDog babyDog = new BabyDog();
            System.out.print("Enter action (weep/bark/eat): ");
            String action = sc.nextLine();

            if (action.equalsIgnoreCase("weep")) {
                babyDog.weep();
            } else if (action.equalsIgnoreCase("bark")) {
                babyDog.bark();
            } else if (action.equalsIgnoreCase("eat")) {
                babyDog.eat();
            } else {
                System.out.println("Invalid action.");
            }

        } else if (animalType.equalsIgnoreCase("Dog")) {
            Dog dog = new Dog();
            System.out.print("Enter action (bark/eat): ");
            String action = sc.nextLine();

            if (action.equalsIgnoreCase("bark")) {
                dog.bark();
            } else if (action.equalsIgnoreCase("eat")) {
                dog.eat();
            } else {
                System.out.println("Invalid action.");
            }

        } else {
            Animal animal = new Animal();
            animal.eat();
        }

        sc.close();
    }
}
