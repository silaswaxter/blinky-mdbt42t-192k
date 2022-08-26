#include <stdbool.h>
#include <stdint.h>

#include "nrf_gpio.h"
#include "nrfx_systick.h"

#define INDICATOR_LED 20

int main(void)
{
    nrf_gpio_cfg_output(INDICATOR_LED);
    nrfx_systick_init();

    while (true)
    {
        //turn off (active low)
        nrf_gpio_pin_set(INDICATOR_LED);
        nrfx_systick_delay_ms(500);
        //turn on (active low)
        nrf_gpio_pin_clear(INDICATOR_LED);
        nrfx_systick_delay_ms(500);
    }
}
