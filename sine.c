#include "LPC214x.h"

void DACInit(void)
{
    PINSEL1 &= ~(3U << 18);
    PINSEL1 |=  (2U << 18);
}

void delay(void)
{
    volatile unsigned int count;

    for (count = 0; count < 1000; count++)
    {
    }
}

int main(void)
{
    unsigned int i = 0;

    unsigned int sinevalues[32] = {
        0x200, 0x263, 0x2C3, 0x31C,
        0x369, 0x3A9, 0x3D8, 0x3F4,
        0x3FF, 0x3F4, 0x3D8, 0x3A9,
        0x369, 0x31C, 0x2C3, 0x263,
        0x200, 0x19D, 0x13D, 0x0E4,
        0x096, 0x057, 0x028, 0x00B,
        0x000, 0x00B, 0x028, 0x057,
        0x096, 0x0E4, 0x13D, 0x19D
    };

    DACInit();

    while (1)
    {
        for (i = 0; i < 32; i++)
        {
            DACR = sinevalues[i] << 6;
            delay();
        }
    }
}
