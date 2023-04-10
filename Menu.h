#ifndef BILLING_MANAGEMENT_MENU_H
#define BILLING_MANAGEMENT_MENU_H


#include "BillVector.h"
#include "CardVector.h"

#include <bits/stdc++.h>
using namespace std;

class Menu {
public:
    Menu();

    ~Menu();

    static void openMenu(CardVector &card, BillVector &bill);

    static void subMenu1(CardVector &card, BillVector &bill);

    static void subMenu2(CardVector &card);

    static void subMenu3(CardVector &card, BillVector &bill);

    static bool rootLogon();
};


#endif //BILLING_MANAGEMENT_MENU_H
