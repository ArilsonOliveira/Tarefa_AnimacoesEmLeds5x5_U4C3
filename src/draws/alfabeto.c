#include "leds.h"
#include "buzzer.h"

// letra A
static uint32_t letra_A[][3] = {
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 1 (da direita para a esquerda)
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 2 (da esquerda para a direita)
    {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, // Linha 3 (da direita para a esquerda)
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 4 (da esquerda para a direita)
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 0}   // Linha 5 (da direita para a esquerda)
};


// Letra C
static uint32_t letra_C[][3] = {
    {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50},  // Linha 1
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 3
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}   // Linha 5
};
// letra D

static uint32_t letra_D[][3] = {
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50},  // Linha 1
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 2
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 3
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},    // Linha 4
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}   // Linha 5
};

// letra E

static uint32_t letra_E[][3] = {
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}   // Linha 5
};

// E
 static uint32_t frame_1[][3] = {
    {0, 0, 0}, {0, 0, 00}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 0}, {0, 0, 00}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
} ;

// E |

static uint32_t frame_2[][3] = {
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},    // Linha 2
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},    // Linha 4
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
}  ;

// E |*

static uint32_t frame_3[][3] = {
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}
}  ;

// E |*|
static uint32_t frame_4[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 3
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}
}  ;

// E|*|*

static uint32_t frame_5[][3] = {
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},  // Linha 1
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 3
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}
}  ;

// M

static uint32_t frame_6[][3] = {
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},  // Linha 1
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},    // Linha 2
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 3
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
}  ;

// *|*| 

static uint32_t frame_7[][3] = {
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 3
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 4
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
}  ;

// |*| |

static uint32_t frame_8[][3] = {
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0},  // Linha 1
    {0, 0, 0}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 2
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 3
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 4
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}
}  ;

// *| |*
static uint32_t frame_9[][3] = {
    {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},  // Linha 1
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 2
    {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 3
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 80}
}  ;

static uint32_t frame_10[][3] = {
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},  // Linha 1
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80},    // Linha 3
    {0, 0, 80}, {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}, {0, 0, 80}
}  ;


static uint32_t frame_11[][3] = {
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0},  // Linha 1
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 2
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0},    // Linha 3
    {0, 0, 0}, {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // Linha 4
    {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 0}
}  ;


// letra B
static uint32_t letra_B[][3] = {
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 1
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},  // Linha 2
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80},  // Linha 3
    {0, 0, 80}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 80},  // Linha 4
    {0, 0, 0}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}, {0, 0, 80}   // Linha 5
};


static uint32_t letra_13[][3] = {
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50},  // Linha 1
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 2
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50},  // Linha 3
    {0, 0, 50}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 50},  // Linha 4
    {0, 0, 0}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}, {0, 0, 50}   // Linha 5
};












// Para todas as outras letras, crie matrizes similares respeitando o formato da matriz zig-zag.

// Função para animar todas as letras do alfabeto em sequência
 /*   void exibir_alfabeto() {
    static uint32_t *letras[] = {letra_A // Add matriz para B, C, ... Z };
    int letras_count = sizeof(letras) / sizeof(letras[0]);

    for (int i = 0; i < letras_count; i++) {
        Leds_Show_All(letras[i], true);
        sleep_ms(500); // Tempo de exibição para cada letra
    }
}    */

void exibir_letra_A() {
     Leds_Show_All(letra_A, true); // Mostra a matriz da letra "A"
    sleep_ms(6500);               // Tempo de exibição da letra
    //Leds_Show_All(letra_B, true);
    //sleep_ms(9500);
    //Leds_Show_All(letra_C, true);
    //sleep_ms(500);
    //Leds_Show_All(letra_D, true);
    //sleep_ms(500);
    Leds_Show_All(letra_E, true);
    sleep_ms(500);
    Leds_Show_All(frame_2, true);
    sleep_ms(500);
    Leds_Show_All(frame_3, true);
    sleep_ms(500);
    Leds_Show_All(frame_4, true);
    sleep_ms(500);
    Leds_Show_All(frame_4, true);
    sleep_ms(500);
    Leds_Show_All(frame_5, true);
    sleep_ms(500);
    Leds_Show_All(frame_6, true);
    sleep_ms(500);
    Leds_Show_All(frame_7, true);
    sleep_ms(500);
    Leds_Show_All(frame_8, true);
    sleep_ms(2500);



}
