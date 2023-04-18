#ifndef BILLING_MANAGER_MENU_H
#define BILLING_MANAGER_MENU_H


#include "BillVector.h"
#include "CardVector.h"

#include <bits/stdc++.h>
using namespace std;

// 声明菜单类
class Menu {
public:
    // 构造函数
    Menu();

    // 析构函数
    ~Menu();

    // 打开主菜单函数，传入卡片信息和账单信息
    static void openMenu(CardVector &card, BillVector &bill);

    // 消费功能子菜单，传入卡片信息和账单信息
    static void subMenu1(CardVector &card, BillVector &bill);

    // 账户功能子菜单，传入卡片信息
    static void subMenu2(CardVector &card);

    // 管理员功能子菜单，传入卡片信息和账单信息
    static void subMenu3(CardVector &card, BillVector &bill);

    // 管理员登陆函数，返回登陆是否成功的布尔值
    static bool rootLogon();
};


#endif //BILLING_MANAGER_MENU_H
