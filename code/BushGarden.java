
/**
  * BushGarden
  * represents a collection of bushes
*/
public class BushGarden extends Garden {
  /**
    * BushGarden
    * constructor
  */
  public BushGarden(int x, int y, int _width, int _height, int pNum) {
    super (x,y,_width,_height,pNum);
  }
  /**
    * newPlant
    * returns bush at location at x and y
  */
  public Bush newPlant(int x, int y) {
    return new Bush(x,y);
  }
}
