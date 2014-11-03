/*
 * Animal.h
 *
 *  Created on: 2014年11月1日
 *      Author: xyzone
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "../baseCls.h"
#include <iostream>

using namespace std;

namespace totcp {
class Animal: public baseCls {
	const char* name;
	int age;
public:
	Animal();
	Animal(const char * name, int age) :
			name(name), age(age) {
	}
	void eat();
	void getName();
	void showMain();
	friend ostream& operator<<(ostream& os,  Animal& an) {
		os << "姓名" << an.name << "       年齡：" << an.age << "      父 Value ："<<an.getValue();
		return os;
	}
};
}
#endif /* ANIMAL_H_ */
