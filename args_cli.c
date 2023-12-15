#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_usage() {
    puts("You must provide at least one argument.");
    puts("Usage: args_test [OPTION]... [TEXT]");
    puts("Writes the text to the std output.\n");
    
    puts("Options:");
    puts("-r, --repeat=AMOUNT      repeats message x times.");
    puts("                         e.g.: args_test --repeat 5 \"Hello World\"");
}

void print_argv(int argc, char* argv[]) {
    printf("argc: %i\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%i]: %s\n", i, argv[i]);
    }
}

int contains_only_numbers(char* input) {
    int input_len = strlen(input);

    if (input_len == 0)
        return 0;
 
    for (int i = 0; i < input_len; i++) {
        if (input[i] < 48 || input[i] > 57) {
            return 0;
        }
    }

    return 1;
}

int string_to_int(char* input) {
    int input_len = strlen(input);
    int result = 0;

    for (int i = 0; i < input_len; i++) {
        result = result + (input[i] - 48);
    }

    return result;
}

// Arguments:
// [0] File path
// [1] Message
// [2] Amount to repeat
int main(int argc, char* argv[]) {
    extern char* optarg;
    extern int optind;
    int out, err = 0, rflag = 0;
    char* rvalue;

    while ((out = getopt(argc, argv, "r:")) != -1) {
        switch (out) {
            case 'r':
                rflag = 1;
                rvalue = optarg;
                break;
            default:
                err = 1;
                break;
        }
    }

    if (rflag == 1 && !rvalue) {
        fprintf(stderr, "%s: found -r option, but not its value", argv[0]);
        exit(1);
    }
    else if ((optind + 1) != argc) {
        if (optind == argc) {
            fprintf(stderr, "%s: missing text\n", argv[0]);
        }
        else {
            fprintf(stderr, "%s: text should be in double quotes\n", argv[0]);
        }
        exit(1);
    }
    else if (err) {
        print_usage();
        exit(1);
    }

    int repeatTimes = 1;

    if (rvalue) {
        if (contains_only_numbers(rvalue) == 0) {
            fprintf(stderr, "%s: -r value must be a number", argv[0]);
            exit(1);
        }

        repeatTimes = string_to_int(rvalue);
        if (repeatTimes <= 0)
        {
            fprintf(stderr, "%s: -r value must be greater than 0", argv[0]);
            exit(1);
        }
    }

    for (int i = 0; i < repeatTimes; i++) {
        printf("%s\n", argv[optind]);
    }

    //print_argv(argc, argv);

    return 0;
}
