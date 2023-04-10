#include "Menu.h"
#include "global.h"

int main() {
    CardVector card(CARDPATH);
    BillVector bill(PRICEPATH, BILLPATH);
    Menu::openMenu(card, bill);
}