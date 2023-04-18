#ifndef BILLING_MANAGER_MENU_H
#define BILLING_MANAGER_MENU_H


#include "BillVector.h"
#include "CardVector.h"

#include <bits/stdc++.h>
using namespace std;

// �����˵���
class Menu {
public:
    // ���캯��
    Menu();

    // ��������
    ~Menu();

    // �����˵����������뿨Ƭ��Ϣ���˵���Ϣ
    static void openMenu(CardVector &card, BillVector &bill);

    // ���ѹ����Ӳ˵������뿨Ƭ��Ϣ���˵���Ϣ
    static void subMenu1(CardVector &card, BillVector &bill);

    // �˻������Ӳ˵������뿨Ƭ��Ϣ
    static void subMenu2(CardVector &card);

    // ����Ա�����Ӳ˵������뿨Ƭ��Ϣ���˵���Ϣ
    static void subMenu3(CardVector &card, BillVector &bill);

    // ����Ա��½���������ص�½�Ƿ�ɹ��Ĳ���ֵ
    static bool rootLogon();
};


#endif //BILLING_MANAGER_MENU_H
