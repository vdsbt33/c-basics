#include <stdio.h>

int ageToDays(int age) {
    return age * 365;
}

int main(void) {
    printf("65 * 365 = %i\n", ageToDays(65));
    printf("0 * 365 = %i\n", ageToDays(0));
    printf("20 * 365 = %i\n", ageToDays(20));

    return 0;
}
