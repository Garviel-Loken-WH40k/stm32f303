#include "gpio.h"

int main(void) {
    // Initialize the GPIO for the LED
    gpio_init();

    while (1) {
        // Toggle the LED
        gpio_toggle_led();
        
        // Simple delay
        for (volatile int i = 0; i < 100000; i++);
    }

    return 0;
}