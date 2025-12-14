#include <stdio.h>

void analyzeRainfall(float *rainfall, int days) {
    float sum = 0.0, avg = 0.0, max = *rainfall;
    int maxDay = 1;
    int aboveAvgDays = 0;

    for (int i = 0; i < days; i++) {
        sum += *(rainfall + i);
        if (*(rainfall + i) > max) {
            max = *(rainfall + i);
            maxDay = i + 1;
        }
    }
    avg = sum / days;
    for (int i = 0; i < days; i++) {
        if (*(rainfall + i) > avg)
            aboveAvgDays++;
    }
    printf("\nAverage Rainfall: %.2f mm\n", avg);
    printf("Maximum Rainfall: %.2f mm on Day %d\n", max, maxDay);

    if (aboveAvgDays > 3)
        printf("Weather Status: Rainy Week \n");
    else
        printf("Weather Status: Normal Week \n");
}
int main() {
    float rainfall[7];
    int days = 7;

    printf("Enter rainfall data (in mm) for 7 days:\n");
    for (int i = 0; i < days; i++) {
        printf("Day %d: ", i + 1);
        scanf("%f", &rainfall[i]);
    }
    analyzeRainfall(rainfall, days);
    return 0;
}
