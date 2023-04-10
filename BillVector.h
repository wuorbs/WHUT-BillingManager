#ifndef BILLING_MANAGEMENT_BILLVECTOR_H
#define BILLING_MANAGEMENT_BILLVECTOR_H


#include <bits/stdc++.h>
using namespace std;

struct Bill {
    char CardName[17]{};
    time_t Start;
    time_t End;
    double Balance;
    int Type;

    Bill(char *nCardName, time_t nStart, time_t nEnd, double nBalance, int nType) {
        strcpy(CardName, nCardName);
        Start = nStart;
        End = nEnd;
        Balance = nBalance;
        Type = nType;
    }
};

class BillVector {
public:
    explicit BillVector(const string &pricePATH, const string &billPATH);

    double getPrice() const;

    void checkPrice() const;

    void resetPrice();

    void savePrice(const string &pricePATH);

    void addBill(Bill billi);

    static bool inputName(string &CardName);

    void queryBill();

    void showBill();

    static void saveBill(Bill bill, const string &billPATH);

private:
    vector<Bill> vec;

    double Price{};
};


#endif //BILLING_MANAGEMENT_BILLVECTOR_H
