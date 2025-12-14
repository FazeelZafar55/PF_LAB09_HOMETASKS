#include <stdio.h>

void calculateMileage(float (*mileage)[7],int vehicles, int days, float *avg){
    for (int i=0;i<vehicles;i++){
        float sum=0;
        for (int j=0;j<days;j++){
            sum += *(*(mileage + i)+ j);
        }
        *(avg+i)= sum/days;
    }
}
void displayCompact(float *avg, int vehicles){
    printf("\n--- Compact Report ---\n");
    printf("Vehicle\tAverage (km/l)\tCategory\n");
    for (int i = 0; i < vehicles; i++) {
        char category[10];
        if (*(avg + i) >= 18)
            sprintf(category, "Efficient");
        else if (*(avg + i) >= 12)
            sprintf(category, "Moderate");
        else
            sprintf(category, "Poor");

        printf("%d\t%.2f\t\t%s\n", i + 1, *(avg + i), category);
    }
}
void displayDetailed(float *avg,int vehicles){
     printf("\n--- Detailed Report ---\n");
    for (int i = 0; i < vehicles; i++) {
        printf("\nVehicle %d:\n", i + 1);
        printf("Average Mileage: %.2f km/l\n", *(avg + i));

        if (*(avg + i) >= 18)
            printf("Category: Efficient\n");
        else if (*(avg + i) >= 12)
            printf("Category: Moderate\n");
        else
            printf("Category: Poor\n");
    }
}
int main() {
    int vehicles = 5, days = 7;
    float mileage[5][7];
    float avg[5];
    int choice;
    printf("Enter daily mileage (in km/l) for 5 vehicles over 7 days:\n");
    for (int i = 0; i < vehicles; i++) {
        printf("\nVehicle %d:\n", i + 1);
        for (int j = 0; j < days; j++) {
            printf("  Day %d: ", j + 1);
            scanf("%f", &mileage[i][j]);
        }
    }
    calculateMileage(mileage, vehicles, days, avg);
    printf("\nSelect report format:\n");
    printf("1. Compact Report\n");
    printf("2. Detailed Report\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    void (*displayPtr)(float *, int);
    if (choice == 1)
        displayPtr = displayCompact;
    else
        displayPtr = displayDetailed;

    displayPtr(avg, vehicles);
    return 0;
}
