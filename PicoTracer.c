#include "pico/stdlib.h"
#include "driver/timer.h"
#include "driver/sw.h"

void init_driver(void);

int main() {

    gpio_init(5);
    gpio_set_dir(5, GPIO_OUT);

    init_driver();

    while (true) {
        if ( isSwStatus(SW_EXE, push) ){
            gpio_put(5, 0);
        }
        else{
            gpio_put(5, 1);
        }

    }
}

void init_driver(void){
    init_sw();
    init_timer();
}