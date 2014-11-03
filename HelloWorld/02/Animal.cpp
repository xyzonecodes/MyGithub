/*
 * Animal.cpp
 *
 *  Created on: 2014年11月1日
 *      Author: xyzone
 */

#include "Animal.h"
#include <iostream>

using namespace std;

namespace totcp {
void Animal::eat() {
	cout << this->name << " 吃！" << endl;
}

Animal::Animal() {

}

void Animal::getName() {
	cout << name << endl;
}

void Animal::showMain() {
	this->name = " 烏鴉";
	this->age = 10;
	this->setVale(100);
	this->eat();
	Animal an;
	an.age = this->age;
	an.name = this->name;
	an.setVale(this->getValue());
	cout << an << endl;
}
}
