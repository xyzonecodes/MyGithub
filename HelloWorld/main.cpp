#include <iostream>
#include "Animal.h"
#include "TemplateCls.cpp"
#include "01/refAdd.h"
#include <string.h>

using namespace std;
using namespace totcp;

void showMain();

int main() {
	cout << "Hello World!" << endl;
	Animal an("鸟", 3);
	an.eat();
	an.getName();
	cout << "UTF-8 都不行啊" << endl;
	TemplateCls<int> tc;
	int a = 3, b = 4;
	tc.swap(a, b);
	cout << "a:" << a << "   b:" << b << endl;

	int static_i = 65;
	char char_p = static_cast<char>(static_i);
	cout << char_p << endl;
	showMain();
	cin.get();
}

void showMain() {
	string input;
	baseCls *pBase = NULL;
	cout << "请输入要执行文件的目录名称：" << endl;
	cin >> input;
	if (input == "01") {
		pBase = new refAdd();
	} else {
		pBase = new baseCls();
	}
	pBase->showMain();
	delete pBase;
}

