#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

#define ROWS 4
#define COLS 4
#define TRUE 1

const uint8_t row_pins[ROWS] = {10, 11, 16, 17};
const uint8_t col_pins[COLS] = {18, 19, 20, 21};

const char keypad[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

static void keypad_init(void);
static char keypad_scan(void);

int main(void)
{
    stdio_init_all();
    keypad_init();
    char key;

    while (TRUE)
    {
        key = keypad_scan();
        if (key != '\0')
        {
            printf("Key pressed: %c\n", key);
        }
    }

    return 0;
}

static void keypad_init(void)
{
    for (size_t row = 0u; row < ROWS; ++row)
    {
        gpio_init(row_pins[row]);
        gpio_set_dir(row_pins[row], GPIO_OUT);
        gpio_put(row_pins[row], 1);
    }

    for (size_t col = 0u; col < COLS; ++col)
    {
        gpio_init(col_pins[col]);
        gpio_set_dir(col_pins[col], GPIO_IN);
        gpio_pull_up(col_pins[col]);
    }
}

static char keypad_scan(void)
{
    for (size_t row = 0u; row < ROWS; ++row)
    {
        gpio_put(row_pins[row], 0);

        for (size_t col = 0u; col < COLS; ++col)
        {
            if (!gpio_get(col_pins[col]))
            {
                while (!gpio_get(col_pins[col])); // Wait for key release
                gpio_put(row_pins[row], 1);
                return keypad[row][col];
            }
        }

        gpio_put(row_pins[row], 1);
    }

    return '\0'; // No key pressed
}
