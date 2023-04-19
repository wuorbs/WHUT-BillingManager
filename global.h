#ifndef BILLING_MANAGER_GLOBAL_H
#define BILLING_MANAGER_GLOBAL_H


#include <bits/stdc++.h>
using namespace std;

// 定义常量，表示三个文本文件的路径
const string CARDPATH = "d:/Projects/Billing_Manager/data/card.txt";   // 存储卡信息文件
const string BILLPATH = "d:/Projects/Billing_Manager/data/bill.txt";   // 存储账单信息文件
const string PRICEPATH = "d:/Projects/Billing_Manager/data/price.txt"; // 存储价格信息文件

// 定义常量，表示卡片状态的枚举值
const int UNUSE = 0; // 未上机
const int USING = 1; // 正在上机

// 定义常量，表示账单类型的枚举值
const int COST = 1;     // 消费操作
const int RECHARGE = 2; // 充值操作
const int REFUND = 3;   // 退费操作

// 定义常量，表示超级管理员的账号和密码
const string ROOTID = "100001";  // 管理员账号
const string ROOTPWD = "100001"; //管理员密码


#endif //BILLING_MANAGER_GLOBAL_H
