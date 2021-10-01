//QUICK SORT 
//PARTITION TECHNIQUE - HOARSE PARTITION 
import java.util.*;
import java.io.*;
public class MyClass {
    public static void swap(int arr[],int a,int b)
    {
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    public static int[] hoarsePartition(int arr[],int l,int h)
    {
        int n=arr.length;
        int pivot=arr[0];//first element as a pivot
        int i=l-1,j=h+1;
       while(true)
        {
            do{
                i++;
            }while(arr[i]<pivot);
        
            do{
                j--;
            }while(arr[j]>pivot);
            if(i>=j)
            {
                System.out.println("pivot index is "+j);
                return arr;
            }
            swap(arr,i,j);
        }
        
    }
    public static void main(String args[]) {
        
      Scanner in=new Scanner(System.in);
      int n=in.nextInt();
      int arr[]=new int[n];
      for(int i=0;i<n;i++)
      {
          arr[i]=in.nextInt();
      }
      int l=in.nextInt();
      int h=in.nextInt();
      System.out.println(Arrays.toString(hoarsePartition(arr,l,h)));
    }
}

