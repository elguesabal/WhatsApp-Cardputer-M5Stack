#include "header.h"

/**
 * @author VAMPETA
 * @brief MONITORA O BOTAO BtnGo AO LADO DA CHAVE OFF/ON
 * @param message MENSAGEM A SER ENVIADA
 */
void BtnGo(String &message) {
    if (!M5Cardputer.BtnA.wasPressed()) return ;
    httpCode = sendText(message);
}

/**
 * @author VAMPETA
 * @brief MONITORA O BOTAO ENTER
 * @param input REFERENCIA DO INPUT QUE GUARDA A MENSAGEM QUE SERA ENVIADA
 */
void enter(String &input) {
    if (!M5Cardputer.Keyboard.keysState().enter) return ;
    sendText(input);
    input = "";
    M5Cardputer.Display.println();
}

/**
 * @author VAMPETA
 * @brief MONITORA O BOTAO DEL
 * @param input REFERENCIA DO INPUT QUE GUARDA A MENSAGEM QUE SERA ENVIADA
 */
void del(String &input) {
    if (!M5Cardputer.Keyboard.keysState().del) return ;
    if (input.length() == 0) return ;
    input.remove(input.length() - 1);
    M5.Display.fillRect(0, 0, 320, 240, BLACK);
    M5.Display.setCursor(0, 0);
    M5.Display.print(input);
}

/**
 * @author VAMPETA
 * @brief MONITORA OS BOTOES EM GERAL DO TECLADO
 * @param input REFERENCIA DO INPUT QUE GUARDA A MENSAGEM QUE SERA ENVIADA
 */
void key(String &input) {
    for (char c : M5Cardputer.Keyboard.keysState().word) {
        input += c;
        M5.Display.print(c);
    }
}

/**
 * @author VAMPETA
 * @brief MONITORA O TECLADO
 */
void keyboard(void) {
    static String input;

    BtnGo(input);
    if (!M5Cardputer.Keyboard.isChange() || !M5Cardputer.Keyboard.isPressed()) return ;
    enter(input);
    del(input);
    key(input);
}