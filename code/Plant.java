/**
  * Creates abstract plant class
*/

/**
  * Plant
  * abstract class for Flower and Bush
*/
public abstract class Plant implements PlantInterface { 
  //protected instance variables
  protected double height;
  protected double width;
  protected double growth; 
  // where the base of the flower will be
  protected int xCoord; 
  protected int yCoord;

  /**
    * Plant
    * constructor
  */
  public Plant(int x, int y, double _width, double _height) {
    xCoord = x;
    yCoord = y;
    width = _width;
    height = _height;
  }
  /**
    * grow
    * increases height by the growth rate every day
  */
  public void grow(int days) { 
    height += growth*days;
  }
  /**
    * rain
    * increase growth rate by 10%
  */
  public void rain(int days) { 
    growth += .1 * days;
  }
  /**
    * frost
    * kills flower and sets everything to 0
  */
  public void frost() { 
    height = 0;
    width = 0;
    growth = 0;
  }
  /**
    * draw
    * draws out flower - says it's a flower, where it is, and the size
  */
  public void draw() { // draws out the flower - saying it is a flower, where it is, and the size
    System.out.println(toString());
  }
  public abstract String toString();
}
