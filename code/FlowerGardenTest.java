/**
  * Creates a flower garden
  * When the garden "grows" all of the flowers in the garden grow
  * When it rains - all of the flowers' growing rates are affected
  * When it frosts all of the flowers within that garden die
  * Draw method specifies garden information and then individual flowers
*/
public class FlowerGardenTest {
  public static void main(String[] args) {
    //create backyard of FlowerGarden 
    FlowerGarden backyard = new FlowerGarden (0, 0, 400, 600, 6);
    backyard.draw();

    //create sideyard of FlowerGarden
    FlowerGarden sideyard = new FlowerGarden(400, 0, 400, 600, 6);
    
    //implement grow, rain, and frost and display plant status
    System.out.println("growing");
    sideyard.grow(1);
    backyard.grow(1);
    backyard.draw(); 
    sideyard.draw();
    backyard.rain(5);
    System.out.println("growing");
    backyard.grow(1);
    backyard.draw();
    System.out.println("Frost happens");
    backyard.frost();
    backyard.draw();
  
    //add new flowers
    System.out.println("Adding new flowers to backyard");
    backyard.plantNewPlants(12);
    backyard.draw();
    
  }
}
