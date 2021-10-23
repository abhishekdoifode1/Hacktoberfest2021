import java.util.Scanner;

public class NumberGame {
    public static void main(String [] args) {

        int number = (int) (Math.random() * 100) + 1;
        boolean haswon = false;
        System.out.println("Guess the number beetween 1 and 100");
        Scanner scanner = new Scanner(System.in);

        for (int i = 10; i > 0; i--) {
            System.out.println("You have " + i + " chances left");
            int guess = scanner.nextInt();

            if (number > guess) {
                System.out.println("No! The number is bigger! Try again!");
            } else if (number < guess) {
                System.out.println("No! The number is smaller! Try again!");
            } else {
                haswon = true;
                break;
            }
        }

        if (haswon) {
        System.out.println("You won!");
        } else {
        System.out.println("You lose! The number was " + number);
        }
    }
}