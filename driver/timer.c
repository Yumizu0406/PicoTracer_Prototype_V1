#include "timer.h"
#include "pico/stdlib.h"

bool timer_callback_1ms(repeating_timer_t *t);

static repeating_timer_t timer_out;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void init_timer(void){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    add_repeating_timer_ms(-1, timer_callback_1ms, NULL, &timer_out);
}

bool timer_callback_1ms(repeating_timer_t *t){
    if ( gpio_get(LED_PIN) != 0 ){
        gpio_put(LED_PIN, 0);
    }
    else{
        gpio_put(LED_PIN, 1);
    }
    return true;
}
