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

//MY_STRING my_string_init_default(void) {
//    my_string_s*  my_string = (my_string_s*)malloc(sizeof(my_string_s));
//    if (my_string == NULL) {
//        printf("Failed to allocate memory");
//        exit(1);
//    }
//    my_string->cap = 7;
//    my_string->size_t = 0;
//    my_string->str = (char*)malloc(sizeof(char) * my_string->cap);
//
//    if (my_string->str == NULL) {
//        printf("Failed to allocate memory");
//        return NULL;
//    }
//    return my_string;
//}

MY_STRING my_string_init_default(void) {
    my_string_s* p_string = (my_string_s*) malloc(sizeof(my_string_s ));
    if (p_string != NULL){
        p_string->cap = 7;
        p_string->size_t = 0;
        p_string->str = (char*)malloc(sizeof(char)* p_string->cap);
        if (p_string->str == NULL) {
            free(p_string);
            return NULL;
        }
    }
    return p_string;
}

void my_string_destroy(MY_STRING* phMy_string) {
    if (phMy_string != NULL && *phMy_string != NULL) {
        my_string_s* pstr = (my_string_s*)(*phMy_string);
        if (pstr != NULL) {
            free(pstr->str);
        }
        free(pstr);
        *phMy_string = NULL;
        //printf("Destroyfication complete\n");
    }
}


MY_STRING my_string_init_c_string(const char* c_string) {
    my_string_s*  my_string = (my_string_s*)malloc(sizeof(my_string_s));

    if (my_string == NULL) {
        printf("Failed to allocate memory");
        exit(1);
    }

    size_t length = 0;
    while(c_string[length] != '\0') {
        length++;
    }

    my_string->size_t = length;
    my_string->cap = length + 1;

    my_string->str = (char*)malloc(my_string->cap * sizeof(char));

    if (my_string->str == NULL) {
        free(my_string); // Free the allocated structure
        printf("Failed to allocate memory for string content\n");
        exit(1);
    }

    for (size_t i = 0; i < length; i ++) {
        my_string->str[i] = c_string[i];
    }
    my_string->str[length] = '\0';
    return my_string;

}

int my_string_get_capacity(MY_STRING hMy_string) {
    my_string_s* myString = (my_string_s*)hMy_string;
    if (myString == NULL) {
        printf("Invalid string\n");
        return -1;
    }
    size_t cap = myString->cap;
    return (int)cap;
}

int my_string_get_size(MY_STRING hMy_string) {
    my_string_s* myString = (my_string_s*)hMy_string;
    if (myString == NULL) {
        printf("Invalid string\n");
        return -1;
    }
    size_t size = myString->size_t;
    return (int)size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string) {
    my_string_s* lString = (my_string_s*)hLeft_string;
    my_string_s* rString = (my_string_s*)hRight_string;


    int i = 0;

    while (i < lString->size_t && i < rString->size_t) {

        if (lString->str[i] != rString->str[i]) {

            if (lString->str[i] < rString->str[i]) {
                return -1;
            } else {
                return 1;
            }
        }
        i++;
    }

    if (lString->size_t < rString->size_t) {
        return -1;
    } else if (lString->size_t > rString->size_t) {
        return 1;
    }


    return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp) {
    my_string_s* new_string = (my_string_s*)hMy_string;
    if (new_string == NULL || fp == NULL) {
        return FAILURE;
    }
    new_string->size_t = 0;

    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\n') {
            break;
        }

    }


    return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp) {

    return FAILURE;
}


