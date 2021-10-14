import java.util.Scanner;
import java.util.Arrays;
import java.util.Random;

class PeriodicTableTester {
// create a linear search algorithm
  public static int linearSearch(String[] arr, String key){  
    for(int i=0;i<arr.length;i++){  
        if(arr[i] == key){  
            return i;  
        }  
    }  
    return -1;  
}  

//function to get slice of a primitive array in Java 
public static String[] slice(String[] array, int startIndex, int endIndex) 
{ 
// Get the slice of the Array 
String[] slicedArray = Arrays.copyOfRange(array, startIndex, endIndex); 
// return the slice 
return slicedArray; 
} 
  public static void main(String[] args) {
    // create an object of Scanner class
    Scanner input = new Scanner(System.in);
    // create an array of elements
    String[] elements = {"Hydrogen", "Helium", "Lithium", "Berylium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Flourine", "Neon", "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulphur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vandium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
    System.out.print("Type the length till which you remember the periodic table: ");
    int userChosenLength = input.nextInt();
    if (userChosenLength < 1) {
      System.out.println("Error! Please type a number equal to or greater than 1!");
    } else if (userChosenLength > 118) {
      System.out.println("Wow! You're a genius. You are even more intelligent than the scientists!");
      System.out.println("😑 Please type a number smaller than 118!");
    } else {
    String[] slicedArray = slice(elements, 0, userChosenLength);
    // pick a random element
    Random random = new Random();
    int pickRandom = random.nextInt(slicedArray.length);
    String randomElement = slicedArray[pickRandom];
    // ask the question
    System.out.println("What is the atomic number of "+ randomElement + "?");
    System.out.print("Your answer: ");
    // ask for input
    int yourAnswer = input.nextInt();
    // check the answer
    if (yourAnswer > userChosenLength) {
      System.out.println("😑 Please type a number smaller than " + userChosenLength + "!");
    } else if (yourAnswer < 1) {
      System.out.println("Error! Please type a number equal to or greater than 1!");
    } else {
    int result = linearSearch(elements, randomElement);
    int recievedInput = yourAnswer - 1;
    int correctAnswer = result + 1;
    if (recievedInput == result) {
      System.out.println("Correct Answer!");
    } else {
      System.out.println("Sorry, but you need some more practice. The correct answer is " + correctAnswer + ".");
    }
  }
}
    // close the object with Scanner class
    input.close();
  }
}
// code by Dhruv Krishna Vaid (https://github.com/dhruvkrishnavaid)
