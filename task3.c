#include <stdio.h>

void bookSeat(int *flight, int seats, int seatNumber) {
    if (seatNumber < 1 || seatNumber > seats) {
        printf("Invalid seat number!\n");
        return;
    }
    if (*(flight + seatNumber - 1) == 1) {
        printf("Seat %d is already booked!\n", seatNumber);
    } else {
        *(flight + seatNumber - 1) = 1;
        printf("Seat %d booked successfully!\n", seatNumber);
    }
}

void cancelSeat(int *flight, int seats, int seatNumber) {
    if (seatNumber < 1 || seatNumber > seats) {
        printf("Invalid seat number!\n");
        return;
    }
    if (*(flight + seatNumber - 1) == 0) {
        printf("Seat %d is already empty!\n", seatNumber);
    } else {
        *(flight + seatNumber - 1) = 0;
        printf("Booking for seat %d cancelled successfully!\n", seatNumber);
    }
}

int countOccupied(int *flight, int seats) {
    int count = 0;
    for (int i = 0; i < seats; i++) {
        if (*(flight + i) == 1)
            count++;
    }
    return count;
}

int main() {
    int flight1[5] = {0};
    int flight2[7] = {0};
    int flight3[9] = {0};

    int *flights[3] = {flight1, flight2, flight3};
    int capacities[3] = {5, 7, 9};

    int choice, flightNum, seatNum;

    do {
        printf("\n==== Flight Seat Booking Tracker ====\n");
        printf("1. Book a Seat\n");
        printf("2. Cancel a Booking\n");
        printf("3. View Occupied Seats per Flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter flight number (1-3): ");
            scanf("%d", &flightNum);
            if (flightNum < 1 || flightNum > 3) {
                printf("Invalid flight number!\n");
                break;
            }
            printf("Enter seat number to book (1-%d): ", capacities[flightNum - 1]);
            scanf("%d", &seatNum);
            bookSeat(flights[flightNum - 1], capacities[flightNum - 1], seatNum);
            break;

        case 2:
            printf("Enter flight number (1-3): ");
            scanf("%d", &flightNum);
            if (flightNum < 1 || flightNum > 3) {
                printf("Invalid flight number!\n");
                break;
            }
            printf("Enter seat number to cancel (1-%d): ", capacities[flightNum - 1]);
            scanf("%d", &seatNum);
            cancelSeat(flights[flightNum - 1], capacities[flightNum - 1], seatNum);
            break;

        case 3:
            for (int i = 0; i < 3; i++) {
                int occupied = countOccupied(flights[i], capacities[i]);
                printf("Flight %d: %d/%d seats occupied\n", i + 1, occupied, capacities[i]);
            }
            break;

        case 4:
            printf("Exiting system. Thank you!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
