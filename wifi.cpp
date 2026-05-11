#include "header.h"

/**
 * @brief CONECTA AO WIFI
 * @return true EM CASO DE SUCESSO
 */
bool connectWifi(void) {
    int attempts;

    WiFi.begin(wifi.c_str(), password.c_str());
    attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        attempts++;
    }
    if (WiFi.status() != WL_CONNECTED) {
        M5.Display.println("Wifi não conectado");
        return (false);
    }
    return (true);
}