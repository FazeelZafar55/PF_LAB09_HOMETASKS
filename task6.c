#include <stdio.h>

void calculateTotal(float *price, int *stock, float *total, int size) {
    for (int i = 0; i < size; i++) {
        *(total + i) = (*(price + i)) * (*(stock + i));
    }
}
void applyDiscount(float *total, int *stock, int size) {
    for (int i = 0; i < size; i++) {
        float discount = 0.0;
        if (*(stock + i) < 3)
            discount = 0.0;          
        else if (*(stock + i) >= 3 && *(stock + i) <= 5)
            discount = 0.10;          
        else
            discount = 0.20;          
            *(total + i) = *(total + i) - (*(total + i) * discount);
    }
}
int main() {
    int size = 5;
    float price[5];
    int stock[5];
    float total[5];
    printf("Enter price and stock for 5 books:\n");
    for (int i = 0; i < size; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("  Price: Rs. ");
        scanf("%f", &price[i]);
        printf("  Stock (no. of copies): ");
        scanf("%d", &stock[i]);
    }
    calculateTotal(price, stock, total, size);

    void (*discountPtr)(float *, int *, int) = applyDiscount;
    discountPtr(total, stock, size);

    printf("\n--- Library Book Summary ---\n");
    for (int i = 0; i < size; i++) {
        printf("Book %d Final Total Value: Rs. %.2f\n", i + 1, total[i]);
    }
    return 0;
}
