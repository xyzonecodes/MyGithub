#include <iostream>
#include "Animal.h"

using namespace std;

int main() {
	cout << "Hello World!" << endl;
	Animal an("鸟", 3);
	an.eat();
	an.getName();
	cin.get();
}
