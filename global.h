#ifndef BILLING_MANAGER_GLOBAL_H
#define BILLING_MANAGER_GLOBAL_H


#include <bits/stdc++.h>
using namespace std;

// ���峣������ʾ�����ı��ļ���·��
const string CARDPATH = "d:/Projects/Billing_Manager/data/card.txt";   // �洢����Ϣ�ļ�
const string BILLPATH = "d:/Projects/Billing_Manager/data/bill.txt";   // �洢�˵���Ϣ�ļ�
const string PRICEPATH = "d:/Projects/Billing_Manager/data/price.txt"; // �洢�۸���Ϣ�ļ�

// ���峣������ʾ��Ƭ״̬��ö��ֵ
const int UNUSE = 0; // δ�ϻ�
const int USING = 1; // �����ϻ�

// ���峣������ʾ�˵����͵�ö��ֵ
const int COST = 1;     // ���Ѳ���
const int RECHARGE = 2; // ��ֵ����
const int REFUND = 3;   // �˷Ѳ���

// ���峣������ʾ��������Ա���˺ź�����
const string ROOTID = "100001";  // ����Ա�˺�
const string ROOTPWD = "100001"; //����Ա����


#endif //BILLING_MANAGER_GLOBAL_H
