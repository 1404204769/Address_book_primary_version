#pragma once
#ifndef _CUSERMGR_H_
#define _CUSERMGR_H_
#include<vector>
#include "Cuser.h"
using namespace std;
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

