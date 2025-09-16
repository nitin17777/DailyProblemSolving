Problem-1: 1.	Design a simple JavaFX GUI application that demonstrates basic user interaction using a button. The application should display a window titled "My First Frame" containing a single button labeled "Press Me". When the button is clicked, the application should respond by printing the message "Welcome to JavaFX" to the console.

Solution:
package application;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Tutorial extends Application {

    // Main method to launch the JavaFX application
    public static void main(String[] args) {
        launch(args);
    }

    // Override the start() method where the UI is set up
    @Override
    public void start(Stage primaryStage) {
        // Set window title
        primaryStage.setTitle("My First Frame");

        // Create a button and set its label
        Button btn = new Button("Press Me");

        // Handle button press event
        btn.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                System.out.println("Welcome to JavaFX");
            }
        });

        // Create root node and add the button
        StackPane root = new StackPane();
        root.getChildren().add(btn);

        // Create scene with root node and set it on stage
        Scene scene = new Scene(root, 300, 250);
        primaryStage.setScene(scene);

        // Display the stage
        primaryStage.show();
    }
}


Problem-2: Develop a JavaFX application that visually represents a simple house using basic geometric shapes like rectangles and lines. The house should include a body, a roof, and a door, all rendered in a GUI window.


Solution:
package application;

import javafx.application.Application; 
import javafx.scene.Group; 
import javafx.scene.Scene; 
import javafx.stage.Stage; 
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Line;
import javafx.scene.paint.Color;

/**
 * A JavaFX program to draw a simple house using rectangles and lines.
 */
public class RectangleHouse extends Application { 

    @Override 
    public void start(Stage stage) { 
        // Main body of the house (rectangle)
        Rectangle houseBody = new Rectangle();
        houseBody.setX(150.0f); 
        houseBody.setY(75.0f); 
        houseBody.setWidth(150.0f); 
        houseBody.setHeight(75.0f);
        houseBody.setFill(Color.BEIGE);

        // Door of the house (second rectangle)
        Rectangle door = new Rectangle(200.0f, 120.0f, 50.0f, 30.0f);
        door.setFill(Color.hsb(50, 1, 1));  // yellowish color

        // Roof lines of the house
        Line roofLeft = new Line(150, 75, 225, 30);   // left slope of the roof
        Line roofRight = new Line(225, 30, 300, 75);  // right slope of the roof

        // Creating a group to hold all shapes
        Group root = new Group();
        root.getChildren().addAll(houseBody, door, roofLeft, roofRight);
         
        // Setting up the scene
        Scene scene = new Scene(root, 600, 300);  
        
        // Stage setup
        stage.setTitle("Drawing a House"); 
        stage.setScene(scene); 
        stage.show(); 
    }      

    public static void main(String[] args) { 
        launch(args); 
    } 
}