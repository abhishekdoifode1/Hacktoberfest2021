class Main{
    static int fibonacci(int num) 
    { 
        int x = 0, y = 1, z; 
        if (num== 0) 
            return x; 
        for (int i = 2; i <= num; i++) 
        { 
            z = x + y; 
            x = y; 
            y = z; 
        } 
        return y; 
    } 
  
    public static void main (String args[]) 
    { 
        int num = 15; 
        System.out.println(fibonacci(num)); 
    } 

}