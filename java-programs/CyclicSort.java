import java.util.*;

public class CyclicSort {
    public static void main(String[] args) {
      
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
          arr[i] = in.nextInt();
        }
        cyclicSort(arr);
        System.out.println(Arrays.toString(arr));
      
    }

    public static void cyclicSort(int[] arr) {
        int n = arr.length;
        int i = 0;
        while(i<n){
            int correctIdx = arr[i]-1;
            if (arr[i] != arr[correctIdx])
                swap(i, correctIdx, arr);
            else
                i++;
        }
    }

    static void swap(int first, int last, int[] arr) {
        int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
    }
}
