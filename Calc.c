#include <stdio.h>

int main() {
    float num1, num2;
    char operation;
    
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    
    printf("Choose an operation (+, -, *, /) or 'q' to quit: ");
    scanf(" %c", &operation);
    
    while(operation != 'q') {
        switch(operation) {
            case '+':
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case '-':
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case '*':
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case '/':
                if(num2 != 0)
                    printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                else
                    printf("Error! Division by zero is not allowed.\n");
                break;
            default:
                printf("Invalid operation. Please try again.\n");
        }
        
        printf("Choose an operation (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &operation);
    }
    
    printf("Exiting...\n");
    return 0;
}