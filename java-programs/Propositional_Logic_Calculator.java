import java.util.Scanner;

public class Propositional_Logic_Calculator {
  
  private static String res, p, q, operation;
  private static int initial, prop;
  
  public static void main(String[] args){
    
    /*
      User enters x amount of propostions and selects what [Note:[it's two for now]]
      Propositional Operator they would like. Then the action is performed
      
      1. First input will be prompted
      2. Operation will be prompted
      3. Output will be spit out
    */
    
    Scanner sc = new Scanner(System.in);
    
    
    System.out.println("Enter your two propositions below. ");
    
    System.out.println();
    
    System.out.print("Enter your propostion: "); p = sc.nextLine();
    System.out.print("Enter your propostion: "); q = sc.nextLine();
    
    System.out.println();
    
    System.out.println("What connective would you like to use?");
    System.out.println();

    System.out.println("Type {N} for negation, {A} for conjunction, {O} for disjunction, {I} for implication, {B} for bicondtional. Please include {}.");
    
    operation = sc.next();
 
    if(operation.equals("{N}")){
       negation(p, q);
    }
    else if (operation.equals("{A}")){
      conjunction(p,q);
    }
    else if (operation.equals("{O}")){
      disjunction(p,q);
    }
    else if (operation.equals("{I}")){
      implication(p,q);
    }
    else if (operation.equals("{B}")){
      biconditional(p,q);
    }
    else {
      System.out.println("Not a valid input. Try again.");
    }
    
    
  }
  
  public static void negation(String p, String q){
    System.out.println("not " + p + ", not " + q  + ".");
  }
  
  public static void conjunction(String p, String q){
    System.out.println(p + " and " + q + ".");
  }
  
  public static void disjunction(String p, String q){
    System.out.println(p + " or " + q + ".");
  }
  
  public static void implication(String p, String q){
    System.out.println("If " + p + ", then " + q + ".");
  }
  
  public static void biconditional(String p, String q){
    System.out.println(p + " if and only if " + q + ".");
  }
  
}