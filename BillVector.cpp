#include "BillVector.h"
#include "global.h"
#include "tool.h"

// 构造函数，用于初始化 BillVector 类的属性
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

// 获取 Price 属性值
double BillVector::getPrice() const { return Price; }

// 检查 Price 属性值
void BillVector::checkPrice() const {
    system("cls");
    cout << "\n\t\t\t\t当前价格为：" << setprecision(2) << Price << "/分钟\n\n";
    system("pause");
}

// 重置 Price 属性值
void BillVector::resetPrice() {
    double NewPrice;
    system("cls");
    cout << "\n\t\t\t\t当前价格为：" << setprecision(2) << Price << "/分钟\n\n";
    cout << "\t\t\t\t请输入新的价格</分钟>：";
    cin >> NewPrice;
    Price = NewPrice;
    savePrice(PRICEPATH);
    system("cls");
    cout << "\n\t\t\t    价格调整成功，当前价格为：" << setprecision(2) << Price << "/分钟\n\n";
    system("pause");
}

// 添加 Bill 对象
void BillVector::addBill(Bill billi) {
    vec.push_back(billi);
}

// 静态方法，用于输入卡片名称
bool BillVector::inputName(string &CardName) {
    while (true) {
        system("cls");
        cout << "\n\t\t\t请输入卡号<长度为1~17>：";
        cin >> CardName;
        if (CardName.size() > 17) {
            system("cls");
            cout << "\n\t\t\t\t卡号长度超过最大值！\n\n";
            char ch = 'M';
            while (ch != 'N' && ch != 'Y') {
                cout << "\t\t\t\t重新输入吗？<y/n>:";
                cin >> ch;
                ch = (char) toupper(ch);
            }
            if (ch == 'N') return false;
        } else break;
    }
    return true;
}

// 查询账单
void BillVector::queryBill() {
    system("cls");
    string CardName;
    if (inputName(CardName)) {
        cout << "\n\t\t卡号\t\t上机时间\t\t下机时间\t\t金额\t\t类型\n";
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
                if (it.Type == COST) cout << "消费\n";
                else if (it.Type == RECHARGE) cout << "充值\n";
                else if (it.Type == REFUND) cout << "退费\n";
            }
        }
        system("pause");
    } else {
        system("cls");
        cout << "\n\t\t\t\t输入的卡号格式不正确！\n\n";
        system("pause");
    }
}

// 显示账单
void BillVector::showBill() {
    system("cls");
    double totBalance = 0;
    cout << "\n\t\t卡号\t\t上机时间\t\t下机时间\t\t金额\t\t类型\n";
    for (auto it: vec) {
        cout << "\t\t" << it.CardName << "\t\t";
        char StartTime[20] = {0};
        timeToString(it.Start, StartTime);
        cout << StartTime << '\t';
        char EndTime[20] = {0};
        timeToString(it.End, EndTime);
        cout << EndTime << '\t';
        cout << setiosflags(ios::fixed) << setprecision(2) << it.Balance << "\t\t";
        if (it.Type == COST) cout << "消费\n";
        else if (it.Type == RECHARGE) cout << "充值\n", totBalance += it.Balance;
        else if (it.Type == REFUND) cout << "退费\n", totBalance += it.Balance;
    }
    cout << "\n\t\t\t\t总营业额：" << totBalance << "\n\n";
    system("pause");
}

// 保存 Price 属性值
void BillVector::savePrice(const string &pricePATH) {
    ofstream pricefile(pricePATH, ios::out | ios::binary);
    if (!pricefile.is_open()) return;
    pricefile.write((char *) &Price, sizeof(double));
    pricefile.close();
}

// 静态方法，用于保存 Bill 对象到文件
void BillVector::saveBill(Bill bill, const std::string &billPATH) {
    ofstream billfile(billPATH, ios::app | ios::binary);
    if (!billfile.is_open()) return;
    billfile.write((char *) &bill, sizeof(Bill));
    billfile.close();
}