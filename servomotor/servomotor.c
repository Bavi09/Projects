#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "pico/time.h"

// Define GPIO pin for servo motor PWM output
#define PWM_PIN 0

// Define ADC pin for potentiometer input
#define POT_PIN 28

// Define PWM frequency and duty cycle range for the servo motor
#define SERVO_FREQ 50
#define SERVO_MIN_DUTY_CYCLE 1000
#define SERVO_MAX_DUTY_CYCLE 9000

int main() {
    stdio_init_all();

    // Initialize PWM for servo control
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    pwm_set_wrap(slice_num, SERVO_MAX_DUTY_CYCLE);
    pwm_set_clkdiv(slice_num, 16.0f);
    pwm_set_enabled(slice_num, true);

    // Initialize ADC for potentiometer input
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0);

    // Main loop
    while (1) {
        // Read potentiometer value
        uint16_t pot_value = adc_read();

        // Map potentiometer value to servo duty cycle
        uint16_t servo_duty_cycle = (pot_value * (SERVO_MAX_DUTY_CYCLE - SERVO_MIN_DUTY_CYCLE) / 65535) + SERVO_MIN_DUTY_CYCLE;

        // Set servo duty cycle
        pwm_set_chan_level(slice_num, PWM_CHAN_A, servo_duty_cycle);

        // Add some delay
        sleep_ms(100);
    }

    return 0;
}
