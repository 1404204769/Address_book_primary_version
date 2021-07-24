#include "Cuser.h"
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
Cuser::Cuser() {
	memset(pszName, 0, sizeof(pszName));
	memset(pszTel, 0, sizeof(pszTel));
	memset(pszAddress, 0, sizeof(pszAddress));
}
Cuser::Cuser(const char* TemPszName, const char* TemPszTel, const char* TemPszAdress) {
	strcpy_s(pszName, TemPszName);
	strcpy_s(pszTel, TemPszTel);
	strcpy_s(pszAddress, TemPszAdress);
}
Cuser::~Cuser() {}