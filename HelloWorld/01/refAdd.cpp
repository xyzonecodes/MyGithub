/*
 * refAdd.cpp
 *
 *  Created on: 2014年11月3日
 *      Author: xyzone
 */

#include "refAdd.h"
#include <iostream>

using namespace std;

namespace totcp {

refAdd::refAdd() {
	// TODO Auto-generated constructor stub

}

refAdd::~refAdd() {
	// TODO Auto-generated destructor stub
}

refAdd::refAdd(int n) :
		data(n) {
}

void refAdd::Add(const refAdd& a, const refAdd& b) {
	int sum = a.data + b.data;
	this->data = sum;
}

void refAdd::show() {
	cout << "refAdd data的值爲：" << this->data << endl;
}

void refAdd::showMain() {
	cout << "----------------refAdd Main Call-------------------" << endl;
	refAdd a(200);
	refAdd b(300);
	refAdd c;
	c.Add(a, b);
	c.show();
}

} /* namespace totcp */
