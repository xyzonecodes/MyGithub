/*
 * Animal.h
 *
 *  Created on: 2014年11月1日
 *      Author: xyzone
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include "../baseCls.h"

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
};
}
#endif /* ANIMAL_H_ */
