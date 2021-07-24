#include "data.h"
#include "Cuser.h"
#include<ctime>
#include<iostream>

//修改随机步长
void SetSrand(){
	static ULONG timeindex = 0;
	srand((int)time(0) + timeindex);
	timeindex += 0x3;
	if (timeindex > 0xfffffff)
	{
		timeindex = 0;
	}
}
//获取随机数
int GetRand(int rval){
	return (int)(rand() % rval);
}
void showRandomName(const Cuser& _input) {
	SetSrand();
	int cnt = 0; 
	char name[20] = "";
	//srand((unsigned)time(NULL));
	//60%概率 是男性名字
	if (GetRand(100) <= 60) {
		//printf("百家姓+随机男名:");
		//姓
		cnt = GetRand(50);
		strcat_s(name, LastName[cnt]);
		//名
		cnt = GetRand(50);
		strcat_s(name, ManName[cnt]);
	}
	else {
		//40%概率 是女性名字
		//printf("百家姓+随机女名:");
		//姓
		cnt = GetRand(50);
		strcat_s(name, LastName[cnt]);
		//名
		cnt = GetRand(50);
		strcat_s(name, WomanName[cnt]);
	}
	//std::cout << name << std::endl;
	Cuser* This = (Cuser*)&_input;
	This->setName(name);
}
void showRandomTel(const Cuser& _input){
	SetSrand();
	int cnt = 0;
	char Tel[20] = "";
	char TelLast[10] = "";
	//srand((unsigned)time(NULL));
	//printf("随机电话头:");
	cnt = GetRand(40);
	strcat_s(Tel, TelHead[cnt]);
	//区
	cnt = GetRand(9999999)+10000000;//保证一定有八位数
	sprintf_s(TelLast, "%d", cnt);
	strcat_s(Tel, TelLast);
	//std::cout << Tel << std::endl;
	Cuser* This = (Cuser*)&_input;
	This->setTel(Tel);
}
void showRandomAddress(const Cuser& _input) {
	SetSrand();
	int cnt = 0;
	char Address[50] = "";
	//srand((unsigned)time(NULL));
	//printf("随机省份名:");
	//省
	cnt = GetRand(34);
	strcat_s(Address, Provincial_Name[cnt]);
	//区
	cnt = GetRand(26);
	strcat_s(Address, District_Name[cnt]);
	//std::cout << Address << std::endl;
	Cuser* This = (Cuser*)&_input;
	This->setAddress(Address);
}