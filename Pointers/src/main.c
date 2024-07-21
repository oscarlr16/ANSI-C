#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"

// Mock de la función UART_putc para ESP32
void UART_putc(char c) {
    // En un entorno real, esto enviaría el carácter por UART
    printf("%c", c);  // Imprimimos el carácter para simular el envío por UART
}

// Función UART_puts
void UART_puts(char *c) {
    while (*c) {
        UART_putc(*c++);
    }
}

// Función principal de la aplicación
void app_main(void) {
    char mensaje[] = "Hello, ESP32!";
    
    printf("Enviando mensaje: %s\n", mensaje);
    UART_puts(mensaje);
    printf("\nMensaje enviado.\n");
    
    // Para que el programa no termine inmediatamente y puedas ver la salida
    while (1) {
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
