#ifndef BILLING_MANAGER_CARDVECTOR_H
#define BILLING_MANAGER_CARDVECTOR_H


#include "BillVector.h"

#include <bits/stdc++.h>
using namespace std;

// 定义卡片结构体
struct Card {
    // 卡号，最长16位
    char CardName[17];
    // 密码，最长6位
    char CardPwd[7];
    // 卡状态：0-未激活，1-已激活
    int Status;
    // 卡余额
    double Balance;
    // 卡片上机时间
    time_t Start;
    // 上次登录时间
    time_t Last;
    // 卡片下机时间
    time_t End;
};

// 定义比较函数，用于在最小堆中按照距离大小排序
struct compareDistance {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

// 定义卡片类
class CardVector {
public:

    // 构造函数，从文件中读取卡片信息并初始化
    explicit CardVector(const string &cardPATH);

    // 添加新卡
    void addCard();

    // 删除卡
    void delCard();

    // 查询卡信息
    void queryCard();

    // 重置卡密码
    void resetPwd();

    // 登录
    void logon();

    // 登出
    void logout(BillVector &bill);

    // 充值
    void recharge(BillVector &bill);

    // 退费
    void refund(BillVector &bill);

    // 显示所有卡片信息
    void showCard();

    // 计算两个字符串之间的编辑距离
    static int editDistance(string str1, string str2);

    // 返回最接近给定卡号的卡片
    vector<Card> getTopMatches(const string &CardName);

    // 输入卡号，返回是否合法
    static bool inputName(string &CardName);

    // 输入密码，返回是否合法
    static bool inputPwd(string &CardPwd, int p);

    // 输入密码，以星号代替，并返回字符串
    static string cinPwd();

    // 检查卡是否存在，如果存在返回指向卡片的指针和其下标
    Card *isExist(string &CardName, int &CardIndex);

    // 将卡信息保存到文件中
    void saveCard(const string &cardPATH);

    // 更新指定下标的卡信息
    static void updateCard(const Card *p, const string &cardPATH, int CardIndex);

private:
    // 卡片信息
    vector<Card> vec;
};


#endif //BILLING_MANAGER_CARDVECTOR_H
