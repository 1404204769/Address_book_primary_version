#define _CRT_SECURE_NO_WARNINGS
#include "CuserMgr.h"
#include <iostream>
Cuser::Cuser() {
	memset(pszName, 0, sizeof(pszName));
	memset(pszTel, 0, sizeof(pszTel));
	memset(pszAddress, 0, sizeof(pszAddress));
}
Cuser::Cuser(const char* TemPszName, const char* TemPszTel, const char* TemPszAdress) {
	strcpy(pszName, TemPszName);
	strcpy(pszTel, TemPszTel);
	strcpy(pszAddress, TemPszAdress);
}
Cuser::~Cuser() {}
CuserMgr::CuserMgr() {
	VecByTel.clear();
	readInfoFromFile();
}
bool CuserMgr::checkTel(char* _inputTel) {
	//���ڼ���ֻ����Ƿ�淶�������ж��Ƿ�����ظ��ֻ���
	size_t nLen = strlen(_inputTel);
	if (nLen != 11) {
		cout << "�ֻ���λ������ȷ������������" << endl;
		return false;
	}
	else {
		for (char* c = _inputTel; *c != 0; c++) {
			if (*c <= '9' && *c >= '0')continue;
			else {
				cout << "�ֻ����ڴ��ڷ����֣�����������" << endl;
				return false;
			}
		}
	}
	return true;

}
Cuser CuserMgr::GetUser() {
	//���������������
	Cuser TemUser = Cuser();
	return TemUser;
}
bool CuserMgr::AddUser(Cuser _input) {
	//���ڽ�������ӵ�VecByTel������
	VecByTel.push_back(_input);
	return true;
}
bool CuserMgr::saveInfoToFile() {
	//�ļ�д����
	FILE* fp = fopen(filename, "w");
	for (vector<Cuser>::iterator it = VecByTel.begin(); it != VecByTel.end(); ++it) {
		fprintf(fp, "%s\t%s\t%s\n", it->getName(), it->getTel(), it->getAddress());
	}
	fclose(fp);
	return true;
}
bool CuserMgr::readInfoFromFile() {
	//�ļ�������
	char* TemPszAddress = new char[50];//������ʱ�����ݴ洢λ
	char* TemPszName = new char[20];
	char* TemPszTel = new char[20];
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		fp = fopen(filename, "w+");
	}
	while (fscanf(fp, "%s\t%s\t%s\n", TemPszName, TemPszTel, TemPszAddress) != EOF) {
		Cuser TemUser(TemPszName, TemPszTel, TemPszAddress);
		AddUser(TemUser);
		memset(TemPszName, 0, sizeof(TemPszName));
		memset(TemPszTel, 0, sizeof(TemPszTel));
		memset(TemPszAddress, 0, sizeof(TemPszAddress));
	}
	fclose(fp);
	delete[]TemPszAddress;//��ʱ�����ͷ��ڴ�
	delete[]TemPszName;
	delete[]TemPszTel;
	return true;
}
void CuserMgr::showName() {
	if (VecByTel.empty()) {
		cout << "��ǰ������" << endl;
		return;
	}
	cout << "ͨѶ¼��������" << endl;
	//��ӡ������е��ִ������
	for (vector<Cuser>::iterator it = VecByTel.begin(); it != VecByTel.end(); ++it) {
		cout << it->getName() << "\t" << endl;
	}
	cout << "����������" << endl;
}
void CuserMgr::showDetailByName(const char* _searchName) {
	//�����û������ֲ�ѯ��Ӧ����Ϣ
	bool _findByName = false;
	for (vector<Cuser>::iterator it = VecByTel.begin(); it != VecByTel.end(); ++it) {
		if (strcmp(it->getName(), _searchName) == 0) {
			cout << "name:" << it->getName() << endl;
			cout << "Tel:" << it->getTel() << endl;
			cout << "Address:" << it->getAddress() << endl;
		}
	}
	if (_findByName) {
		cout << "����������" << endl;
	}
	else {
		cout << "δ�ҵ����˵���Ϣ" << endl;
	}
}