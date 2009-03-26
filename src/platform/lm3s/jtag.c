/*
  jtag.c - JTAG utilities for LM3s hosts
*/

#include "jtag.h"

/* -------------------- JTAG functions -------------------- */
/* Enable JTAG pins */
void JtagEnable(void)
{
    /* Change PB7 and PC0-3 for JTAG */
    HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTB_BASE + GPIO_O_CR) = 0x80;
    HWREG(GPIO_PORTB_BASE + GPIO_O_AFSEL) |= 0x80;
    HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTB_BASE + GPIO_O_CR) = 0x00;
    HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = 0;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x01;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) |= 0x01;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x02;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) |= 0x02;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x04;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) |= 0x04;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x08;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) |= 0x08;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x00;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = 0;
}

/* Set JTAG pins for use as GPIO */
void JtagDisable(void)
{
    /* Enable GPIO ports B and C */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    /* Change PB7 and PC0-3 for GPIO input */
    HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTB_BASE + GPIO_O_CR) = 0x80;
    HWREG(GPIO_PORTB_BASE + GPIO_O_AFSEL) &= 0x7f;
    HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTB_BASE + GPIO_O_CR) = 0x00;
    HWREG(GPIO_PORTB_BASE + GPIO_O_LOCK) = 0;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x01;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) &= 0xfe;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x02;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) &= 0xfd;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x04;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) &= 0xfb;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x08;
    HWREG(GPIO_PORTC_BASE + GPIO_O_AFSEL) &= 0xf7;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTC_BASE + GPIO_O_CR) = 0x00;
    HWREG(GPIO_PORTC_BASE + GPIO_O_LOCK) = 0;
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_7);
    GPIOPinTypeGPIOInput(GPIO_PORTC_BASE, (GPIO_PIN_0 | GPIO_PIN_1 |
                                           GPIO_PIN_2 | GPIO_PIN_3));
}
