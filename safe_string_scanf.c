#include <stdio.h>

int main(void) {
    char word[20];

    if (scanf("%19s", word) == 1)
        puts(word);
    return 0;
}
