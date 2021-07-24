#include<iostream>
#include "data.h"
#include "Cuser.h"
using namespace std;
int test() {
	//char str[10] = "李四";
	//char arr[10] = "";
	//cin >> arr;
	//cout << str << " ： " << arr << endl;
	clock_t start, finish; //声明start和finish是两个时间
	double time; //定义运行时间
	start = clock(); //获取开始时间
	cout << "随机生成100人的数据" << endl;
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
	printf("RunningTime:\n%f 秒\n", time);//显示
	return 0;
}