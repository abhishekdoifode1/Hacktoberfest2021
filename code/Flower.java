
/**
  * Flower
  * Creates flower object from plant class
*/
public class Flower extends Plant {
  // constructor sets the base (location) of the flower
  public Flower(int x, int y) { 
    //set constants: initial height to be 30, width to be 8
    super(x,y,8.0,30.0); 

    //growth rate is half of height
    growth = height/2.0;
  }
  /**
    * toString
    * composes the string that is printed with Flower information
  */
  public String toString() {
    return "Flower X:" + xCoord + " Y:" + yCoord + " - Rate: " + growth + " Height: " + height + " Width: " + width;
  }
}
