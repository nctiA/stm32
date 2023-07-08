#include "esp8266.h"
#include "string.h"
#include "stdio.h"


extern UART_HandleTypeDef huart1;


// ESP01 modülüne AT komutu gönderen fonksiyon
void esp8266_send_command(const char* command)
{
    HAL_UART_Transmit(&huart1, (uint8_t*)command, strlen(command), HAL_MAX_DELAY);
}

// ESP01 modülünden yanıtı okuyan fonksiyon
void esp8266_receive_response(char* response, uint16_t max_length)
{
    HAL_UART_Receive(&huart1, (uint8_t*)response, max_length, HAL_MAX_DELAY);
}

// ESP01 modülüne bağlanma ve WiFi ağına katılma fonksiyonu
void esp8266_connect_to_wifi(const char* ssid, const char* password)
{
    char command[64];
    char response[64];

    // ESP01 modülüne AT komutları göndererek WiFi ağına bağlanma işlemi
    sprintf(command, "AT+CWJAP=\"%s\",\"%s\"\r\n", ssid, password);
    esp8266_send_command(command);
    esp8266_receive_response(response, sizeof(response));

    // WiFi bağlantısı başarılıysa, "OK" yanıtı almalısınız.
}