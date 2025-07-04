#include <stdio.h>
#include <omp.h>

void add() {
    double a, b;
    printf("Enter two numbers to add: ");
    scanf("%lf %lf", &a, &b);
    printf("Sum = %.2lf\n", a + b);
}

void subtract() {
    double a, b;
    printf("Enter two numbers to subtract (a - b): ");
    scanf("%lf %lf", &a, &b);
    printf("Difference = %.2lf\n", a - b);
}

void multiply() {
    double a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%lf %lf", &a, &b);
    printf("Product = %.2lf\n", a * b);
}

void divide() {
    double a, b;
    printf("Enter two numbers to divide (a / b): ");
    scanf("%lf %lf", &a, &b);
    if (b != 0)
        printf("Quotient = %.2lf\n", a / b);
    else
        printf("Error: Division by zero\n");
}

// Example of parallel sum using OpenMP
void parallel_sum() {
    int n;
    printf("Enter number of elements to sum: ");
    scanf("%d", &n);

    double arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of array elements = %.2lf\n", sum);
}

int main() {
    int choice;

    while (1) {
        printf("\nCalculator Menu:\n");
        printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Parallel Sum\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: parallel_sum(); break;
            case 6: return 0;
            default: printf("Invalid choice, try again.\n");
        }
    }
}
