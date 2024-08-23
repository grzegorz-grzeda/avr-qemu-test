#include <avr/io.h>
#include <stdio.h>

void uart_init() {
    // Set baud rate to 9600
    UBRR0H = (unsigned char)(103 >> 8);
    UBRR0L = (unsigned char)103;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

int uart_putchar(char c, FILE* stream) {
    if (c == '\n') {
        uart_putchar('\r', stream);
    }

    while (!(UCSR0A & (1 << UDRE0)))
        ;

    UDR0 = c;

    return 0;
}

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);

int main() {
    uart_init();

    stdout = &uart_output;

    printf("\033[32mHello, World!\033[0m\n");

    while (1) {
    }
}