#include "pico/stdlib.h"

#define TRUE 1

int main(void) {
    const uint8_t LED_PIN = PICO_DEFAULT_LED_PIN;  // Use uint32_t for consistency
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (TRUE) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }

    /* Code should not reach here. */
    return 0;  // Explicitly return 0 at the end of main
}