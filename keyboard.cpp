#include "header.h"

/**
 * @author VAMPETA
 * @brief MONITORA O TECLADO
 */
void keyboard(void) {
    Keyboard_Class::KeysState status;
    String input;

    if (!M5Cardputer.Keyboard.isChange() || M5Cardputer.Keyboard.isPressed()) return ;
    status = M5Cardputer.Keyboard.keysState();
    input = "";
    for (auto c : status.word) {
        switch (c) {
            case '\n':
                return ;
            case '\b':
                break;
        }
        input += c;
        M5.Display.print(c);
    }
}