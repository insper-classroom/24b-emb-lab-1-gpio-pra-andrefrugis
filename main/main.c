/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"


const int led = 5;
const int button = 28;
const int m1 = 27;
const int m2 = 26;
const int m3 = 22;
const int m4 = 21;



int main() {
    stdio_init_all();
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);

    gpio_init(button);
    gpio_set_dir(button, GPIO_IN);
    gpio_pull_up(button);

    gpio_init(m1);
    gpio_set_dir(m1, GPIO_OUT);
    gpio_init(m2);
    gpio_set_dir(m2, GPIO_OUT);
    gpio_init(m3);
    gpio_set_dir(m3, GPIO_OUT);
    gpio_init(m4);
    gpio_set_dir(m4, GPIO_OUT);


    while (true) {

        if(!gpio_get(button)){
            gpio_put(led, 1);
            
            for (int i=0; i<512; i++){
                printf("entrou\n");
                gpio_put(m1,1);
                sleep_ms(20);
                gpio_put(m1,0);
                gpio_put(m2,1);
                sleep_ms(20);
                gpio_put(m2,0);
                gpio_put(m3,1);
                sleep_ms(20);
                gpio_put(m3,0);
                gpio_put(m4,1);
                sleep_ms(20);
                gpio_put(m4,0);

            }
            gpio_put(led, 0);   
            
        }

        else if (gpio_get(button)){
            gpio_put(led, 0);
            sleep_ms(100);
        }        
    }
}
