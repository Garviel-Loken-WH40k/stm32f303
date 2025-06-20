void GPIO_Init(void) {
    // Enable the GPIO clock for the LED port (e.g., GPIOA)
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    // Configure the GPIO pin (e.g., PA5) as output
    GPIOA->MODER &= ~(3U << (5 * 2)); // Clear mode bits
    GPIOA->MODER |= (1U << (5 * 2));  // Set mode to output (01)

    // Set the output type to push-pull
    GPIOA->OTYPER &= ~(1U << 5); // Clear output type for PA5

    // Set the output speed to high
    GPIOA->OSPEEDR |= (3U << (5 * 2)); // Set speed to high (11)

    // Set the pull-up/pull-down configuration to no pull-up, no pull-down
    GPIOA->PUPDR &= ~(3U << (5 * 2)); // No pull-up, no pull-down
}

void GPIO_Toggle_LED(void) {
    GPIOA->ODR ^= (1U << 5); // Toggle the state of PA5
}