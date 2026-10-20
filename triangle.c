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
    unsigned int value;

    DACInit();

    while (1)
    {
        // Rising part of triangular wave
        for (value = 0; value <= 1023; value++)
        {
            DACR = (value << 6);
            delay();
        }

        // Falling part of triangular wave
        for (value = 1023; value > 0; value--)
        {
            DACR = (value << 6);
            delay();
        }
    }

    return 0;
}
