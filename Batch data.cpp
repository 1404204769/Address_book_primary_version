#include<iostream>
#include "data.h"
#include "Cuser.h"
#include "CuserMgr.h"
using namespace std;
int main2() {
	CuserMgr cusermgr;
	Cuser temUser;
	clock_t start, finish; //声明start和finish是两个时间
	double time; //定义运行时间
	start = clock(); //获取开始时间
	cout << "随机生成100000人的数据" << endl;
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
	printf("RunningTime:\n%f 秒\n", time);//显示
	return 0;
}