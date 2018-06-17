#include "peripherals.h"


#define ADDR_OFFSET(addr, offset) ((uint32_t*)((uint8_t*)(addr) + 0x20 * GET_PORT(p)))

void select_gpio_out_mode(uint32_t p)
{
    uint32_t register_idx = 2*GET_PORT(p);
    uint32_t pin = GET_PIN(p);
    volatile uint32_t *dir_register;

    if (pin >= 16)
    {
        pin -= 16;
        register_idx++;
    }
    /* Configure function */
    PINSEL[register_idx] &= ~(3 << (pin * 2)); /* Clear the two function bits -> gpio mode (p. 108) */

    /* Configure mode */
    PINMODE[register_idx] &= ~(3 << (pin * 2)); /* Clear the two mode bit -> pull-up resistor */

    /* Configure opendrain */
    PINMODE_OD[GET_PORT(p)] &= ~(1 << GET_PIN(p)); /* Clear bit -> normal (not opendrain) mode */

    /* Set GPIO mode to output */
    dir_register = ADDR_OFFSET(&FIO0DIR, 0x20 * GET_PORT(p));
    *dir_register |= (1 << GET_PIN(p)); /* set bit to 1 -> set pin to output */
}

/* Set pin to HIGH */
void set_pin(uint32_t p)
{
    volatile uint32_t *set_register = ADDR_OFFSET(&FIO0SET, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));

    *mask_register = ~(1 << GET_PIN(p)); /* Affected pin are those whose mask is 0 */
    *set_register = (1 << GET_PIN(p)); /* Set pin to HIGH */
}

/* Clear pin to GND */
void clr_pin(uint32_t p)
{
    volatile uint32_t *clr_register = ADDR_OFFSET(&FIO0CLR, 0x20 * GET_PORT(p));
    volatile uint32_t *mask_register = ADDR_OFFSET(&FIO0MASK, 0x20 * GET_PORT(p));

    *mask_register = ~(1 << GET_PIN(p)); /* Affected pin are those whose mask is 0 */
    *clr_register = (1 << GET_PIN(p)); /* Set pin to GND */
}


void wait(void)
{
    int i;
    uint32_t j;

    for (i=0 ; i < (10000) ; ++i)
        j = FIO0MASK;
    /* avoids an unused variable 'j' warning */
    if (j == (1000000))
        return ;
}

void main(void)
{
    /* First select GPIO mode of LED PINS */
    select_gpio_out_mode(MBED_BASE_LED1);
    select_gpio_out_mode(MBED_BASE_LED2);
    select_gpio_out_mode(MBED_BASE_LED3);
    select_gpio_out_mode(MBED_BASE_LED4);


    select_gpio_out_mode(MBED_BASE_DIP23);
    select_gpio_out_mode(MBED_BASE_DIP24);
    select_gpio_out_mode(MBED_BASE_DIP25);

    int r = 0;
    int v = 0;
    int b = 0;
    while(1)
    {
        /* Turn all leds on */
        /*set_pin(MBED_BASE_LED1); wait();
        set_pin(MBED_BASE_LED2); wait();
        set_pin(MBED_BASE_LED3); wait();
        set_pin(MBED_BASE_LED4); wait();
        */
        /* Clear leds */
        /*clr_pin(MBED_BASE_LED1);wait();
        clr_pin(MBED_BASE_LED2);wait();
        clr_pin(MBED_BASE_LED3);wait();
        clr_pin(MBED_BASE_LED4);wait();
        */
        uint32_t * pin = (uint32_t *) 0x2009C034; // registre FIO1PIN

        *pin |= 1<<23; // 18 = LED1, 20 = LED2, 21 = LED3, 23 = LED4

        for(int r = 0; r <= 100; r+=25){
            for(int i = 1; i <= 1000; i++){
                set_pin(MBED_BASE_DIP23);
                set_pin(MBED_BASE_DIP24);
                set_pin(MBED_BASE_DIP25);
                for(int j = 0; j < 100; j++){
                    if(r == 100 - j) clr_pin(MBED_BASE_DIP23);
                    //if(v == 100 - j) clr_pin(MBED_BASE_DIP24);
                    //if(b == 100 - j) clr_pin(MBED_BASE_DIP25);
                }
            }
        }
        /*if(r <= 100){ // nuance de rouge
            v += r + 25;
            b += r + 25;
        }
        if(v <= 100){
            r += v + 25;
            b += v + 25;
        }
        if(b <= 100){
            r += b + 25;
            v += v + 25;
        }*/
        /*for(int i = 0; i < 8; i++){
            switch(i){
                case 0:
                    set_pin(MBED_BASE_DIP23);
                    set_pin(MBED_BASE_DIP24);
                    set_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                case 1:
                    set_pin(MBED_BASE_DIP23);
                    set_pin(MBED_BASE_DIP24);
                    clr_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                case 2:
                    set_pin(MBED_BASE_DIP23);
                    clr_pin(MBED_BASE_DIP24);
                    set_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                case 3:
                    set_pin(MBED_BASE_DIP23);
                    clr_pin(MBED_BASE_DIP24);
                    clr_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                case 4:
                    clr_pin(MBED_BASE_DIP23);
                    set_pin(MBED_BASE_DIP24);
                    set_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                case 5:
                    clr_pin(MBED_BASE_DIP23);
                    set_pin(MBED_BASE_DIP24);
                    clr_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                case 6:
                    clr_pin(MBED_BASE_DIP23);
                    clr_pin(MBED_BASE_DIP24);
                    set_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
                default:
                    clr_pin(MBED_BASE_DIP23);
                    clr_pin(MBED_BASE_DIP24);
                    clr_pin(MBED_BASE_DIP25);
                    for(int j = 0; j < 10; j++) wait();
                    break;
            }
        }*/
    }
}
