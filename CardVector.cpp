#include "CardVector.h"
#include "global.h"
#include "tool.h"
#include <conio.h>

// ���캯�������ļ��ж�ȡ��Ƭ��Ϣ����ʼ��
CardVector::CardVector(const string &cardPATH) {
    ifstream cardfile(cardPATH, ios::in | ios::binary);
    Card card{};
    if (!cardfile.is_open()) return;
    while (true) {
        cardfile.read((char *) &card, sizeof(Card));
        if (cardfile.eof())break;
        vec.push_back(card);
    }
    cardfile.close();
}

// ����¿�
void CardVector::addCard() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        if (isExist(CardName, CardIndex) != nullptr) {
            system("cls");
            cout << "\n\t\t\t\t�˿�����ʹ�ã�������ʧ�ܣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 1)) {
            Card card{};
            strcpy(card.CardName, CardName.c_str());
            strcpy(card.CardPwd, CardPwd.c_str());
            card.Status = UNUSE;
            card.Balance = 0;
            card.Start = card.Last = card.End = time(nullptr);
            vec.push_back(card);
            saveCard(CARDPATH);
            system("cls");
            cout << "\n\t\t\t\t\t�������ɹ���\n\n";
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t�����ʽ����ȷ��������ʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ɾ����
void CardVector::delCard() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 1) && CardPwd == p->CardPwd) {
            vec.erase(vec.begin() + CardIndex);
            saveCard(CARDPATH);
            system("cls");
            cout << "\n\t\t\t\t\tɾ�����ɹ���\n\n";
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t�������ɾ����ʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ��ѯ����Ϣ
void CardVector::queryCard() {
    string CardName;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            vector<Card> topMatches = getTopMatches(CardName);
            if (topMatches.size()) {
                cout << "\t\t\t\t    ���Ƿ��ڲ�ѯ���¿��ţ�\n";
                for (int i = 0; i < topMatches.size(); i++)
                    cout << "\t\t\t\t\t����" << i + 1 << "��" << topMatches[i].CardName << '\n';
                cout << "\n\t\t\t    ��������Ų�ѯ������Ϣ<����0�˳�>��";
                int idx;
                cin >> idx;
                while (idx > topMatches.size()) {
                    cout << "\n\t\t\t    �������Ŵ������������룺";
                    cin >> idx;
                }
                if (idx == 0) return;
                idx--;
                cout << "\n\t\t\t����\t\t״̬\t���\t�ϴ�ʹ��ʱ��\n";
                cout << "\t\t\t" << topMatches[idx].CardName << "\t\t";
                if (topMatches[idx].Status == UNUSE) cout << "δ�ϻ�\t";
                else cout << "�ϻ�\t";
                cout << setiosflags(ios::fixed) << setprecision(2) << topMatches[idx].Balance << '\t';
                char LastTime[20] = {0};
                timeToString(topMatches[idx].Last, LastTime);
                cout << LastTime << '\n';
            }
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t����\t\t״̬\t���\t�ϴ�ʹ��ʱ��\n";
            cout << "\t\t\t" << CardName << "\t\t";
            if (p->Status == UNUSE) cout << "δ�ϻ�\t";
            else cout << "�ϻ�\t";
            cout << setiosflags(ios::fixed) << setprecision(2) << p->Balance << '\t';
            char LastTime[20] = {0};
            timeToString(p->Last, LastTime);
            cout << LastTime << '\n';
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ���ÿ�����
void CardVector::resetPwd() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            if (inputPwd(CardPwd, 2)) {
                strcpy(p->CardPwd, CardPwd.c_str());
                system("cls");
                cout << "\n\t\t\t\t\t��������ɹ���\n\n";
                system("pause");
            } else {
                system("cls");
                cout << "\n\t\t\t\t�����ʽ����ȷ��������ʧ�ܣ�\n\n";
                system("pause");
            }
        } else {
            system("cls");
            cout << "\n\t\t\t\t���������������ʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ��¼
void CardVector::logon() {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            if (p->Status == USING) {
                system("cls");
                cout << "\n\t\t\t\t�ÿ�����ʹ�ã������ظ��ϻ���\n\n";
                system("pause");
            } else if (p->Balance <= 0) {
                system("cls");
                cout << "\n\t\t\t\t�����㣬�ϻ�ʧ�ܣ�\n\n";
                system("pause");
            } else {
                p->Status = USING;
                p->Start = p->Last = time(nullptr);
                char StartTime[20];
                timeToString(p->Start, StartTime);
                updateCard(p, CARDPATH, CardIndex);
                system("cls");
                cout << "\n\t\t\t\t\t�ϻ��ɹ���\n\n";
                cout << "\t\t\t\t���ţ�" << p->CardName << '\n';
                cout << "\t\t\t\t��" << setiosflags(ios::fixed) << setprecision(2) << p->Balance << '\n';
                cout << "\t\t\t\t�ϻ�ʱ�䣺" << StartTime << "\n\n";
                system("pause");
            };
        } else {
            system("cls");
            cout << "\n\t\t\t\t��������ϻ�ʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// �ǳ�
void CardVector::logout(BillVector &bill) {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            if (p->Status == UNUSE) {
                system("cls");
                cout << "\n\t\t\t\t\t�ÿ�δ�ϻ���\n\n";
                system("pause");
            } else {
                p->Status = UNUSE;
                p->Last = p->End = time(nullptr);
                char StartTime[20], EndTime[20];
                timeToString(p->End, EndTime);
                timeToString(p->Start, StartTime);
                double Price = bill.getPrice();
                double outBalance = (double) (p->End - p->Start) / 60.0 * Price;
                p->Balance -= outBalance;
                updateCard(p, CARDPATH, CardIndex);
                system("cls");
                cout << "\n\t\t\t\t\t�»��ɹ���\n\n";
                cout << "\t\t\t\t���ţ�" << p->CardName << '\n';
                cout << "\t\t\t\t�������ѣ�" << outBalance << '\n';
                cout << "\t\t\t\t��" << setiosflags(ios::fixed) << setprecision(2) << p->Balance << '\n';
                cout << "\t\t\t\t�ϻ�ʱ�䣺" << StartTime << "\n";
                cout << "\t\t\t\t�»�ʱ�䣺" << EndTime << "\n\n";
                Bill billi(p->CardName, p->Start, p->End, -outBalance, COST);
                bill.addBill(billi);
                bill.saveBill(billi, BILLPATH);
                system("pause");
            }
        } else {
            system("cls");
            cout << "\n\t\t\t\t��������»�ʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ��ֵ
void CardVector::recharge(BillVector &bill) {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            system("cls");
            cout << "\n\t\t\t\t���ţ�" << p->CardName << '\n';
            cout << "\t\t\t\t��" << setiosflags(ios::fixed) << setprecision(2) << p->Balance << "\n\n";
            cout << "\t\t\t\t�������ֵ��";
            double inBalance;
            cin >> inBalance;
            p->Balance += inBalance;
            p->Last = time(nullptr);
            updateCard(p, CARDPATH, CardIndex);
            cout << "\n\t\t\t\t\t��ֵ�ɹ���\n";
            cout << "\t\t\t\t���ţ�" << p->CardName << '\n';
            cout << "\t\t\t\t��" << setiosflags(ios::fixed) << setprecision(2) << p->Balance << '\n';
            Bill billi(p->CardName, p->Last, p->Last, inBalance, RECHARGE);
            bill.addBill(billi);
            bill.saveBill(billi, BILLPATH);
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t������󣬳�ֵʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// �˷�
void CardVector::refund(BillVector &bill) {
    string CardName;
    string CardPwd;
    if (inputName(CardName)) {
        int CardIndex = 0;
        Card *p = isExist(CardName, CardIndex);
        if (p == nullptr) {
            system("cls");
            cout << "\n\t\t\t\t\t���Ų����ڣ�\n\n";
            system("pause");
        } else if (inputPwd(CardPwd, 0) && CardPwd == p->CardPwd) {
            system("cls");
            cout << "\n\t\t\t\t���ţ�" << p->CardName << '\n';
            cout << "\t\t\t\t��" << setiosflags(ios::fixed) << setprecision(2) << p->Balance << "\n\n";
            cout << "\t\t\t\t�������˷ѽ�";
            double outBalance;
            cin >> outBalance;
            while (outBalance > p->Balance) {
                cout << "\n\t\t\t\t�˷ѽ�������\n\n";
                char ch = 'M';
                while (ch != 'N' && ch != 'Y') {
                    cout << "\t\t\t\t����������<y/n>:";
                    cin >> ch;
                    ch = (char) toupper(ch);
                }
                if (ch == 'Y') {
                    cout << "\n\t\t\t\t�������˷ѽ�";
                    cin >> outBalance;
                } else {
                    system("cls");
                    cout << "\n\t\t\t\t\t�˷�ʧ�ܣ�\n\n";
                    system("pause");
                    return;
                }
            }
            p->Balance -= outBalance;
            p->Last = time(nullptr);
            updateCard(p, CARDPATH, CardIndex);
            cout << "\n\t\t\t\t\t�˷ѳɹ���\n";
            cout << "\t\t\t\t���ţ�" << p->CardName << '\n';
            cout << "\t\t\t\t��" << setiosflags(ios::fixed) << setprecision(2) << p->Balance << '\n';
            Bill billi(p->CardName, p->Last, p->Last, -outBalance, REFUND);
            bill.addBill(billi);
            bill.saveBill(billi, BILLPATH);
            system("pause");
        } else {
            system("cls");
            cout << "\n\t\t\t\t��������˷�ʧ�ܣ�\n\n";
            system("pause");
        }
    } else {
        system("cls");
        cout << "\n\t\t\t\t����Ŀ��Ÿ�ʽ����ȷ��\n\n";
        system("pause");
    }
}

// ���������ַ���֮��ı༭����
int CardVector::editDistance(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int j = 0; j <= len2; j++) dp[0][j] = j;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
    return dp[len1][len2];
}

// ������ӽ��������ŵĿ�Ƭ
vector<Card> CardVector::getTopMatches(const string &CardName) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareDistance> pq;
    vector<Card> res;
    for (int i = 0; i < vec.size(); i++) {
        int dist = editDistance(CardName, vec[i].CardName);
        pq.push({dist, i});
    }
    for (int i = 0; i < 5 && !pq.empty(); i++) {
        int idx = pq.top().second;
        res.push_back(vec[idx]);
        pq.pop();
    }
    return res;
}

// ���뿨�ţ������Ƿ�Ϸ�
bool CardVector::inputName(string &CardName) {
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

// �������룬�����Ƿ�Ϸ�
bool CardVector::inputPwd(string &CardPwd, int p) {
    while (true) {
        system("cls");
        if (p == 2) cout << "\n\t\t\t������������<����Ϊ1~7>:";
        else cout << "\n\t\t\t����������<����Ϊ1~7>:";
        CardPwd = cinPwd();
        if (CardPwd.size() > 7) {
            system("cls");
            cout << "\n\t\t\t\t���볤�ȳ������ֵ��\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t����������<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        } else if (p) {
            system("cls");
            cout << "\n\t\t\t���ٴ���������<����Ϊ1~7>��";
            string Pwd;
            Pwd = cinPwd();
            if (Pwd != CardPwd) {
                system("cls");
                cout << "\n\t\t\t\t������������벻��ͬ��\n\n";
                char ch = 'M';
                while (ch != 'N' && ch != 'Y') {
                    cout << "\t\t\t\t����������<y/n>:";
                    cin >> ch;
                    ch = (char) toupper(ch);
                }
                if (ch == 'N') return false;
            } else break;
        } else break;
    }
    return true;
}

// �������룬���ǺŴ��棬�������ַ���
string CardVector::cinPwd() {
    char password[20];
    char ch;
    int i = 0;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (i > 0) {
                i--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        } else {
            password[i] = ch;
            i++;
            putchar('*');
        }
    }
    password[i] = '\0';
    return password;
}

// ��ʾ���п�Ƭ��Ϣ
void CardVector::showCard() {
    system("cls");
    cout << "\n\t\t\t����\t\t״̬\t���\t�ϴ�ʹ��ʱ��\n";
    for (auto it: vec) {
        cout << "\t\t\t" << it.CardName << "\t\t";
        if (it.Status == UNUSE) cout << "δ�ϻ�\t";
        else cout << "�ϻ�\t";
        cout << setiosflags(ios::fixed) << setprecision(2) << it.Balance << '\t';
        char LastTime[20] = {0};
        timeToString(it.Last, LastTime);
        cout << LastTime << '\n';
    }
    system("pause");
}

// ��鿨�Ƿ���ڣ�������ڷ���ָ��Ƭ��ָ������±�
Card *CardVector::isExist(string &CardName, int &CardIndex) {
    CardIndex = 0;
    for (auto &it: vec) {
        if (it.CardName == CardName) return &it;
        CardIndex++;
    }
    return nullptr;
}

// ������Ϣ���浽�ļ���
void CardVector::saveCard(const string &cardPATH) {
    ofstream cardfile(cardPATH, ios::out | ios::binary);
    if (!cardfile.is_open()) return;
    for (auto it: vec) cardfile.write((char *) &it, sizeof(Card));
    cardfile.close();
}

// ����ָ���±�Ŀ���Ϣ
void CardVector::updateCard(const Card *p, const string &cardPATH, int CardIndex) {
    fstream cardfile(cardPATH, ios::in | ios::out);
    if (!cardfile.is_open()) return;
    cardfile.seekp(sizeof(Card) * CardIndex, ios::beg);
    cardfile.write((char *) p, sizeof(Card));
    cardfile.close();
}
