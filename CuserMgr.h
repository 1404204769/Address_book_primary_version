#pragma once
#ifndef _CUSERMGR_H_
#define _CUSERMGR_H_
#include<vector>
using namespace std;
class Cuser {
	char pszName[20];//��������
	char pszTel[20];//�����ֻ���
	char pszAddress[50];//�����ַ
public:
	Cuser();
	Cuser(const char* TemPszName, const char* TemPszTel, const char* TemPszAdress);//��������
	~Cuser();
	char* getName() { return pszName; }
	char* getTel() { return pszTel; }
	char* getAddress() { return pszAddress; }
	void setName(const char* _input) { strcpy(pszName, _input); }
	void setTel(const char* _input) { strcpy(pszTel, _input); }
	void setAddress(const char* _input) { strcpy(pszAddress, _input); }
};
class CuserMgr {
	const char* const filename = "UserDatabase.txt";//���ڱ������ݵ��ļ��������Ը���
	vector<Cuser>VecByTel;//ʹ���ֻ�����Ϊ��������Ϊ���ֿ���һ�������ֻ��Ų�����һ��
public://�ڲ����߼�����
	CuserMgr(); 
	~CuserMgr();
	bool checkTel(const char* _inputTel);//���ڼ���ֻ����Ƿ�淶�������ж��Ƿ�����ظ��ֻ���
	Cuser GetUser();//���������������
	bool AddUser(Cuser _input);//���ڽ�������ӵ�VecByTel������
	bool saveInfoToFile();//�ļ�д����
	bool readInfoFromFile();//�ļ�������
	void showName();//��ӡ������е��ִ������
	void showDetailByName(const char* _searchName);//�����û������ֲ�ѯ��Ӧ����Ϣ
};
#endif // !_CUSERMGR_H_

