/*
 * Animal.h
 *
 *  Created on: 2014年11月1日
 *      Author: xyzone
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

class Animal {
protected:
	const char* name;
	int age;
public:
	Animal(const char * name, int age) :
		name(name), age(age)
	{

	}
	void eat();
	void getName();
};

#endif /* ANIMAL_H_ */
