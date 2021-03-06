﻿/*
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

	void refAdd::set(int n) {
		this->data = n;
	}

	void refAdd::Add(const refAdd& a, const refAdd& b) {
		int sum = a.data + b.data;
		this->data = sum;
	}

	refAdd operator+(const refAdd& a, const refAdd& b) {
		int sum = a.data + b.data;
		return refAdd(sum);
	}

	void refAdd::show() {
		cout << "refAdd data的计算的值爲：" << this->data << endl;
	}

	void refAdd::showMain() {
		cout << "----------------refAdd Main Call-------------------" << endl;
		refAdd a;
		refAdd b;
		cout << "请输入第一个int型数据" << endl;
		cin >> a.data;
		cout << "请输入第二个int型数据" << endl;
		cin >> b.data;
		this->Add(a, b);
		this->show();
		refAdd c = a + b;
		c.show();
		cout << c.getValue() << endl;
	}

} /* namespace totcp */
