import java.util.Arrays;

public class BubbleSort {                                                                      
  public static void main(String []args) {                                              
    int i, j, temp;                                                                
    
    int array[] = {29, 7, 5, 9, 50, 8, 17, 1, 6,11};                                                            
                                                             
    for (i = 0; i < ( array.length - 1 ); i++) {                                                 
      for (j = 0; j < array.length - 1 - i; j++) {                                               
        if (array[j+1] < array[j])      
        {
          temp = array[j];                                                             
          array[j] = array[j+1];                                                         
          array[j+1] = temp;                                                          
        }
      }
    }
    System.out.println("Sorted Array : " + Arrays.toString(array));;;
  } 
}
