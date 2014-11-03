#include <iostream>
#include "02/Animal.h"
#include "TemplateCls.cpp"
#include "01/refAdd.h"
#include <string.h>
#include "03/LinkList.h"

using namespace std;
using namespace totcp;

void showMain();

int main() {
	/*
	cout << "UTF-8 都不行啊" << endl;
	TemplateCls<int> tc;
	int a = 3, b = 4;
	tc.swap(a, b);
	cout << "a:" << a << "   b:" << b << endl;

	int static_i = 65;
	char char_p = static_cast<char>(static_i);
	cout << char_p << endl;*/
	char ch = 0;
	while (ch!='q')
	{
		showMain();
		cout << "按回车继续，按q退出:";
		cin.get();//回车
		cin.get(ch);
		cout << ch;
	}
	

}

void showMain() {
	char input[20] = { 0 };
	baseCls *pBase = NULL;
	cout << "请输入要执行文件的目录名称：" << endl;
	cin >> input;
	if (strcmp(input, "01") == 0)
		pBase = new refAdd();
	else if (strcmp(input, "02") == 0)
		pBase = new Animal(); 
	else if (strcmp(input, "03") == 0)
		pBase = new LinkList();
	else
		pBase = new baseCls();
	pBase->showMain();
	delete pBase;
}

