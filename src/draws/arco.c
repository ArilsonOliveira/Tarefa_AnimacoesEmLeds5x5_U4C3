#include "arco.h"
#include "leds.h"

static uint32_t new_piskel_data[18][25][3] = {
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 100}, 
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 100, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 100, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 100}, 
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 0, 0}, {0, 100, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {100, 0, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 0, 0}, {0, 100, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 100},
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 0, 0}, {0, 100, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 100, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 100}, 
        {0, 0, 100}, {0, 0, 0}, {0, 100, 0}, {0, 0, 0}, {0, 0, 0}, 
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 100},
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 100, 0}, {0, 0, 100},
        {0, 0, 100}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 0},
        {0, 100, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 100},
        {0, 0, 100}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 100, 0}, {0, 100, 0}, {0, 0, 100}
    },
    {
        {0, 0, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 0, 100},
        {0, 0, 100}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0},
        {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 100},
        {0, 0, 100}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 100, 0},
        {0, 0, 0}, {0, 100, 0}, {0, 100, 0}, {0, 100, 0}, {0, 0, 100}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
    {
        {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
    {
        {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {0, 0, 0}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0},
        {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {100, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
        {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
        },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0}, {100, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },   
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {100, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    },
    {
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},
        {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}
    }
};


void arco() {
    int quantidade_frames = sizeof(new_piskel_data) / sizeof(new_piskel_data[0]);

    for (int i = 0; i < quantidade_frames; i++) {
        Leds_Show_All(new_piskel_data[i], true);
        sleep_ms(500);
    }
}

void desligar_leds() {
    Leds_Show_All(NULL, false);
}
