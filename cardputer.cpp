#include "header.h"

/**
 * @author VAMPETA
 * @brief INCIA O CARDPUTER CONFIGURANDO FORMATACAO DE TEXTO
*/
void cardputerStart(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.setTextScroll(true);
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(1);
}