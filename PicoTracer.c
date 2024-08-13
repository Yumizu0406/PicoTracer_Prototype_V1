#include "pico/stdlib.h"
#include "driver/timer.h"

void init_driver(void);

int main() {

    init_driver();

    while (true) {

    }
}

void init_driver(void){
    init_timer();
}