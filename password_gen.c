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

char random_number_char() {
    int num_range[2] = {48, 58};
    return random_number(&num_range[0], &num_range[1]);
}

char random_letter(int isUppercase) {
    if (isUppercase == 1)
    {
        int lowercase_range[2] = {97, 123};
        return random_number(&lowercase_range[0], &lowercase_range[1]);
    }
    else
    {
        int uppercase_range[2] = {65, 91};
        return random_number(&uppercase_range[0], &uppercase_range[1]);
    }
}

char random_symbol() {
    int symbols_range[2] = {0, 6};
    int symbols_list[5] = {33, 36, 42, 46, 47};
    return symbols_list[random_number(&symbols_range[0], &symbols_range[1])];
}

void clear_array(char* text, int size) {
    for (int i = 0; i < size; i++) {
        text[i] = 0;
    }
}

char* generate_password(int size) {
    int random_char_range[2] = {0, 4};
    int boolean_range[2] = {0, 2};
    int numbers_range[2] = {0, 10};

    char* password_result = malloc(sizeof(char) * (size + 1));
    clear_array(password_result, size);

    password_result[0] = random_letter(random_number(&boolean_range[0], &boolean_range[1]));

    for (int i = 1; i < size; i++)
    {
        int random_char = random_number(&random_char_range[0], &random_char_range[1]);

        // Number
        if (random_char == 0) {
            password_result[i] = random_number_char();
        }

        // Lowercase letter
        else if (random_char == 1) {
            password_result[i] = random_letter(0);
        }

        // Uppercase letter
        else if (random_char == 2) {
            password_result[i] = random_letter(1);
        }

        // Symbol
        else if (random_char == 3) {
            password_result[i] = random_symbol();
        }

        else {
            password_result[i] = '?';
        }
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

    for (int i = 0; i < pass_amount; i++)
    {
        char* password_generated = generate_password(pass_size);
        printf("%s\n", password_generated);
 
        free(password_generated);
    }
    puts("\nPasswords generated.");
    return 0;
}
