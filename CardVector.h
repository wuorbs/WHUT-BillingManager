#ifndef BILLING_MANAGER_CARDVECTOR_H
#define BILLING_MANAGER_CARDVECTOR_H


#include "BillVector.h"

#include <bits/stdc++.h>
using namespace std;

// ���忨Ƭ�ṹ��
struct Card {
    // ���ţ��16λ
    char CardName[17];
    // ���룬�6λ
    char CardPwd[7];
    // ��״̬��0-δ���1-�Ѽ���
    int Status;
    // �����
    double Balance;
    // ��Ƭ�ϻ�ʱ��
    time_t Start;
    // �ϴε�¼ʱ��
    time_t Last;
    // ��Ƭ�»�ʱ��
    time_t End;
};

// ����ȽϺ�������������С���а��վ����С����
struct compareDistance {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

// ���忨Ƭ��
class CardVector {
public:

    // ���캯�������ļ��ж�ȡ��Ƭ��Ϣ����ʼ��
    explicit CardVector(const string &cardPATH);

    // ����¿�
    void addCard();

    // ɾ����
    void delCard();

    // ��ѯ����Ϣ
    void queryCard();

    // ���ÿ�����
    void resetPwd();

    // ��¼
    void logon();

    // �ǳ�
    void logout(BillVector &bill);

    // ��ֵ
    void recharge(BillVector &bill);

    // �˷�
    void refund(BillVector &bill);

    // ��ʾ���п�Ƭ��Ϣ
    void showCard();

    // ���������ַ���֮��ı༭����
    static int editDistance(string str1, string str2);

    // ������ӽ��������ŵĿ�Ƭ
    vector<Card> getTopMatches(const string &CardName);

    // ���뿨�ţ������Ƿ�Ϸ�
    static bool inputName(string &CardName);

    // �������룬�����Ƿ�Ϸ�
    static bool inputPwd(string &CardPwd, int p);

    // �������룬���ǺŴ��棬�������ַ���
    static string cinPwd();

    // ��鿨�Ƿ���ڣ�������ڷ���ָ��Ƭ��ָ������±�
    Card *isExist(string &CardName, int &CardIndex);

    // ������Ϣ���浽�ļ���
    void saveCard(const string &cardPATH);

    // ����ָ���±�Ŀ���Ϣ
    static void updateCard(const Card *p, const string &cardPATH, int CardIndex);

private:
    // ��Ƭ��Ϣ
    vector<Card> vec;
};


#endif //BILLING_MANAGER_CARDVECTOR_H
