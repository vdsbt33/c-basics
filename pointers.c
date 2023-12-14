#include <stdio.h>

void addOne(int* number) {
    *number = *number + 1;
}

void checkNumber(int* number) {
    printf("number: %p\n", number);
    printf("&number: %p\n",&number);
    printf("*number: %i\n",*number);
}

int main(void) {
    int number = 5;
    checkNumber(&number);
    printf("Original number: %i\n", number);

    for (int i = 0; i < 5; i++) {
        addOne(&number);
        printf("Previous + 1 = %i\n", number);
    }

    return 0;
}
