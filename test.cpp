#include<iostream>
#include "data.h"
#include "Cuser.h"
using namespace std;
int test() {
	//char str[10] = "����";
	//char arr[10] = "";
	//cin >> arr;
	//cout << str << " �� " << arr << endl;
	clock_t start, finish; //����start��finish������ʱ��
	double time; //��������ʱ��
	start = clock(); //��ȡ��ʼʱ��
	cout << "�������100�˵�����" << endl;
	Cuser temUser;
	for (int i = 0; i < 100; i++) {
		showRandomName(temUser);
		showRandomTel(temUser);
		showRandomAddress(temUser);
		cout <<i<< ".\tname:" << temUser.getName() << "\tTel:" << temUser.getTel() << "\tAddress:" << temUser.getAddress() << endl;
	}
	finish = clock();
	printf("\n");
	//time = (double)(finish - start);
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("RunningTime:\n%f ��\n", time);//��ʾ
	return 0;
}