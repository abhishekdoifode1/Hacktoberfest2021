#include <stdio.h>

void main () {
  char name[100], link[100];

  printf("Welcome to hacktoberfest event!\n\n");
  printf("Enter your name: ");
  scanf(" %[^\n]s", &name);

  printf("Hello %s! put your link github here: ", name);
  scanf(" %s", &link);

  printf("\n\n\n---------------\n");
  printf("Your name: %s\n", name);
  printf("Your github profile: %s\n\n", link);

  printf("Happy hacking!\n");

  }
