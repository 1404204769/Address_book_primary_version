#include<iostream>
#include "data.h"
#include "Cuser.h"
#include "CuserMgr.h"
using namespace std;
int main2() {
	CuserMgr cusermgr;
	Cuser temUser;
	clock_t start, finish; //����start��finish������ʱ��
	double time; //��������ʱ��
	start = clock(); //��ȡ��ʼʱ��
	cout << "�������100000�˵�����" << endl;
	for (int i = 0; i < 10; i++) {
		temUser = cusermgr.GetUser();
		cout << i << ".\tname:" << temUser.getName() << "\tTel:" << temUser.getTel() << "\tAddress:" << temUser.getAddress() << endl;
		cusermgr.AddUser(temUser);
	}
	cusermgr.showName();
	cusermgr.~CuserMgr();
	CuserMgr cusermgr2;
	cusermgr2.showName();
	finish = clock();
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("RunningTime:\n%f ��\n", time);//��ʾ
	return 0;
}