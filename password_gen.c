#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_number(int* min, int* max) {
    if (min != NULL && max != NULL) {
        return *min + (rand() % (*max - *min));
    }
    else {
        return rand();
    }
}

char random_letter(int isUppercase) {
    if (isUppercase == 1)
    {
        int lowercase_range[2] = {97, 122+1};
        return random_number(&lowercase_range[0], &lowercase_range[1]);
    }
    else
    {
        int uppercase_range[2] = {65, 90+1};
        return random_number(&uppercase_range[0], &uppercase_range[1]);
    }
}

char random_symbol() {
    return '.';
}

void clear_array(char* text, int size) {
    for (int i = 0; i < size; i++) {
        text[i] = 0;
    }
}

char* generate_password(int size) {
    int boolean_range[2] = {0, 1+1};
    int numbers_range[2] = {0, 9+1};
    int lowercase_letters_range[2] = {0, 5};

    char* password_result = malloc(sizeof(char) * (size + 1));
    clear_array(password_result, size);

    password_result[0] = random_letter(random_number(&boolean_range[0], &boolean_range[1]));

    for (int i = 1; i < size; i++)
    {
        password_result[i] = random_letter(random_number(&boolean_range[0], &boolean_range[1]));
    }
 
    return password_result;
}


int main() {
    int pass_size = 20;
    int pass_amount = 5;

    puts("-- Password Generator --");
    printf("Size: ");
    scanf("%5d", &pass_size);
    puts("");
    printf("Amount: ");
    scanf("%i", &pass_amount);
    puts("");

    puts("Generating password(s)...");

    srand(time(NULL));
    char* password_generated = generate_password(20);
    puts("Password generated:");
    printf("%s", password_generated);
 
    free(password_generated);
    return 0;
}
