import java.io.*;
class transpose
{
    public static void main()throws IOException
    {int m,n;
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the Limits");
        m=Integer.parseInt(in.readLine());
        n=Integer.parseInt(in.readLine());
        int a[][]=new int[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.println("Enter the values");
                a[i][j]=Integer.parseInt(in.readLine());
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(a[i][j]+" ");
            }
            System.out.println();
        }
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j||j>i)
                {
                    System.out.print(a[i][j]+" ");
                }
            }
        }
    }
}
                
