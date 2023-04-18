#include "Menu.h"
#include "global.h"

int main() {
    // 创建卡片对象，并从文件中读取卡片信息
    CardVector card(CARDPATH);

    // 创建账单对象，并从文件中读取价格信息和账单信息
    BillVector bill(PRICEPATH, BILLPATH);

    // 打开主菜单，传入卡片信息和账单信息
    Menu::openMenu(card, bill);
}