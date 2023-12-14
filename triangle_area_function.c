#include <stdio.h>

float getTriangleArea(float base, float height) {
    return (base * height) / 2;
}

int main(void) {
    printf("(3 * 2) / 2 = %.2f\n", getTriangleArea(3, 2));
    printf("(7 * 4) / 2 = %.2f\n", getTriangleArea(7, 4));
    printf("(10 * 10) / 2 = %.2f\n", getTriangleArea(10, 10));
    return 0;
}
