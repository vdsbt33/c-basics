#include <stdio.h>

int main() {
    int my_var[5];
    size_t my_var_length = sizeof(my_var) / sizeof(* my_var);
    my_var[0] = 5;

    for (int i = 0; i < my_var_length; i++)
    {
        printf("value[%i]: %i\n", i, my_var[i]);
    }

    return 0;
}
