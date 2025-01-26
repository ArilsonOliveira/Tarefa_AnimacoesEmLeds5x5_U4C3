#include "leds.h"
#include "contagem.h"

static uint32_t contagem_frame0[][3] = {                               
    {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0},   // - - * - -      
    {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0},   // - * * - -       
    {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0},   // - - * - -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0},  // - - * - -       
    {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0}    // - - * - -       
};

static uint32_t contagem_frame1[][3] = {                               
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},    // - * * * -      
    {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},      // - - - * -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},    // - * * * -       
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0},      // - * - - -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0}     // - * * * -       
};

static uint32_t contagem_frame2[][3] = {                               
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},   // - * * * -      
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0},     // - - - * -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},   // - * * * -       
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0},     // - - - * -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0}    // - * * * -       
};

static uint32_t contagem_frame3[][3] = {                               
    {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},    // - * - * -      
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0},    // - * - * -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},  // - * * * -       
    {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0},   // - - - * -       
    {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0}    // - - - * -       
};

static uint32_t contagem_frame4[][3] = {                               
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},    // - * * * -      
    {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 60, 0}, {0, 0, 0},      // - * - - -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0},    // - * * * -       
    {0, 0, 0}, {0, 60, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0},      // - - - * -       
    {0, 0, 0}, {0, 60, 0}, {0, 60, 0}, {0, 60, 0}, {0, 0, 0}     // - * * * -       
};

/* função: contagem
   funcionamento: ao pressionar a tecla 0, os números de 1 a 5 aparecem na matriz de LEDs */
void contagem() {
    uint32_t (*contagem_frames[])[3] = {contagem_frame0, contagem_frame1, contagem_frame2, contagem_frame3, contagem_frame4};
    int quantidade_frames = sizeof(contagem_frames) / sizeof(contagem_frames[0]);

    
    for (int i = 0; i < quantidade_frames; i++) {
        Leds_Show_All(contagem_frames[i], true);
        sleep_ms(2000);
    }        
}


static uint32_t frameTeclaB[][3] = {                               
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},        
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},            
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},        
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100},             
    {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}, {0, 0, 100}           
};

/* função: teclaB
   funcionamento: ao pressionar a tecla B, todos os LEDs são ligados na cor azul, 
   no nível de intensidade de 100% da luminosidade máxima */
void teclaB() {
    Leds_Show_All(frameTeclaB, true);
    sleep_ms(1000);
}


static uint32_t frameTeclaC[][3] = {                               
    {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0},        
    {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0},            
    {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0},        
    {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0},             
    {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0}, {80, 0, 0}           
};

/* função: teclaC
   funcionamento: ao pressionar a tecla B, todos os LEDs são ligados na cor vermelha, 
   no nível de intensidade de 80% da luminosidade máxima */
void teclaC() {
    Leds_Show_All(frameTeclaC, true);
    sleep_ms(1000);
}