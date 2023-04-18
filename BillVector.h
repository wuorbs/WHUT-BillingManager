#ifndef BILLING_MANAGER_BILLVECTOR_H
#define BILLING_MANAGER_BILLVECTOR_H


#include <bits/stdc++.h>
using namespace std;

// ����ṹ�� Bill
struct Bill {
    // �洢��Ƭ����
    char CardName[17]{};
    // �洢�˵���ʼ����
    time_t Start;
    // �洢�˵���������
    time_t End;
    // �洢�˵����
    double Balance;
    // �洢�˵�����
    int Type;

    // ���캯�������ڳ�ʼ�� Bill �ṹ�������
    Bill(char *nCardName, time_t nStart, time_t nEnd, double nBalance, int nType) {
        strcpy(CardName, nCardName);
        Start = nStart;
        End = nEnd;
        Balance = nBalance;
        Type = nType;
    }
};

// ������ BillVector
class BillVector {
public:
    // ���캯�������ڳ�ʼ�� BillVector �������
    explicit BillVector(const string &pricePATH, const string &billPATH);

    // ��ȡ Price ����ֵ
    double getPrice() const;

    // ��� Price ����ֵ
    void checkPrice() const;

    // ���� Price ����ֵ
    void resetPrice();

    // ���� Price ����ֵ
    void savePrice(const string &pricePATH);

    // ��� Bill ����
    void addBill(Bill billi);

    // ��̬�������������뿨Ƭ����
    static bool inputName(string &CardName);

    // ��ѯ�˵�
    void queryBill();

    // ��ʾ�˵�
    void showBill();

    // ��̬���������ڱ��� Bill �����ļ�
    static void saveBill(Bill bill, const string &billPATH);

private:
    // �洢 Bill ����� vector ����
    vector<Bill> vec;

    // �洢�˵��ļ۸�
    double Price{};
};


#endif //BILLING_MANAGER_BILLVECTOR_H
