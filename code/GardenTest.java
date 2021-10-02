

import java.util.Scanner;

/**
  * GardenTest
  * Test class for FlowerBushGarden
*/
public class GardenTest {
  public static void main(String[] args) {
    //scanner class for inputs
    Scanner s = new Scanner(System.in);
    
    System.out.println("Enter the amount of plants you wish to plant, must be a whole number: ");
    int plantNum = s.nextInt();

    //check if input is valid
    if(plantNum < 0) {
      System.out.println("Please enter valid number.");
    }
    else {
      //creates a garden backyard using plantNum amount
      FlowerBushGarden backyard = new FlowerBushGarden(0, 0, 400, 600, plantNum);

      backyard.draw();
      System.out.println("growing"); 
  
      //grows garden
      backyard.grow(1);
      backyard.draw();
      backyard.rain(5);
      System.out.println("growing");
      backyard.grow(1);
      backyard.draw();
    
      //kills garden
      System.out.println("Frost happens.");
      backyard.frost();
      backyard.draw();
     
      //adds plants
      System.out.println("Adding new flowers to backyard");
      int newPlants = (int)(50 * Math.random());
      backyard.plantNewPlants(newPlants);
      backyard.draw();

      int total = plantNum + newPlants;

      System.out.println("The total amount of plants in your garden is " + total);
    }
  }
}


