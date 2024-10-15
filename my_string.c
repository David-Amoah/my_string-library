//
// Created by David Amoah on 9/30/2024.
//
#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"

struct my_string {
    int cap;
    int size_t;
    char* str;
};

typedef struct my_string my_string_s;

MY_STRING my_string_init_default(void) {
    my_string_s*  my_string = (MY_STRING)malloc(sizeof(MY_STRING));
    if (my_string == NULL) {
        printf("Failed to allocate memory");
        exit(1);
    }
    my_string->cap = 7;
    my_string->size_t = 0;
    my_string->str = (char*)malloc(sizeof(char) * my_string->cap);

    if (my_string->str == NULL) {
        printf("Failed to allocate memory");
        return NULL;
    }
    return my_string;
}

void my_string_destroy(MY_STRING* phMy_string) {
    if (phMy_string != NULL && *phMy_string != NULL) {
        my_string_s* pstr = (my_string_s*)(*phMy_string);
        free(pstr->str);
        free(pstr);
        *phMy_string = NULL;
        printf("Destroyfication complete\n");
    }
}


MY_STRING my_string_init_c_string(const char* c_string) {
    my_string_s* new_string = (my_string_s*)(c_string);

    if (new_string == NULL) {
        printf("Failed to allocate memory");
        exit(1);
    }
    new_string->cap = 4;
    new_string->str = c_string;


    return new_string;

}



