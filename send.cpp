#include "header.h"

/**
 * @author VAMPETA
 * @brief ENVIA UMA MENSAGEM DO TIPO TEXTO
 * @param message MENSAGEM A SER ENVIADA
 */
void sendText(String &message) {
    WiFiClientSecure client;
    HTTPClient http;
    String url;
    String body;
    int httpCode;
    String res;

    if (message.length() == 0) return ;
    client.setInsecure();
    url = "https://graph.facebook.com/v22.0/" + idPhone + "/messages";
    http.begin(client, url);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", "Bearer " + accessToken);
    body = R"rawliteral(
{
    "messaging_product": "whatsapp",
    "to": "__PHONE__",
    "type": "text",
    "text": {
        "body": "__MESSAGE__"
    }
}
)rawliteral";
    body.replace("__PHONE__", phone);
    body.replace("__MESSAGE__", message);
    httpCode = http.POST(body);
    res = http.getString();
    http.end();
    if (httpCode == 200) {
        message = "";
    } else if (httpCode != 200) {
        M5Cardputer.Display.println();
        M5Cardputer.Display.println(httpCode);
        M5Cardputer.Display.println(res);
    }
}