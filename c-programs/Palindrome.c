#include<stdio.h>
void main(){
    int b,p=0,d=0,a;
    printf("Enter a number :\n ");
    scanf("%d",&a);
    b=a;
    while(b!=0){
            p=b%10;
            d=(d*10)+p;
            b=b/10;
        }
        if(a==d){
            printf("The number is a palindrome number .");
        }
        else{
            printf("The number is not a palindrome number .");
        }
}