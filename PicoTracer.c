#include "pico/stdlib.h"
#include "driver/timer.h"
#include "driver/sw.h"
#include "driver/lineSensor.h"

void init_driver(void);

int main() {

    gpio_init(5);
    gpio_set_dir(5, GPIO_OUT);

    gpio_init(22);
    gpio_set_dir(22, GPIO_OUT);

    init_driver();

    while (true) {
 
    }
}

void init_driver(void){
    init_sw();
    init_lineSensor();
    init_timer();
}
