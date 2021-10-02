import java.util.Scanner;

public class HCF {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n1=scanner.nextInt();
        int n2=scanner.nextInt();
        int temp;
        while (n2 > 0)
        {
            temp = n2;
            n2 = n1% n2;
            n1 = temp;
        }
        System.out.println("hcf="+n1);
    }
}
