#include <stdio.h>

void func_A(char* text) {
    printf("func_A says: %s\n", text);
}

void call_function(void (*target_function)(char*), char text[]) {
    target_function(text);
}

int main(void) {
    char text[] = "Hello World!";
    call_function(func_A, text);
}
