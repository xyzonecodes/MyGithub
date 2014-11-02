#include <iostream>
#include "Animal.h"
#include "TemplateCls.cpp"

using namespace std;

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
	cin.get();
}
