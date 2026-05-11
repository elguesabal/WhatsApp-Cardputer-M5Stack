#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <SD.h>
#include <WiFi.h>

#define FILE "/whatsapp"

extern String wifi;
extern String password;
extern String idPhone;
extern String accessToken;
extern String phone;

// ./cardputer.cpp
void cardputerStart(void);

// ./sdCard.cpp
String extractValue(String line);
bool readCredentials(void);

// ./wifi.cpp
bool connectWifi(void);

// ./keyboard.cpp
void keyboard(void);

#endif