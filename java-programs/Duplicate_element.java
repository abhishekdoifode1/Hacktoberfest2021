import java.util.Scanner;
class Duplicate_element
{
    public static void main(String args[]) 
    {
        Scanner input = new Scanner(System.in);
        int a[] = new int[5];
        int index = 0; 
        int count = 0;
        int num = 0;
        while (count < a.length) 
        {
            System.out.println("Enter number: ");
            num = input.nextInt();

            if ((num >= 10) && (num <= 1000))
            {
                boolean digit = true;
                count++;

                for (int i = 0; i < a.length; i++) 
                {   
                    if (a[i] == num)
                    {
                        digit = false;
                        count--;
                    }
                }  

                
                if (digit) 
                {
                    a[index] = num;
                    index++;
                } 

                else
                {
                    System.out.printf("Duplicate number found \n");
                }
            }

            else
            {
               System.out.println("-----Number must be between 10 and 100----");
            }
            System.out.print("\nUnique set: ");
            for (int i =0;  i < count; i++) 
            {
                    System.out.print(a[i] +" ");
            }
            System.out.println();  
        } 
     } 
} 