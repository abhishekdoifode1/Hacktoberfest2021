import java.io.*;
public class getInput {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    public String getUserInput(String remark) {
        String input = null;
        System.out.print(remark + " ");
        try{
            input= in.readLine();
            if (input.length()==0)
            return null;
        }
        catch (IOException e) {
            System.out.println("IOException: " + e);
        }
        return input;
    }
}
