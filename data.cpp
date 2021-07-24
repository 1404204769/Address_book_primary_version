#include "data.h"
#include<ctime>
#include<iostream>
void showRandomName() {
	srand((unsigned)time(NULL));
	int a = rand()%4;
	int b = rand()%3;
	char name[20] = "";
	strcat(name, NameHead[a]);
	strcat(name, NameLast[b]);
	std::cout << name << std::endl;
}