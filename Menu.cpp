#include "Menu.h"
#include "global.h"

Menu::Menu() = default;

Menu::~Menu() = default;

void Menu::openMenu(CardVector &card, BillVector &bill) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t��ӭ����Ʒѹ���ϵͳ��\n\n";
        cout << "\t\t\t    -------�Ʒѹ���ϵͳ�˵�-------\n";
        cout << "\t\t\t\t    1. ���ѹ���\n";
        cout << "\t\t\t\t    2. �˻�����\n";
        cout << "\t\t\t\t    3. ����Ա����\n";
        cout << "\t\t\t\t    0. �˳�ϵͳ\n\n";
        cout << "\t\t\t\t��ѡ��˵�����<0~3>:";
        cin >> op;
        switch (op) {
            case 1:
                subMenu1(card, bill);
                break;
            case 2:
                subMenu2(card);
                break;
            case 3:
                subMenu3(card, bill);
                break;
            case 0:
                system("cls");
                cout << "\n\t\t\t\t��л��ʹ�ñ�ϵͳ��\n\n";
                system("pause");
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t����Ĳ˵����Ŵ���\n\n";
                system("pause");
        }
    } while (op != 0);
}

void Menu::subMenu1(CardVector &card, BillVector &bill) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------���ѹ���-------\n";
        cout << "\t\t\t\t    1. ��ѯ�۸�\n";
        cout << "\t\t\t\t    2. �ϻ�\n";
        cout << "\t\t\t\t    3. �»�\n";
        cout << "\t\t\t\t    4. ��ֵ\n";
        cout << "\t\t\t\t    5. �˷�\n";
        cout << "\t\t\t\t    6. ��ѯ�˵�\n";
        cout << "\t\t\t\t    0. �����ϼ��˵�\n\n";
        cout << "\t\t\t��ѡ��˵�����<0~6>:";
        cin >> op;
        switch (op) {
            case 1:
                bill.checkPrice();
                break;
            case 2:
                card.logon();
                break;
            case 3:
                card.logout(bill);
                break;
            case 4:
                card.recharge(bill);
                break;
            case 5:
                card.refund(bill);
                break;
            case 6:
                bill.queryBill();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t����Ĳ˵����Ŵ���\n\n";
                system("pause");
        }

    } while (op != 0);
}

void Menu::subMenu2(CardVector &card) {
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------�˻�����-------\n";
        cout << "\t\t\t\t    1. ������\n";
        cout << "\t\t\t\t    2. ע����\n";
        cout << "\t\t\t\t    3. ��ѯ��\n";
        cout << "\t\t\t\t    4. ��������\n";
        cout << "\t\t\t\t    0. �����ϼ��˵�\n\n";
        cout << "\t\t\t\t��ѡ��˵�����<0~4>:";
        cin >> op;
        switch (op) {
            case 1:
                card.addCard();
                break;
            case 2:
                card.delCard();
                break;
            case 3:
                card.queryCard();
                break;
            case 4:
                card.resetPwd();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t����Ĳ˵����Ŵ���\n\n";
                system("pause");
        }
    } while (op != 0);
}

bool Menu::rootLogon() {
    string rootId;
    string rootPwd;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------����Ա����-------\n";
        cout << "\n\t\t\t    ���������Ա�˺ţ�";
        cin >> rootId;
        if (rootId != ROOTID) {
            cout << "\n\t\t\t\t����Ĺ���Ա�˺Ų���ȷ��\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t����������<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        }
    } while (rootId != ROOTID);
    do {
        system("cls");
        cout << "\n\t\t\t\t-------����Ա����-------\n";
        cout << "\n\t\t\t    ���������Ա���룺";
        cin >> rootPwd;
        if (rootPwd != ROOTPWD) {
            cout << "\n\t\t\t\t����Ĺ���Ա���벻��ȷ��\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t����������<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        }
    } while (rootPwd != ROOTPWD);
    return true;
}

void Menu::subMenu3(CardVector &card, BillVector &bill) {
    if (!rootLogon()) return;
    int op;
    do {
        system("cls");
        cout << "\n\t\t\t\t-------����Ա����-------\n";
        cout << "\t\t\t\t    1. ��ѯ��\n";
        cout << "\t\t\t\t    2. �鿴�˵�\n";
        cout << "\t\t\t\t    3. �۸����\n";
        cout << "\t\t\t\t    0. �����ϼ��˵�\n\n";
        cout << "\t\t\t\t��ѡ��˵�����<0~3>:";
        cin >> op;
        switch (op) {
            case 1:
                card.showCard();
                break;
            case 2:
                bill.showBill();
                break;
            case 3:
                bill.resetPrice();
                break;
            case 0:
                break;
            default:
                system("cls");
                cout << "\n\t\t\t\t����Ĳ˵����Ŵ���\n\n";
                system("pause");
        }
    } while (op != 0);
}