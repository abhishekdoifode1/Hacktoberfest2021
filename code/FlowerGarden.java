

/**
  * FlowerGarden
  * represents a collection of flowers
*/
public class FlowerGarden extends Garden {
  /**
    * FlowerGarden
    * constructor
  */
  public FlowerGarden(int x, int y, int _width, int _height, int pNum) {
    super(x,y,_width,_height,pNum);
  }
  /**
    * newPlant
    * returns flower at location x,y
  */
  public Flower newPlant(int x, int y) {
    return new Flower(x,y);
  }
}
