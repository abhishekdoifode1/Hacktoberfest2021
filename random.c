#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
int a;
srand(time(0));
a = rand()%1000+1;
printf("%d",a);
return 0;
}