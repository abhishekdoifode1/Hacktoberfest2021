/**
  * Tests to see if the flower class works
  * The grow method should increase the flower's height by the rate which is initially .5
  * The rain method should increase the rate by 10%
  * The frost method should kill the flower and set growth rate, height, and width to 0
  * The draw method should write out where flower is, the growth rate, height, and width
*/
public class FlowerTest {
  public static void main(String[] args) {
    // creates a flower at coordinates 20, 40
    Flower myFlower = new Flower (20, 40);

    //display flower
    myFlower.draw();

    //flower grows 2 days
    System.out.println("growing 2 days"); 
    myFlower.grow(2);

    //display flower
    myFlower.draw();

    //flower rains 5 days and grows 2 days
    System.out.println("raining 5 days and growing 2 days");
    myFlower.rain(5);
    myFlower.grow(2);

    //display flower
    myFlower.draw();

    //flower grows 1 day
    System.out.println("growing 1 day");
    myFlower.grow(1);

    //display flower
    myFlower.draw();

    //frost kills flower
    System.out.println("Frost happens");
    myFlower.frost();

    //display flower
    myFlower.draw();

    System.out.println();
  }
}
