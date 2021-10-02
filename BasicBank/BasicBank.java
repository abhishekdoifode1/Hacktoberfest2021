package Hacktoberfest2021.BasicBank;

import java.util.Scanner;

public class BasicBank {

    public static void main(String[] args) {
        // create new account by using account class
        Account myAcc = new Account();
        myAcc.task();
    }
}

class Account {

    private int currBalance;

    private void setCurrBalance(int amount) {
        this.currBalance = amount;
    }

    private void showBalance() {
        System.out.println("This is your current account balance: " + this.currBalance);
    }

    private void deposit() {
        System.out.print("Enter the debit amount: ");
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();
        this.currBalance += amount;
        System.out.println("Your current account balance is " + this.currBalance);
    }

    private void withdraw() {
        System.out.print("Enter the credit amount: ");
        Scanner in = new Scanner(System.in);
        int amount = in.nextInt();
        if (amount > this.currBalance) {
            System.out.println("Insufficient balance in current account. Withdrawal can't be processed");
        }
        this.currBalance -= amount;
        System.out.println("Your current account balance is " + this.currBalance);
    }

    private void addInterest() {
        System.out.print("Enter the interest rate: ");
        Scanner in = new Scanner(System.in);
        double rate = in.nextDouble();
        this.currBalance += this.currBalance * rate;
        System.out.println("Your current account balance is " + this.currBalance);
    }

    public void task() {
        System.out.println("Welcome to Basic Bank🙏");
        System.out.println("============================================");
        System.out.print("Enter the amount you want your account to initialise with: ");
        Scanner in = new Scanner(System.in);
        setCurrBalance(in.nextInt());
        System.out.println("Now, your current account balance is " + this.currBalance);

        int taskCode = 0;
        while (taskCode != -1) {
            System.out.println(
                    "Enter the task code: \n(0 for display of account balance;\n1 for deposit;\n2 for withdrawal;\n3 for add interest;\n-1 for safe exit) ");
            taskCode = in.nextInt();

            if (taskCode == 0) {
                showBalance();
            } else if (taskCode == 1) {
                deposit();
            } else if (taskCode == 2) {
                withdraw();
            } else if (taskCode == 3) {
                addInterest();
            } else if (taskCode == -1) {
                System.out.println("Safe Exit");
            }
        }
    }
}