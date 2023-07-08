#ifndef ESP8266_H
#define ESP8266_H

#include "main.h"

// ESP01 modülüne AT komutu gönderen fonksiyon
void esp8266_send_command(const char* command);

// ESP01 modülünden yanıtı okuyan fonksiyon
void esp8266_receive_response(char* response, uint16_t max_length);

// ESP01 modülüne bağlanma ve WiFi ağına katılma fonksiyonu
void esp8266_connect_to_wifi(const char* ssid, const char* password);

#endif /* ESP8266_H */
