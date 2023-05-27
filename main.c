#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void info(void) {
  printf("Welcome to the Collatz Conjecture Program!\n");
  printf("This program allows you to input a positive integer number and it will follow the rules of the Collatz Conjecture until the number reaches 1.\n");
  printf("\nHow the Collatz Conjecture works:\n");
  printf("1. If the number is even, it's divided by 2.\n");
  printf("2. If the number is odd, it's multiplied by 3 and then 1 is added.\n");
}

void collatzProgram(long long value, bool printSteps, bool stopAfterTime, double timeLimit) {
  int steps = 0;
  double total = 0;

  clock_t start = clock();
  while (value != 1) {
    total = ((double)clock() - start) / CLOCKS_PER_SEC;

    if (stopAfterTime && total >= timeLimit) {
      printf("Time limit reached. Exiting...\n");
      break;
    }

    if (printSteps) printf("%lld ", value);

    value = (value % 2 == 0) ? value / 2 : 3 * value + 1; // Follow the conjecture
    steps++;
  }

  printf("\n\nSteps taken: %d \n", steps);
  printf("Time elapsed: %f seconds\n", total);
}

void menu(void) {
  int choice;
  long long value;
  double timeLimit = 0;

  do {
    bool printSteps = false, stopAfterTime = false;
    printf("\n\nChoose an option:\n");
    printf("1. Run with steps shown\n");
    printf("2. Run with time limit\n");
    printf("3. Run with steps shown and time limit\n");
    printf("4. Exit\n");

    printf("Choice: ");
    scanf("%d", &choice);
    printf("\nGive a value: ");
    scanf("%lld", &value);

    switch (choice) {
      case 1:
        printSteps = true;
        collatzProgram(value, printSteps, stopAfterTime, timeLimit);
        break;
      case 2:
        stopAfterTime = true;
        printf("How many seconds do you want the program to run? ");
        scanf("%lf", &timeLimit);
        collatzProgram(value, printSteps, stopAfterTime, timeLimit);
        break;
      case 3:
        stopAfterTime = true;
        printSteps = true;
        printf("How many seconds do you want the program to run? ");
        scanf("%lf", &timeLimit);
        collatzProgram(value, printSteps, stopAfterTime, timeLimit);
        break;
      case 4:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid choice. Try again.\n");
        break;
    }
  } while (choice != 4);
}

int main(void) {
  info();
  menu();
  return 0;
}
