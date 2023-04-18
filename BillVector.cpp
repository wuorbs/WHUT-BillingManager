#include "BillVector.h"
#include "global.h"
#include "tool.h"

// ���캯�������ڳ�ʼ�� BillVector �������
BillVector::BillVector(const string &pricePATH, const string &billPATH) {
    ifstream pricefile(pricePATH, ios::in | ios::binary);
    if (!pricefile.is_open()) return;
    pricefile.read((char *) &Price, sizeof(double));
    pricefile.close();
    ifstream billfile(billPATH, ios::in | ios::binary);
    Bill bill("", 0, 0, 0, 0);
    if (!billfile.is_open()) return;
    while (true) {
        billfile.read((char *) &bill, sizeof(Bill));
        if (billfile.eof())break;
        vec.push_back(bill);
    }
    billfile.close();
}

// ��ȡ Price ����ֵ
double BillVector::getPrice() const { return Price; }

// ��� Price ����ֵ
void BillVector::checkPrice() const {
    system("cls");
    cout << "\n\t\t\t\t��ǰ�۸�Ϊ��" << setprecision(2) << Price << "/����\n\n";
    system("pause");
}

/ ���� Price ����ֵ
void BillVector::resetPrice() {
    double NewPrice;
    system("cls");
    cout << "\n\t\t\t\t��ǰ�۸�Ϊ��" << setprecision(2) << Price << "/����\n\n";
    cout << "\t\t\t\t�������µļ۸�</����>��";
    cin >> NewPrice;
    Price = NewPrice;
    savePrice(PRICEPATH);
    system("cls");
    cout << "\n\t\t\t    �۸�����ɹ�����ǰ�۸�Ϊ��" << setprecision(2) << Price << "/����\n\n";
    system("pause");
}

// ��� Bill ����
void BillVector::addBill(Bill billi) {
    vec.push_back(billi);
}

// ��̬�������������뿨Ƭ����
bool BillVector::inputName(string &CardName) {
    while (true) {
        system("cls");
        cout << "\n\t\t\t�����뿨��<����Ϊ1~17>��";
        cin >> CardName;
        if (CardName.size() > 17) {
            system("cls");
            cout << "\n\t\t\t\t���ų��ȳ������ֵ��\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t����������<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        } else break;
    }
    return true;
}

// ��ѯ�˵�
void BillVector::queryBill() {
    system("cls");
    string CardName;
    if (inputName(CardName)) {
        cout << "\n\t\t����\t\t�ϻ�ʱ��\t\t�»�ʱ��\t\t���\t\t����\n";
        for (auto it: vec) {
            if (it.CardName == CardName) {
                cout << "\t\t" << it.CardName << "\t\t";
                char StartTime[20] = {0};
                timeToString(it.Start, StartTime);
                cout << StartTime << "\t";
                char EndTime[20] = {0};
                timeToString(it.End, EndTime);
                cout << EndTime << "\t";
                cout << setiosflags(ios::fixed) << setprecision(2) << it.Balance << "\t\t";
                if (it.Type == COST) cout << "����\n";
                else if (it.Type == RECHARGE) cout << "��ֵ\n";
                else if (it.Type == REFUND) cout << "�˷�\n";
            }
        }
        system("pause");
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ��ʾ�˵�
void BillVector::showBill() {
    system("cls");
    cout << "\n\t\t����\t\t�ϻ�ʱ��\t\t�»�ʱ��\t\t���\t\t����\n";
    for (auto it: vec) {
        cout << "\t\t" << it.CardName << "\t\t";
        char StartTime[20] = {0};
        timeToString(it.Start, StartTime);
        cout << StartTime << '\t';
        char EndTime[20] = {0};
        timeToString(it.End, EndTime);
        cout << EndTime << '\t';
        cout << setiosflags(ios::fixed) << setprecision(2) << it.Balance << "\t\t";
        if (it.Type == COST) cout << "����\n";
        else if (it.Type == RECHARGE) cout << "��ֵ\n";
        else if (it.Type == REFUND) cout << "�˷�\n";
    }
    system("pause");
}

// ���� Price ����ֵ
void BillVector::savePrice(const string &pricePATH) {
    ofstream pricefile(pricePATH, ios::out | ios::binary);
    if (!pricefile.is_open()) return;
    pricefile.write((char *) &Price, sizeof(double));
    pricefile.close();
}

// ��̬���������ڱ��� Bill �����ļ�
void BillVector::saveBill(Bill bill, const std::string &billPATH) {
    ofstream billfile(billPATH, ios::app | ios::binary);
    if (!billfile.is_open()) return;
    billfile.write((char *) &bill, sizeof(Bill));
    billfile.close();
}