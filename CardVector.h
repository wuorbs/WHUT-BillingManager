#ifndef BILLING_MANAGEMENT_CARDVECTOR_H
#define BILLING_MANAGEMENT_CARDVECTOR_H


#include "BillVector.h"

#include <bits/stdc++.h>
using namespace std;

struct Card {
    char CardName[17];
    char CardPwd[7];
    int Status;
    double Balance;
    time_t Start;
    time_t Last;
    time_t End;
};

struct compareDistance {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

class CardVector {
public:

    explicit CardVector(const string &cardPATH);

    void addCard();

    void delCard();

    void queryCard();

    void resetPwd();

    void logon();

    void logout(BillVector &bill);

    void recharge(BillVector &bill);

    void refund(BillVector &bill);

    void showCard();

    static int editDistance(string str1, string str2);

    vector<Card> getTopMatches(const string &CardName);

    static bool inputName(string &CardName);

    static bool inputPwd(string &CardPwd, int p);

    Card *isExist(string &CardName, int &CardIndex);

    void saveCard(const string &cardPATH);

    static void updataCard(const Card *p, const string &cardPATH, int CardIndex);

private:
    vector<Card> vec;
};


#endif //BILLING_MANAGEMENT_CARDVECTOR_H
