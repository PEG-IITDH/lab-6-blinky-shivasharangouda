#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)

int main(void)
{
    int i;
    SYSCTL_RCGCGPIO_R |= (1U << 5); // enable clock for GPIOF
    GPIO_PORTF_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIO_PORTF_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
    while(1)
    {
    GPIO_PORTF_DATA_R |= LED_RED; // turn on red LED       //or we can GPIO_PORTF_DATA_R |= 0x2;
    for (i = 0; i < 800; i++); // delay
    GPIO_PORTF_DATA_R &= ~LED_RED; // turn off red LED
    for (i = 0; i < 800; i++);
    }
}
