/***********************************************************************************************************************
* ファイル名 : timer.c
* 説明 : タイマ割り込みモジュール
***********************************************************************************************************************/

/***********************************************************************************************************************
include
***********************************************************************************************************************/
#include "timer.h"
#include "pico/stdlib.h"

/***********************************************************************************************************************
prototype
***********************************************************************************************************************/
bool timer_callback_1ms(repeating_timer_t *t);

/***********************************************************************************************************************
global
***********************************************************************************************************************/
static repeating_timer_t timer_out;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

/***********************************************************************************************************************
 * Function Name: init_timer
 * Description  : タイマ初期化処理
 *                特定の関数を1msのタイマコールバック関数として登録する
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
void init_timer(void){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    add_repeating_timer_ms(-1, timer_callback_1ms, NULL, &timer_out);//1msごとにtimer_callback_1ms関数をコール
}

/***********************************************************************************************************************
 * Function Name: timer_callback_1ms
 * Description  : タイマコールバック処理
 * Arguments    : *t
 * Return Value : none
 ***********************************************************************************************************************/
bool timer_callback_1ms(repeating_timer_t *t){
    if ( gpio_get(LED_PIN) != 0 ){
        gpio_put(LED_PIN, 0);
    }
    else{
        gpio_put(LED_PIN, 1);
    }
    return true;
}
