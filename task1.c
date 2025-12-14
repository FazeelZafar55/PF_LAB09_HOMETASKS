#include <stdio.h>

void calculateDenominations(int amount, int *denominations, int *count, int size) {
    for (int i = 0; i < size; i++) {
        count[i] = amount / denominations[i];
        amount = amount % denominations[i];
    }
}
int main() {
    int amount;
    int denominations[3] = {5000, 1000, 500};  
    int count[3] = {0}; 
    int size = 3;
    printf("Enter the amount you want to withdraw: ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
    }
    else if (amount % 50 != 0) {
        printf("Invalid amount! Please enter an amount that is a multiple of 50.\n");
    }
    else {
        calculateDenominations(amount, denominations, count, size);

        printf("\nCash Dispensed:\n");
        for (int i = 0; i < size; i++) {
            if (count[i] > 0)
                printf("Rs. %d x %d = Rs. %d\n", denominations[i], count[i], denominations[i] * count[i]);
        }
    }

    return 0;
}
