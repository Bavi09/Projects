#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

// Define GPIO pin for motor control
#define MOTOR_PIN 15

// Define ADC pin for potentiometer input
#define POT_PIN 26

// Define maximum and minimum values for potentiometer and motor speed
#define POT_MAX 4095
#define POT_MIN 0
#define MOTOR_MAX_SPEED 65535
#define MOTOR_MIN_SPEED 0

int main() {
    stdio_init_all();
    adc_init();

    // Initialize ADC
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    // Initialize PWM for motor control
    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, MOTOR_MAX_SPEED);
    pwm_config_set_clkdiv(&config, 1.f);
    pwm_init(pwm_gpio_to_slice_num(MOTOR_PIN), &config, true);

    uint16_t pot_value;
    uint16_t motor_speed;

    while (1) {
        // Read potentiometer value
        pot_value = adc_read();

        // Map potentiometer value to motor speed
        motor_speed = (uint16_t)((pot_value - POT_MIN) * (MOTOR_MAX_SPEED - MOTOR_MIN_SPEED) / (POT_MAX - POT_MIN));

        // Control motor speed
        pwm_set_gpio_level(MOTOR_PIN, motor_speed);

        // Add some delay to avoid excessive reading
        sleep_ms(100);
    }

    return 0;
}
