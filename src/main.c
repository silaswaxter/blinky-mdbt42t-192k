#include <stdbool.h>
#include <stdint.h>

#include "nrf_gpio.h"

#define INDICATOR_LED 20

// only works with gcc `-O0` flag which disables all optimizations
void bad_delay(void){
    for(int i = 0; i < 1000000; i++){

    }
}

int main(void)
{
    nrf_gpio_cfg_output(INDICATOR_LED);

    while (true)
    {
        //turn off
        nrf_gpio_pin_set(INDICATOR_LED);
        bad_delay();
        //turn on
        nrf_gpio_pin_clear(INDICATOR_LED);
        bad_delay();

    }
}
