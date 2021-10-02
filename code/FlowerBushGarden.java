
/**
  * FlowerBushGarden
  * creates garden of flowers and bushes
*/
public class FlowerBushGarden extends Garden {
  /**
    * FlowerBushGarden
    * constructor
  */
  public FlowerBushGarden(int x, int y, int _width, int _height, int pNum) {
    super (x,y,_width,_height,pNum);
  }
  /**
    * newPlant
    * plants the plants in garden
  */
  public PlantInterface newPlant(int x, int y) {
    // a random number that determines whether or not the plant planted is a bush or a flower
    int rand = (int)(2 * Math.random()); 
    if (rand == 0)
      return new Flower(x,y);
    else
      return new Bush(x,y);
 }
}
