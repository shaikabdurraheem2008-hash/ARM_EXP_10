#include <LPC214x.h>

void DACInit(void)
{
    PINSEL1 &= ~(3U << 18);  // Clear bits 19:18
    PINSEL1 |=  (2U << 18);  // Select DAC function on P0.25
}

void delay(void)
{
    volatile unsigned int i;

    for (i = 0; i < 1000; i++)
    {
        // Software delay
    }
}

int main(void)
{
    DACInit();

    while (1)
    {
        DACR = (0U << 6);     // Low level: approximately 0 V
        delay();

        DACR = (776U << 6);   // High level: approximately 2.5 V
        delay();
    }

    return 0;
}
