#include "func.h"

int addition(int numericA, int numericB) {

    int result = numericA + numericB;

    return result;
}
int substraction(int numericA, int numericB) {

    int result = numericA - numericB;

    return result;
}

int multiplication(int numericA, int numericB) {

    int result = numericA * numericB;

    return result;
}

int segmentation(int numericA, int numericB) {

    int result = numericA / numericB;

    return result;
}


int calkuljator() {

    char in[11];
    int choice;
    int numericA = 0;
    int numericB = 0;


//interface

    do {
        do {

            system("clear");
            printf("Choice operation:\n1.+\n2.-\n3.*\n4./\n5.EXIT\n\nYour choice:");

            scanf("%s", in);
            if (in < 0) {
                printf("\n\nError of gets");
                return 0;
            }

            if (atoi(in) < 1 || atoi(in) > 5) {

                printf("\nPlease, enter correct numeric, 1 - 5\n");
                sleep(5);
                system("clear");
            }

            if (in[0] == '5') { return 0; }

        } while (in[0] < '1' || in[0] > '5');

        choice = in[0] - '0';

        printf("\nEnter first numeric: ");
        scanf("%s", in);

        if (in < 0) {
            printf("\n\nError of gets");
            return 0;
        }

        numericA = atoi(in);
        printf("\nEnter second numeric: ");
        scanf("%s", in);

        if (in < 0) {
            printf("\n\nError of gets");
            return 0;
        }

        numericB = atoi(in);

//Choice of function

        switch(choice) {

        case 1:
            printf("\nResult: %d\n\n", addition(numericA, numericB));
            break;
        case 2:
            printf("\nResult: %d\n\n", substraction(numericA, numericB));
            break;
        case 3:
            printf("\nResult: %d\n\n", multiplication(numericA, numericB));
            break;
        case 4:
            printf("\n\nResult: %d\n\n", segmentation(numericA, numericB));
            break;
        }

        sleep(10);

    } while(1);

    return 0;

}
