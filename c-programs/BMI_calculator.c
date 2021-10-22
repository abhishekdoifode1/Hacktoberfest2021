//simple program to calculate the Body Mass Index(BMI) of a person//
#include <stdio.h>
 
int main()
{
printf("This is a simple code to calculate BMI of a person\n");

float h, w, BMI;
printf("Enter persons weight in KG\n");
scanf("%f", &w);

printf("Enter persons height in Metre\n");
scanf("%f",&h);

BMI = w/(h*h);

printf("BMI of the person is %.2f", BMI);
return 0;
}

}



