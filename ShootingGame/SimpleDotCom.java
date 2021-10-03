import java.io.*;

public class simpleDotcom {
    public static void main(String[] args) throws Exception {
        BufferedReader size = new BufferedReader(new InputStreamReader(System.in));
        getInput n = new getInput();
        simpleDotcomTester dot = new simpleDotcomTester();
        System.out.print("Enter the Difficulty Level:-\nE: Easy\nM: Medium\nH: Hard\n");
        String choice = size.readLine();
        int m = 0, p = 0, rand = 0, trial = 0;
        if (choice.toLowerCase().charAt(0) == 'e') {
            m = 5;
            p = 3;
        }
        else if (choice.toLowerCase().charAt(0) == 'm') {
            m = 10;
            p = 2;
        }
        else if (choice.toLowerCase().charAt(0) == 'h') {
            m = 15;
            p = 2;
        }
        int arr[] = new int[p];
        for (int i = 0; i < p; i++) {
            rand = (int) (Math.random() * m) % m;
            arr[i] = rand;
        }
        boolean isAlive = true;
        int killCount = 0;
        while (isAlive) {
            String q = n.getUserInput("Enter your choice:");
            String h = dot.checking(q, arr, p);
            if (h == "Kill!")
                killCount++;
            if (killCount == p)
                isAlive = false;
            trial++;
        }
        System.out.println("You took "+trial+" chances to end the game");
    }
}
