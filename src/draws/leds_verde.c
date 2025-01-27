#include "pico/stdlib.h"
#include "leds_verde.h"
#include "leds.h" 


static uint32_t frame_verde[][3] = {
    {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0},
    {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0},
    {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0},
    {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0},
    {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0}, {0, 50, 0}
};

void leds_verde() {
    Leds_Show_All(frame_verde, true); 
    sleep_ms(5000);                   
    leds_off();                       
}
