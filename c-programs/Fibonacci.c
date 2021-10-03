#include <stdio.h>

int main() {


        //We already know that series start with 0 and 1:
        int num1 = 0;
        int num2 = 1;
        int num;
        //Keep a counter so we'll know when to stop:
        int counter = 0;
        printf("Enter an integer:");
        scanf("%d",&num);

        printf("The iterative function result:");

        while (counter < num) {
            printf(" %d", num1);


            int num3 = num2 + num1;
            num1 = num2;
            num2 = num3;
            counter = counter + 1;
        }


    return 0;
}

