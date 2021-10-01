import java.util.*;
class a16{
    public static void main(String args[]) {
        Scanner sc = new Scanner (System.in);
        System.out.print("Enter the no. of elements : ");
        int n = sc.nextInt();
        int count = 0;
        System.out.println("Enter the elements : ");
        int [] arr = new int[100];
        for (int i=0;i<n;i++){
            arr[i] = sc.nextInt();
            if (arr[i]!=0){
                count++;
            }
        }
        System.out.println("No. of non-zero elements  : " + count);

    }
}