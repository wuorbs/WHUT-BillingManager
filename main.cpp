#include "Menu.h"
#include "global.h"

int main() {
    // ������Ƭ���󣬲����ļ��ж�ȡ��Ƭ��Ϣ
    CardVector card(CARDPATH);

    // �����˵����󣬲����ļ��ж�ȡ�۸���Ϣ���˵���Ϣ
    BillVector bill(PRICEPATH, BILLPATH);

    // �����˵������뿨Ƭ��Ϣ���˵���Ϣ
    Menu::openMenu(card, bill);
}