#ifndef BILLING_MANAGER_BILLVECTOR_H
#define BILLING_MANAGER_BILLVECTOR_H


#include <bits/stdc++.h>
using namespace std;

// 定义结构体 Bill
struct Bill {
    // 存储卡片名称
    char CardName[17]{};
    // 存储账单起始日期
    time_t Start;
    // 存储账单结束日期
    time_t End;
    // 存储账单余额
    double Balance;
    // 存储账单类型
    int Type;

    // 构造函数，用于初始化 Bill 结构体的属性
    Bill(char *nCardName, time_t nStart, time_t nEnd, double nBalance, int nType) {
        strcpy(CardName, nCardName);
        Start = nStart;
        End = nEnd;
        Balance = nBalance;
        Type = nType;
    }
};

// 定义类 BillVector
class BillVector {
public:
    // 构造函数，用于初始化 BillVector 类的属性
    explicit BillVector(const string &pricePATH, const string &billPATH);

    // 获取 Price 属性值
    double getPrice() const;

    // 检查 Price 属性值
    void checkPrice() const;

    // 重置 Price 属性值
    void resetPrice();

    // 保存 Price 属性值
    void savePrice(const string &pricePATH);

    // 添加 Bill 对象
    void addBill(Bill billi);

    // 静态方法，用于输入卡片名称
    static bool inputName(string &CardName);

    // 查询账单
    void queryBill();

    // 显示账单
    void showBill();

    // 静态方法，用于保存 Bill 对象到文件
    static void saveBill(Bill bill, const string &billPATH);

private:
    // 存储 Bill 对象的 vector 容器
    vector<Bill> vec;

    // 存储账单的价格
    double Price{};
};


#endif //BILLING_MANAGER_BILLVECTOR_H
