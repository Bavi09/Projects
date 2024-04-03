#include <stdio.h>
#include "pico/stdlib.h"

#define TRUE 1

int main(void) {
    stdio_init_all();

    while (TRUE) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }

    /* Code should not reach here. */
    return 0;
}
