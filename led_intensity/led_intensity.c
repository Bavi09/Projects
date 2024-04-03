#include <stdio.h>
#include <stdint.h>  // Include the header for uint32_t
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#define POTENTIOMETER_PIN 26
#define LED_PIN 14

#define PWM_RANGE 65535
#define TRUE 1

static void setup_pwm(void);

int main(void) {
    stdio_init_all();

    adc_init();
    adc_gpio_init(POTENTIOMETER_PIN);
    adc_select_input(0);

    setup_pwm();
    uint16_t pot_value;
    uint32_t duty_cycle;

    while (TRUE) {
        pot_value = adc_read();

        /* Scale potentiometer value to fit within PWM range */
        duty_cycle = (pot_value * PWM_RANGE) / 4095; /* 4095 is the maximum value of the ADC */

        if (pot_value <= 500) {
            duty_cycle = 0;
        }

        pwm_set_gpio_level(LED_PIN, duty_cycle);
        printf("Analog value is: %u\n", pot_value);
        sleep_ms(250);
    }

    return 0;
}

static void setup_pwm(void) {
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    pwm_set_wrap(pwm_gpio_to_slice_num(LED_PIN), PWM_RANGE);
    pwm_set_clkdiv(pwm_gpio_to_slice_num(LED_PIN), 16.0);
    pwm_set_enabled(pwm_gpio_to_slice_num(LED_PIN), true);
}
