#include "header.h"

String wifi;
String password;
String idPhone;
String accessToken;
String phone;

void setup(void) {
    cardputerStart();
    while (!readCredentials()) continue ;
    while (!connectWifi()) continue ;
}

void loop(void) {
    M5.update();
    keyboard();
}