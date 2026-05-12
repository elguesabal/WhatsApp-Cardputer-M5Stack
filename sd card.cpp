#include "header.h"

/**
 * @author VAMPETA
 * @brief EXTRAI O VALOR DA LINHA
 * @param line STRING DA LINHA PARA EXTRAIR O VALOR
 * @return RETORNA UMA String COM O VALOR
*/
String extractValue(String line) {
    int firstQuote;
    int secondQuote;

    firstQuote = line.indexOf('"');
    secondQuote = line.lastIndexOf('"');
    if (firstQuote == -1 || firstQuote == secondQuote) {
        return ("");
    }
    return (line.substring(firstQuote + 1, secondQuote));
}

/**
 * @author VAMPETA
 * @brief INCIA O CARTAO SD
 * @return RETORNA true OU false EM CASO DE FALHA DA LEITURA DAS INFORMACOES DO CARTAO SD
*/
bool readCredentials(void) {
    File file;
    String line;

    if (!SD.begin()) {
        M5.Display.println("Cartão sd não iniciado");
        return (false);
    }
    file = SD.open(FILE);
    if (!file) {
        M5.Display.println("Arquivo \"whatsapp\" não encontrado");
        return (false);
    }
    while (file.available()) {
        line = file.readStringUntil('\n');
        line.trim();
        if (line.startsWith("WIFI=")) {
            wifi = extractValue(line);
        } else if (line.startsWith("PASSWORD=")) {
            password = extractValue(line);
        } else if (line.startsWith("IDPHONE=")) {
            idPhone = extractValue(line);
        } else if (line.startsWith("ACCESSTOKEN=")) {
            accessToken = extractValue(line);
        } else if (line.startsWith("PHONE=")) {
            phone = extractValue(line);
        }
    }
    file.close();
    return (true);
}