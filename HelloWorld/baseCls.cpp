/*
 * baseCls.cpp
 *
 *  Created on: 2014年11月3日
 *      Author: xyzone
 */
#include <iostream>
#include "baseCls.h"
using namespace std;
namespace totcp {

baseCls::baseCls() {
	// TODO Auto-generated constructor stub

}

baseCls::~baseCls() {
	// TODO Auto-generated destructor stub
}

void baseCls::showMain() {
	cout << "base showMain Call!!!" << endl;
}

void baseCls::setVale(int n) {
	this->baseInt = n;
}

int baseCls::getValue(){
	return this->baseInt;
}
}
/* namespace totcp */
