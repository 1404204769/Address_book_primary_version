#pragma once
#ifndef _DATA_H_
#define _DATA_H_
#include <windows.h>

//499个   0-498，百家姓
const char NameHead[500][10] = { "赵","钱","孙","李"};
//322个，常见名字
const char NameLast[323][10] = { "骄奢","荫庇","芳馨" };
//52个，大小写字母
const char Name3[53][4] = { "A","B","C","D","E"};
void showRandomName();
#endif //!_DATA_H_