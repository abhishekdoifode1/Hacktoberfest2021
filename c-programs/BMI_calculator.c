#include <stdio.h>

int main() {
	  double x,y;
	      printf("Enter your height in meter:");
		    scanf("%lf",&x);
		        printf("Enter your weight in KiloGrams (kg):");
			    scanf("%lf",&y);
			        double bmi=y/(x*x);
				    printf("your BMI is : %lf", bmi);

				        return 0;
}



