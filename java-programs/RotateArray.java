import java.io.*;
import java.util.*;

public class Main{
  public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + " ");
    }
    System.out.println(sb);
  }

  public static void rotate(int[] a, int k){
    boolean flag = false;
    int size = a.length;
    
    if(k<0){
         k = k*-1;
         flag = true;
     }
     
     while(k>size){
         k = k%size;
     }
     
     
     
     if(flag){
         k = size-k;
     }
    
    
    while(k!=0){
        int i = size - 1;
        int temp = a[i];
        
        while(i!=0){
            a[i] = a[i-1];
            i--;
        }
        a[0] = temp;
        k--;
    }
  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }
    int k = Integer.parseInt(br.readLine());

    rotate(a, k);
    display(a);
 }

}
