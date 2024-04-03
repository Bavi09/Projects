#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define TRUE 1

int main(void) {
    stdio_init_all();

    adc_init();
    adc_gpio_init(26); 
    adc_select_input(0); // Set GPIO 26 as the ADC input
    uint16_t reading;
    while (TRUE) {
        reading  = adc_read(); // Read analog value from ADC
        printf("ADC: %u\n", reading);
        sleep_ms(200); // Wait for 200 milliseconds
    }

    return 0;
}
