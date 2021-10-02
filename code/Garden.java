/**
  * Parent class for bushGarden and flowerGarden
*/

import java.util.ArrayList;

/**
  * Garden
  * abstract class for FlowerGarden and BushGarden
*/
public abstract class Garden implements PlantInterface {
  // creates a garden
  protected ArrayList <PlantInterface> garden = new ArrayList ();
  
  //protected instance variables
  protected int xCoord;
  protected int yCoord;
  protected int width;
  protected int height;
  protected int plantNum;
  
  /**
    * Garden
    * constructor
  */
  public Garden(int x, int y, int _width, int _height, int pNum) {
    xCoord = x;
    yCoord = y;
    width = _width;
    height = _height;
    
    plantNewPlants(pNum);
  }
  /**
    * grow
    * grows all plants in garden
  */
  public void grow(int days) { 
    //for loop to grow every plant in garden
    for (int i = 0; i < garden.size(); i ++) {
      garden.get(i).grow(days);
    }
  }
  /**
    * rain
    * rains on all plants in garden 
  */
  public void rain(int days) { 
    //for loop to rain on every plant in garden
    for (int i = 0; i < garden.size(); i ++) {
      garden.get(i).rain(days);
    }
  }
  /**
    * frost
    * kills all of the plants
  */
  public void frost() { 
    //for loop to kill each plant in garden
    for (int i = 0; i < garden.size(); i ++) {
      garden.get(i).frost();
    }
  }
  /**
    * draw
    * prints information of garden
  */
  public void draw() {
    System.out.println(toString()); 
    //for loop to print information of each plant
    for (int i = 0; i < garden.size(); i ++) { 
      garden.get(i).draw();
    }
  }
  /**
    * toString
    * compose string that is printed with garden information
  */
  public String toString() {
    return "Garden X:" + xCoord + " Y:" + yCoord + " Width: " + width + " Height: " + height + " Plants: " + plantNum;
  }
  
  /**
    * plantNewPlants
    * adds plants to the garden
  */
  public void plantNewPlants(int newPlants) {
    plantNum += newPlants;
    //for loop to plant each plant
    for (int i = 0; i < newPlants; i ++) {
      int rand1, rand2; // x value then y value to determine where they will be placed in the garden
      rand1 = (int)(width * Math.random() + xCoord);
      rand2 = (int)(height * Math.random() + yCoord);
      
      garden.add(newPlant(rand1,rand2));
    }
  }
  public abstract PlantInterface newPlant(int x, int y);
}
