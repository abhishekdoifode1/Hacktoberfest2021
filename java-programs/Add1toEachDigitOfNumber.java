import java.util.Scanner;

class Add1toEachDigitOfNumber
{
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    int a=sc.nextInt();
    int num=a;
    int rem=0,k=0;
    int []arr=new int[4];
    while(a>0)
    {
      rem=a%10;
      arr[k++]=rem;
      a/=10;
    }
    
    if(arr[0]==9)
      arr[0]=-1;
    if(arr[1]==9)
      arr[1]=-1;
    if(arr[2]==9)
      arr[2]=-1;
    if(arr[3]==9)
      arr[3]=-1;
    
    int i,n=0;
    for(i=0;i<k;i++)
    {
      n+=(arr[i]+1)*(Math.pow(10,i));
    }
    System.out.println(n);
  }
}

// By Vishal Bhola