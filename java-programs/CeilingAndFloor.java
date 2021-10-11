package Practice;

import java.util.Scanner;

public class CeilingAndFloor {
    public static void main(String[] args) {
        Scanner s= new Scanner(System.in);
        int n= s.nextInt();
        int[] a= new int[n];
        for (int i=0 ; i<n ; i++){
            a[i]= s.nextInt();
        }
        int d= s.nextInt();
        int Ceil= CeilSearch(a, 0, n-1, d);
        int Floor= FloorSearch(a, 0, n-1, d);
        if (Ceil == -1){
            System.out.println("Ceiling of " +d+ " does not exist");
        }
        else System.out.println("Ceiling= " + a[Ceil]);
        if (Floor == -1){
            System.out.println("Floor of " +d+ " does not exist");
        }
        else System.out.println("Floor=" + a[Floor]);
    }

    static int FloorSearch(int arr[], int low, int high, int x){
        int i;
        if (x >= arr[high]){
            return high;
        }
        for (i=low ; i<high ; i++){
            /*if (arr[i] == x){
                return i;
            }*/

            if (arr[i] < x && arr[i+1] >= x){
                return i;
            }
        }
        return -1;
    }

    static int CeilSearch(int arr[], int low, int high, int x){
        int i;
        if (x <= arr[low]){
            return low;
        }
        for (i=low ; i<high ; i++){
            if (arr[i] == x){
                return i;
            }

            if (arr[i] < x && arr[i+1] >= x){
                return i+1;
            }
        }
        return -1;
    }
}
