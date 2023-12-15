#include <stdio.h>

int sum(int num1, int num2) {
    return num1 + num2;
}

int main(void) {
    printf("3 + 2 = %i\n", sum(3, 2));
    printf("-3 + -6 = %i\n", sum(-3, -6));
    printf("7 + 3 = %i\n", sum(7, 3));
}
