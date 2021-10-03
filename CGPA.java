import java.util.Scanner;

public class CGPA {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("Enter your marks in maths out of 100 : ");
        double maths = in.nextDouble();

        System.out.print("Enter your marks in chem out of 100 : ");
        double chem = in.nextDouble();

        System.out.print("Enter your marks in phy out of 100 : ");
        double phy = in.nextDouble();

        System.out.print("Enter your marks in eng out of 100 : ");
        double eng = in.nextDouble();

        System.out.print("Enter your marks in pe out of 100 : ");
        double pe = in.nextDouble();

        System.out.print("Enter your marks in cs out of 100 : ");
        double cs = in.nextDouble();

        double totalmarks = maths + chem + phy + pe + eng + cs;
        double percentage = totalmarks/600 * 100;

        System.out.println("Total marks = " + totalmarks);
        System.out.println("Marks percentage = " + percentage);

        double CGPA = percentage/9.5;
        System.out.println("CGPA = " + CGPA);
    }
}
