#include <stdio.h>
#define LED_BASE_ADDR 0x1000

/**
 * TEORICAMENTE, configura uma suposta faixa de LEDs espalhados em 128 colunas
 * e 8 linhas para acender no seguinte padrão:
 * 
 * |o       o       o       o       o       o       o       o       |(...)
 * | o       o       o       o       o       o       o       o      |(...)
 * |  o       o       o       o       o       o       o       o     |(...)
 * |   o       o       o       o       o       o       o       o    |(...)
 * |    o       o       o       o       o       o       o       o   |(...)
 * |     o       o       o       o       o       o       o       o  |(...)
 * |      o       o       o       o       o       o       o       o |(...)
 * |       o       o       o       o       o       o       o       o|(...) 
 * 
 * @author Dahan Schuster
 */
int main()
{
    int i;

    /* Como cada bit representa um LED, col_leds irá representar o byte que
       contém os bits ligados em cada coluna */
    unsigned int col_leds = 128;

    /* col_leds_hex guarda o valor hexadecimal de col_leds */
    unsigned char *panel_ptr, col_leds_hex[10];

    // itera pelas colunas de LED
    for (i = 0; i < 128; i++)
    {
        // define a coluna a ser configurada na iteração
        panel_ptr = LED_BASE_ADDR + i;

        // converte em hex o decimal que representa os bits acesos na coluna
        sprintf(col_leds_hex, "%x", col_leds);

        // liga os LEDs referentes ao hexadecimal
        *panel_ptr = col_leds_hex;

        /* Configura os LEDs que ligarão na próxima coluna
           
        A cada iteração divide o valor de col_leds por 2, fazendo com que o bit
        anterior seja ligado (deixando os demais desligados)

        Quando chega no último bit (0x01), volta ao primeiro (0x80)

        Ex.: dec |  hex | bin
             128 | 0x80 | 10000000
              64 | 0x40 | 01000000
              32 | 0x20 | 00100000
              16 | 0x10 | 00010000
               8 | 0x08 | 00001000
               4 | 0x04 | 00000100
               2 | 0x02 | 00000010
               1 | 0x01 | 00000001
        */
        col_leds = col_leds == 1 ? 128 : col_leds / 2;
    }

    return 0;
}