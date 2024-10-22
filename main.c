#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "assert.h"


int main(int argc, char* argv[]) {

    MY_STRING hMy_string = NULL;

    MY_STRING app = NULL;
    MY_STRING apple = NULL;


    hMy_string = my_string_init_c_string("hi");

    app = my_string_init_c_string("psychology");
    apple = my_string_init_c_string("psychology");
    assert(my_string_compare(app,apple) == 0);


    app = my_string_init_c_string("app");
    apple = my_string_init_c_string("apple");
    assert(my_string_compare(app,apple) == -1);

    app = my_string_init_c_string("apple");
    apple = my_string_init_c_string("app");
    assert(my_string_compare(app,apple) == 1);

    app = my_string_init_c_string("banana");
    apple = my_string_init_c_string("banana");
    assert(my_string_compare(app,apple) == 0);

    app = my_string_init_c_string("dog");
    apple = my_string_init_c_string("do");
    assert(my_string_compare(app,apple) == 1);

    app = my_string_init_c_string("elephant");
    apple = my_string_init_c_string("elephant");
    assert(my_string_compare(app,apple) == 0);

    app = my_string_init_c_string("Apple");
    apple = my_string_init_c_string("apple");
    assert(my_string_compare(app,apple) == -1);

    printf("%d\n", my_string_get_size(apple));


    my_string_destroy(&apple);

    printf("%d", my_string_get_size(apple));


    return 0;
}