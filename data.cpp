#include "data.h"
#include "Cuser.h"
#include<ctime>
#include<iostream>

//�޸��������
void SetSrand(){
	static ULONG timeindex = 0;
	srand((int)time(0) + timeindex);
	timeindex += 0x3;
	if (timeindex > 0xfffffff)
	{
		timeindex = 0;
	}
}
//��ȡ�����
int GetRand(int rval){
	return (int)(rand() % rval);
}
void showRandomName(const Cuser& _input) {
	SetSrand();
	int cnt = 0; 
	char name[20] = "";
	//srand((unsigned)time(NULL));
	//60%���� ����������
	if (GetRand(100) <= 60) {
		//printf("�ټ���+�������:");
		//��
		cnt = GetRand(50);
		strcat_s(name, LastName[cnt]);
		//��
		cnt = GetRand(50);
		strcat_s(name, ManName[cnt]);
	}
	else {
		//40%���� ��Ů������
		//printf("�ټ���+���Ů��:");
		//��
		cnt = GetRand(50);
		strcat_s(name, LastName[cnt]);
		//��
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
	//printf("����绰ͷ:");
	cnt = GetRand(40);
	strcat_s(Tel, TelHead[cnt]);
	//��
	cnt = GetRand(9999999)+10000000;//��֤һ���а�λ��
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
	//printf("���ʡ����:");
	//ʡ
	cnt = GetRand(34);
	strcat_s(Address, Provincial_Name[cnt]);
	//��
	cnt = GetRand(26);
	strcat_s(Address, District_Name[cnt]);
	//std::cout << Address << std::endl;
	Cuser* This = (Cuser*)&_input;
	This->setAddress(Address);
}