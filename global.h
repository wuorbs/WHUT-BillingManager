#ifndef BILLING_MANAGER_GLOBAL_H
#define BILLING_MANAGER_GLOBAL_H


#include <bits/stdc++.h>
using namespace std;

// 定义常量，表示三个文本文件的路径
const string CARDPATH = "d:/Projects/Billing_Manager/data/card.txt";
const string BILLPATH = "d:/Projects/Billing_Manager/data/bill.txt";
const string PRICEPATH = "d:/Projects/Billing_Manager/data/price.txt";

// 定义常量，表示卡片状态的枚举值
const int UNUSE = 0;
const int USING = 1;

// 定义常量，表示账单类型的枚举值
const int COST = 1;
const int RECHARGE = 2;
const int REFUND = 3;

// 定义常量，表示超级管理员的账号和密码
const string ROOTID = "100001";
const string ROOTPWD = "100001";


#endif //BILLING_MANAGER_GLOBAL_H
