import java.util.Scanner;
class A
{
  private int a,b;
  A(int p,int q)
  {
    System.out.println("\nNormal Constructor Fired");
    a=p;
    b=q;
    System.out.println("First member: "+this.a+"\nSecond member: "+this.b);
  }
  A(A o)
  {
    System.out.println("\nCopy Constructor Fired");
    this.a=o.a;
    this.b=o.b;
    System.out.println("First member: "+this.a+"\nSecond member: "+this.b);
  }
}
public class Main
{
  public static void main(String[] arg)
  {
    
    Scanner sc=new Scanner(System.in);
    System.out.print("Enter number A: ");
    int x=sc.nextInt();
    System.out.print("\nEnter number B: ");
    int y=sc.nextInt();
    A obj1=new A(x,y);
    A obj2=new A(obj1);

    }
}
