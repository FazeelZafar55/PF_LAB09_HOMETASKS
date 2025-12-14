#include <stdio.h>

float applyDiscounts(float *prices, int size) {
    float total = 0.0;

    for (int i = 0; i < size; i++) {
        float discount = 0.0, discountedPrice;
        if (*(prices + i) < 1000)
            discount = 0.10; 
        else if (*(prices + i) >= 1000 && *(prices + i) <= 5000)
            discount = 0.15;  
        else
            discount = 0.25;  

        discountedPrice = *(prices + i) - (*(prices + i) * discount);
        total += discountedPrice;
    }
    return total;
}
int main() {
    float prices[5];
    float totalAmount;
    int size = 5;

    printf("Enter prices of 5 products:\n");
    for (int i = 0; i < size; i++) {
        printf("Product %d price: Rs. ", i + 1);
        scanf("%f", &prices[i]);
    }
    totalAmount = applyDiscounts(prices, size);
    float *ptr = &totalAmount;
    printf("\nTotal amount after applying discounts: Rs. %.2f\n", *ptr);

    return 0;
}
